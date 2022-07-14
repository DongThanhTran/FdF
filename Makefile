# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dtran <dtran@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/14 14:44:11 by dtran         #+#    #+#                  #
#    Updated: 2022/07/14 15:26:47 by dtran         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#===============================================================================: Filename
NAME		= fdf

#===============================================================================: Source to object conversion location
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#===============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#===============================================================================: Include files
FDF			= include
MLX42		= include/MLX42
LIBFT		= include/libft
GNL			= include/get_next_line

#===============================================================================: Compile variables
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
MKDIR		= mkdir -p objs
HEADERS		= -I $(MLX42) -I $(LIBFT) -I $(GNL) -I $(FDF)
GLFW		= include/MLX42/libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

#===============================================================================: Sourcefiles
SRCS		= $(addprefix src/, $(addsuffix .c, \
				main ))

#===============================================================================: Make commands
all: message mlx libft gnl $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(GLFW) $(HEADERS) $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX42)/libmlx42.a -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created!$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
run: all
	@./$(NAME) maps/$(MAP).fdf

#===============================================================================: Build messages
message:
	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

#===============================================================================: MLX42 Compile
mlx:
	@$(MAKE) -C $(MLX42)

#===============================================================================: MLX42 Compile
gnl:
	@$(MAKE) -C $(GNL)

#===============================================================================: Libft Compile
libft:
	@$(MAKE) -C $(LIBFT)

#===============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files and executable
fclean:
	@$(RM) objs/
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(MLX42) fclean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run