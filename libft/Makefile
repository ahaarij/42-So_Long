# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 10:51:34 by ahaarij           #+#    #+#              #
#    Updated: 2024/01/21 10:25:03 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories

SRCS_PATH 		= ./srcs
CHECK_PATH 		= $(SRCS_PATH)/check/
GNL_PATH		= $(SRCS_PATH)/gnl/
LIST_PATH 		= $(SRCS_PATH)/list/
MEMORY_PATH 	= $(SRCS_PATH)/mem/
PRINTF_PATH		= $(SRCS_PATH)/printf/
STRING_PATH		= $(SRCS_PATH)/string/

HEAD			=  ./includes/
NAME = libft.a

SRCS_CHECK		= ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_isspace.c
SRCS_GNL		= get_next_line.c \
					get_next_line_utils.c
SRCS_LIST		= ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstlast.c \
					ft_lstdelone.c \
					ft_lstnew.c \
					ft_lstsize.c
SRCS_MEMORY		= ft_bzero.c \
					ft_calloc.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c
SRCS_PRINTF		= ft_printf.c \
					ft_printchar.c \
					ft_printhex.c \
					ft_printnbr.c \
					ft_printptr.c \
					ft_printstr.c \
					ft_printuint.c
SRCS_STRING		= ft_atoi.c \
					ft_itoa.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlen.c \
					ft_strncmp.c \
					ft_substr.c \
					ft_strrchr.c \
					ft_strnstr.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strtrim.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \

SRC_CHECK		= $(addprefix $(CHECK_PATH),$(SRCS_CHECK))
SRC_GNL			= $(addprefix $(GNL_PATH),$(SRCS_GNL))
SRC_LIST		= $(addprefix $(LIST_PATH),$(SRCS_LIST))
SRC_MEMORY		= $(addprefix $(MEMORY_PATH),$(SRCS_MEMORY))
SRC_PRINTF		= $(addprefix $(PRINTF_PATH),$(SRCS_PRINTF))
SRC_STRING		= $(addprefix $(STRING_PATH),$(SRCS_STRING))

OBJS_CHECK		= $(SRC_CHECK:.c=.o)
OBJS_GNL		= $(SRC_GNL:.c=.o)
OBJS_LIST		= $(SRC_LIST:.c=.o)
OBJS_MEMORY		= $(SRC_MEMORY:.c=.o)
OBJS_PRINTF		= $(SRC_PRINTF:.c=.o)
OBJS_STRING		= $(SRC_STRING:.c=.o)

HEAD			= ./includes/

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

AR = ar -rcs

LIB = ranlib

all: $(NAME)

$(OBJS_CHECK): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(OBJS_GNL): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(OBJS_LIST): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(OBJS_MEMORY): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(OBJS_PRINTF): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(OBJS_STRING): %.o: %.c
				$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME): $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINTF) $(OBJS_STRING)
		$(AR) $(NAME) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINTF) $(OBJS_STRING)
		$(LIB) $(NAME)

clean: 
	$(RM) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINTF) $(OBJS_STRING)

fclean: clean
	$(RM) $(NAME)

re: fclean all
