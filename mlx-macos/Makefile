#
#

RESET		= \033[0m
RED			= $'\x1b[31m
GREEN		= \033[32m
YELLOW		= \033[33m

define HEADER
 _____                               _____ 
( ___ )-----------------------------( ___ )
 |   |                               |   | 
 |   | .___  ___.  __      ___   ___ |   | 
 |   | |   \/   | |  |     \  \ /  / |   | 
 |   | |  \  /  | |  |      \  V  /  |   | 
 |   | |  |\/|  | |  |       >   <   |   | 
 |   | |  |  |  | |  `----. /  .  \  |   | 
 |   | |__|  |__| |_______|/__/ \__\ |   | 
 |___|                               |___| 
(_____)-----------------------------(_____)
endef
export HEADER

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

%.o: %.c
	@cc -c -w $(CFLAGS) $?
%.o: %.m
	@cc -c -w $(CFLAGS) $?
all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r -c $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo ""
	@echo "$(GREEN)$$HEADER"
	@echo "$(YELLOW)Created: $(words $(OBJ)) object file(s) for MLX"
	@echo "$(YELLOW)Created: $(NOM)$(RESET)"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo ""
	@echo "$(RED)$$HEADER"
	@echo "$(YELLOW)Removed: $(words $(OBJ)) object file(s) from MLX"
	@echo "$(YELLOW)Removed: $(NOM)$(RESET)"

re: clean all
