# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 13:11:24 by mkamei            #+#    #+#              #
#    Updated: 2022/02/22 14:22:40 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath	%.c srcs:srcs/utils

SRCSDIR	:= srcs
SRCSNAME:=	main.c read_file.c init_object.c loop_draw.c draw_object.c \
			debug.c exit.c get_next_line.c rotate.c terminal.c
SRCS	:= $(addprefix $(SRCSDIR)/, $(SRCSNAME))

OBJSDIR :=	objs
OBJS    :=	$(addprefix $(OBJSDIR)/, $(SRCSNAME:.c=.o))
DEPS	:=	$(addprefix $(OBJSDIR)/, $(SRCSNAME:.c=.d))

INCLUDE	:=	-Iincludes
NAME	:=	term3d

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
CFLAGS	+=	-MMD -MP
RM		:=	rm -rf

LIBFTDIR	:=	libft
LIBFTNAME	:=	libft.a
LIBFT		:=	$(LIBFTDIR)/$(LIBFTNAME)
LIBFTTARGET	:=	all

LIBINCLUDE	:=	-I${LIBFTDIR}
LIBPATH		:=	-L${LIBFTDIR}
LIBLINK		:=	-l$(subst lib,,$(basename $(LIBFTNAME)))
LIB			:=	$(LIBINCLUDE) $(LIBPATH) $(LIBLINK)


all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $(NAME)

$(OBJSDIR)/%.o	:	%.c
			@mkdir -p $(OBJSDIR)
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBINCLUDE) -o $@ -c $<

ifneq ($(findstring clean,$(MAKECMDGOALS)),clean)
-include $(DEPS)
endif

$(LIBFT):
			make $(LIBFTTARGET) -C $(LIBFTDIR)

clean	:
			$(RM) $(OBJS) $(DEPS)
			make clean -C $(LIBFTDIR)

fclean	: 	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFTDIR)

re		:	fclean all

address	:	CFLAGS		+=	-g -fsanitize=address
address	:	LIBFTTARGET	=	address
address	:	re

leak	:	CC			=	/usr/local/opt/llvm/bin/clang
leak	:	CFLAGS		+=	-g -fsanitize=leak
leak	:	LIBFTTARGET	=	leak
leak	:	re

.PHONY:	all clean fclean re address leak
