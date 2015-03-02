SRC_PATH:=./src/
SRC_NAME:=main.c
INC_PATH=./includes/
INC_NAME=libft.h\
	 get_next_line.h\
	 ft_printf.h\
	 wolf.h
OBJ_PATH =./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))
LIBSDL=-lSDL2main -lSDL2
LIBFT:=-L libft -lftprintf
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
	@make -s -C libft
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@gcc $(OBJ) $(CLFAGS) $(pkg-config --cflags --libs sdl2) $(INC) $(LIBFT) $(LIBSDL) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $@ with $<${NC}";
	@$(CC) -c $< $(CFLAGS) $(INC) $(pkg-config --cflags --libs sdl2) $(LIBSDL) -o $@ 

clean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${CYAN}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

push: fclean
	@echo "${CYAN}Clean and push all on git${NC}"
	@make fclean -s -C libft
	@git add --all
	@git commit -m "$(DATE)"
	@git push -q

re: fclean all clean

.PHONY: all clean fclean re
