# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 22:58:00 by abenamar          #+#    #+#              #
#    Updated: 2023/07/05 04:22:16 by abenamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT := $(CURDIR)/libft/libft.a

MLX := $(CURDIR)/mlx/libmlx.a

INCLUDES := -I $(CURDIR)
INCLUDES += -I $(CURDIR)/libft
INCLUDES += -I $(CURDIR)/mlx

LDFLAGS := -L$(CURDIR)/libft
LDFLAGS += -L$(CURDIR)/mlx

LDLIBS := -lft
LDLIBS += -lmlx
LDLIBS += -lXext
LDLIBS += -lX11
LDLIBS += -lm

SRCS := ft_free_xclient.c
SRCS += ft_init_xclient.c
SRCS += fdf.c

OBJS := $(SRCS:.c=.o)

BOBJS := $(BSRCS:.c=.o)

CC := cc

CFLAGS := -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g3

RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	@$(MAKE) -C $(CURDIR)/libft $(findstring bonus, $(MAKECMDGOALS))

$(MLX):
	@$(MAKE) -C $(CURDIR)/mlx

bonus: $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all bonus