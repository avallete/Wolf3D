# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 11:43:55 by avallete          #+#    #+#              #
#    Updated: 2015/02/17 09:27:32 by avallete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH=./src/
SRC_NAME=ft_argument.c\
ft_atoi.c\
ft_bzero.c\
ft_tabstrcmp.c\
ft_splitprint.c\
ft_splitlen.c\
ft_calloc.c\
ft_splitdel.c\
ft_resizesplit.c\
ft_splititer.c\
ft_secfree.c\
ft_putsterr.c\
ft_puterrdl.c\
ft_check.c\
ft_converter_char.c\
ft_converter_int.c\
ft_converter_longi.c\
ft_converter_mod.c\
ft_converter_o.c\
ft_converter_p.c\
ft_converter_str.c\
ft_converter_unsigned.c\
ft_converter_us.c\
ft_converter_wchar.c\
ft_converter_x.c\
ft_filler.c\
ft_fillint.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_linttooct.c\
ft_longnbrlen.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstpushback.c\
ft_lstsize.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_misc.c\
ft_nbrlen.c\
ft_nodeaddleft.c\
ft_nodeaddright.c\
ft_octal_err.c\
ft_print_wchar.c\
ft_printf.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putlongnbr.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_putwnstr.c\
ft_putwstr.c\
ft_realloc.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strndup.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_treenew.c\
ft_wcharlen.c\
ft_wnstrlen.c\
get_next_line.c\
ft_printtab.c\
ft_wstrlen.c
OBJ_PATH =./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
INC_PATH=./includes/
INC_NAME=libft.h\
		 get_next_line.h\
		ft_printf.h
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))
CFLAGS=-Wall -Wextra -Werror
CC=-gcc
NAME=libftprintf.a
RED=\033[0;31m
LBLUE=\033[34m
GREEN=\033[32m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@echo "${LBLUE}ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${ORANGE}ranlib $(NAME)${NC}"
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $(NAME) : $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "${RED}Delete OBJ files${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${RED}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
