	# COLORS_TEXT
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
#
B = \033[40m    #чёрный цвет фона
R = \033[41m    #красный цвет фона
G = \033[42m    #зелёный цвет фона
Y = \033[43m    #желтый цвет фона
BL = \033[44m    #синий цвет фона
M = \033[45m    #фиолетовый цвет фона
C = \033[46m    #цвет морской волны фона
W = \033[47m    #серый цвет фона
#
NAME		=	pipex
#
SOURSE		=	pipex_utils.c\
				pipex_utils2.c\
				pipex.c\
				main.c
# 
#CFLAGS		= -Wall -Werror -Wextra -I. $(HEADER)
HEADER		= pipex.h

OBJ = $(SOURSE:%.c=%.o)
CC = gcc
#
.PHONY : all clean fclean re bonus
#
all: $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
#
fclean : clean
	@rm -f $(NAME)
re     :	fclean all
