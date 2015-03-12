SRC_PATH:=./src/
SRC_NAME:=	ft_wolf.c\
		ft_init.c\
		ft_keyhook.c\
   		ft_map.c\
		ft_mousehook.c
INC_PATH=./includes/
INC_NAME=	libft.h\
		get_next_line.h\
		ft_printf.h\
		ft_SDL.h\
		ft_wolf.h
OBJ_PATH =./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))
LIBSDL=-I ./SDL2.framework/Headers
LIBFT:=-L ftlibsdl/libft -lftprintf
LIBFTSDL:=-L ftlibsdl -lftsdl
CFLAGS=-Wall -Wextra -Werror
CC=gcc
NAME=Wolf3D
RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m
DATE:=`date`

all: $(NAME)

$(NAME):$(OBJ)
	@make -s -C ftlibsdl/libft
	@make -s -C ftlibsdl
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@gcc $(OBJ) $(CLFAGS) $(INC) $(LIBFT) $(LIBFTSDL) $(LIBSDL) ./SDL2.framework/SDL2 -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) $(LIBSDL) -o $@ -c $<

clean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C ftlibsdl/libft
	@make fclean -C ftlibsdl
	@echo "${CYAN}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

push: fclean
	@echo "${CYAN}Clean and push all on git${NC}"
	@make fclean -C ftlibsdl/libft
	@make fclean -C ftlibsdl
	@find . -type f -name "*.sw[op]" -exec rm {} \;}
	@git add --all *
	@git commit -m "$(DATE)"
	@git push -q

re: fclean all clean

.PHONY: all clean fclean re
