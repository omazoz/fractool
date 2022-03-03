# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:27:23 by omazoz            #+#    #+#              #
#    Updated: 2022/03/03 20:03:05 by omazoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

INCLUDE = $(INC_DIR)/fractol.h

INCLUDES = $(INC_DIR)/fractol.h\
		   $(INC_DIR)/ft_mlx_keys.h

SRC = main.c\
	  events.c\
	  init.c\
	  mandelbrot.c\
	  images.c\
	  julia.c\
	  burningship.c
OBJ = $(addprefix $(OBJ_DIR)/, ${SRC:.c=.o})

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -I ./libft

LIBFT = ./libft/libft.a

BLUE=\033[0;34m

RESET=\033[0m

CC = cc

all : $(NAME) | fractal_art

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I $(INC_DIR) -I libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME) : $(LIBFT) $(OBJ) $(INCLUDES)
			@$(CC) $(CFLAGS) $(OBJ) -I $(INC_DIR) -o $(NAME)

$(LIBFT) :
	make -C ./libft

clean :
	@make -C ./libft clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: fractal_art

fractal_art:
	@echo "$(BLUE)";
	@echo "███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗     ";
	@echo "██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║     ";
	@echo "█████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║     ";
	@echo "██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║     ";
	@echo "██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗";
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝";
	@echo "$(RESET)"
	@echo "$(BLUE)";
	@echo "                                                       ";
	@echo "	                                                ,_		"
	@echo "                                              iW@@Wi		"
	@echo "                                              !@@@@f		"
	@echo "                                      __ ,gsmWmmWWmmmmsz		"
	@echo "                                      M@W@@@@@@@@@@@@@@@@bd@P		"
	@echo "                                   ,sm@@@@@@@@@@@@@@@@@@@@@W_		"
	@echo "                                  ,m@@@@@@@@@@@@@@@@@@@@@@@@@s.		"
	@echo "                      s.,_s..    ,W@@@@@@@@@@@@@@@@@@@@@@@@@@W		"
	@echo "                    ,_@@@@@@@Ws. d@@@@@@@@@@@@@@@@@@@@@@@@@@@@		"
	@echo "                    W@@@@@@@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@A		"
	@echo "      ----*-----i@@W@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@P  		"
	@echo "                 ~~@@@@@@@@@@@@!@@@@@@@@@@@@@@@@@@@@@@@@@@@Ws		"
	@echo "                    !*@@@@@@@@Af M@@@@@@@@@@@@@@@@@@@@@@@@@@@@		"
	@echo "                      AfV*Aff   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@		"
	@echo "                                  !@@@@@@@@@@@@@@@@@@@@@@@@@@D-		"
	@echo "                                   -A@@@@@@@@@@@@@@@@@@@@@@@*		"
	@echo "                                      8@@@@@@@@@@@@@@@@@@AMWi		"
	@echo "                                      **'VMA@@@@@@@@@@AK~'~~		"
	@echo "                                             ,mWWm.		"
	@echo "                                              ]@@@@P		"
	@echo "                                               'V*		"
	@echo "$(RESET)"
