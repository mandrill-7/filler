# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/16 18:03:56 by fchanal           #+#    #+#              #
#    Updated: 2017/06/16 19:56:20 by fchanal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
###                  Settings                 ###
#################################################

NAME = fchanal.filler
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs/
INC_PATH = -I./includes/

VISU_PATH = srcs/visualisator/
VISU_NAME = filler_arena
VISU_INC = -I./srcs/visualisator -framework OpenGL -framework AppKit
MINILIBX_PATH = ./srcs/visualisator/minilibx/libmlx.a
MINI_LIB_PATH = ./srcs/fl_mini_libft/

#################################################
###                  Colors                   ###
#################################################

COL_BLACK  = \033[1;30m
COL_RED    = \033[1;31m
COL_GREEN  = \033[1;32m
COL_YELLOW = \033[1;33m
COL_BLUE   = \033[1;34m
COL_PURPLE = \033[1;35m
COL_WHITE  = \033[1;37m

#################################################
###                 Sources                   ###
#################################################

VISU_SRC =\
		  \
		  main.c \
		  grid.c \
		  token.c \
		  utilities.c

MINI_LIB_SRC =\
			  \
			  ft_atoi.c \
			  ft_strlen.c \
			  ft_strchr.c \
			  ft_get_nbr.c \
			  ft_isdigit.c \
			  ft_get_snbr.c \
			  \
			  ft_get_next_line.c \
			  ft_clist_del_node.c \
			  ft_clist_insert.c \
			  ft_clist_new.c \
			  ft_clist_find_prev.c \
			  ft_memdel.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strmerge.c \
			  ft_strnew.c \
			  ft_strsub.c

SRC =\
	\
	filler.c \
	fl_play.c \
	fl_reset.c \
	fl_rush.c \
	fl_utilities.c \
	\
	ft_printf/ft_vdprintf.c \
	ft_printf/ft_vprintf.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_dprintf.c \
	ft_printf/pf_color.c \
	ft_printf/pf_buffering.c \
	ft_printf/pf_utilities.c \
	ft_printf/pf_unicode_handler.c \
	ft_printf/pf_get_attr.c \
	ft_printf/pf_numb_conv_tools.c \
	ft_printf/pf_casting.c \
	\
	ft_printf/pf_specifier/pf_convert_m.c \
	ft_printf/pf_specifier/pf_convert_big_m.c \
	ft_printf/pf_specifier/pf_convert_b.c \
	ft_printf/pf_specifier/pf_convert_c.c \
	ft_printf/pf_specifier/pf_convert_big_c.c \
	ft_printf/pf_specifier/pf_convert_d.c \
	ft_printf/pf_specifier/pf_convert_o.c \
	ft_printf/pf_specifier/pf_convert_p.c \
	ft_printf/pf_specifier/pf_convert_s.c \
	ft_printf/pf_specifier/pf_convert_big_s.c \
	ft_printf/pf_specifier/pf_convert_u.c \
	ft_printf/pf_specifier/pf_convert_v.c \
	ft_printf/pf_specifier/pf_convert_x.c \
	ft_printf/pf_specifier/pf_convert_y.c \
	ft_printf/pf_specifier/pf_convert_big_y.c \
	ft_printf/pf_specifier/pf_convert_n.c \
	ft_printf/pf_specifier/pf_convert_w.c \
	ft_printf/pf_specifier/pf_convert_big_w.c \
	ft_printf/pf_specifier/float/pf_convert_f.c \
	ft_printf/pf_specifier/float/pf_float_engine.c \
	ft_printf/pf_specifier/float/pf_float_integer_part.c \
	\
	ft_printf/pf_mini_libft/ft_dexp.c \
	ft_printf/pf_mini_libft/ft_get_dint_part.c \
	ft_printf/pf_mini_libft/ft_memcpy.c \
	ft_printf/pf_mini_libft/ft_memcmp.c \
	ft_printf/pf_mini_libft/ft_memset.c \
	ft_printf/pf_mini_libft/ft_strchr_zero.c \
	ft_printf/pf_mini_libft/ft_strnlen.c \
	ft_printf/pf_mini_libft/ft_isprint.c

#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_PATH), $(SRC))
O = $(notdir $(SRC))
OB = $(basename $(O))
OBJ = $(addsuffix .o ,$(OB))

VISU_SRCS = $(addprefix $(VISU_PATH), $(VISU_SRC))

MINI_LIB_SRCS = $(addprefix $(MINI_LIB_PATH), $(MINI_LIB_SRC))

#################################################
###                   Rules                   ###
#################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(MINI_LIB_SRCS)
	$(CC) -o $(NAME) $(FLAGS) $(INC_PATH) $(SRCS) $(MINI_LIB_SRCS)

arena: $(VISU_SRCS) $(MINI_LIB_SRCS)
	$(CC) -o $(VISU_NAME) $(FLAGS) $(VISU_INC) $(VISU_SRCS) $(MINI_LIB_SRCS) $(MINILIBX_PATH) $(INC_PATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
