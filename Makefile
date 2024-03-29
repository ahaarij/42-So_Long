SRCS_DIR	= 	./sources

SRCS_FILES	=	main.c \
				checkfile.c \
				ft_getmap.c \
				ft_checkmap.c \
				ft_checkmaputils.c \
				putimage.c \
				move.c	\
				text.c	\
				exit.c	\
				spriteanimate_utils.c \
				spriteanimate.c \
				ft_strjoinfree.c \
				scanplayer.c \

SRCS		= $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

HEAD		= ./includes

# **************************************************************************** #
# LIBRARIES   								                               	   #
# **************************************************************************** #

LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_DIR = ./mlx-macos
MLX_PATH = $(MLX_DIR)/libmlx.a

# **************************************************************************** #
# VARIABLES                                									   #
# **************************************************************************** #

NAME		= so_long
RM			= rm -f
GCC			= gcc
CFLAGS 		= -Wall -Wextra -Werror

HEADER_FILE	= $(HEAD)/so_long.h

RESET		= $'\x1b[0m
BOLD		= $'\x1b[1m
UNDER		= $'\x1b[4m
REV			= $'\x1b[7m
GREY		= $'\x1b[30m
RED			= $'\x1b[31m
GREEN		= $'\x1b[32m
YELLOW		= $'\x1b[33m
BLUE		= $'\x1b[34m
PURPLE		= $'\x1b[35m
CYAN		= $'\x1b[36m
WHITE		= $'\x1b[37m

define HEADER
 _____                                                 _____ 
( ___ )-----------------------------------------------( ___ )
 |   |                                                 |   | 
 |   |      _______. __       __  .___  ___.  _______  |   | 
 |   |     /       ||  |     |  | |   \/   | |   ____| |   | 
 |   |    |   (----`|  |     |  | |  \  /  | |  |__    |   | 
 |   |     \   \    |  |     |  | |  |\/|  | |   __|   |   | 
 |   | .----)   |   |  `----.|  | |  |  |  | |  |____  |   | 
 |   | |_______/    |_______||__| |__|  |__| |_______| |   | 
 |___|                                                 |___| 
(_____)-----------------------------------------------(_____)
endef
export HEADER

# **************************************************************************** #
# TARGETS                                  									   #
# **************************************************************************** #

all: libft_make mlx_make $(NAME)

$(OBJS): %.o: %.c
	@if ! $(GCC) $(CFLAGS) -c -I $(HEAD) $< -o $@ 2> error.txt; then \
		echo "$(RED)$(BOLD)MAKEFILE TERMINATED!$(RESET)"; \
		echo "$(YELLOW)Unable to create the object file for $<$(RESET)"; \
		echo "\n\n$(RED)$(BOLD)ERROR$(RESET)"; \
		sed '$$d' error.txt; \
		echo "\n\n$(YELLOW)EXITING$(RESET)"; \
		exit 1; \
	fi

$(NAME) : $(OBJS) $(LIBFT_PATH) $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME) 
	@echo ""
	@echo "${GREEN}$$HEADER"
	@echo "$(YELLOW)Created: $(words $(OBJS)) object file(s) for so_long"
	@echo "$(YELLOW)Created: $(NAME)$(RESET)"

clean :
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJS) error.txt
	@echo ""
	@echo "${RED}$$HEADER"
	@echo "$(YELLOW)Removed: $(words $(OBJS)) object file(s) from so_long"

fclean : clean
	@$(RM) $(NAME)
	@echo "${YELLOW}Removed: $(NAME)$(RESET)"

re : fclean all

libft_make :
	@make -C $(LIBFT_DIR)

mlx_make :
	@make -C $(MLX_DIR)

.PHONY: all clean fclean re libft_make mlx_make