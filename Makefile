# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2018/09/25 12:48:26 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

MLX = mlx/libmlx.a
INCLUDES = -I includes/ -I mlx/mlx.h
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra -g3 -fsanitize=address

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(addprefix vector/, vector vector2 angle vecrot intersection) \
	   $(addprefix core/, main loop render map) \
	   $(addprefix events/, keys mouse window ) \
	   $(addprefix playerhandling/, playermove) \
	   $(addprefix tools/, malloc error images putline allocate) \
		))

all: $(NAME)

$(NAME): objs $(OBJS)
	@make -C mlx
	@gcc -o $(NAME) $(MLX) $(OBJS) $(FLAGS) $(INCLUDES)

objs/%.o: srcs/%.c
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

objs:
	@mkdir -p objs/events
	@mkdir objs/tools
	@mkdir objs/core
	@mkdir objs/vector
	@mkdir objs/playerhandling

clean:
	@make -C mlx clean
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX)

re:
	@$(MAKE) fclean
	@$(MAKE)
	@make -C mlx re
