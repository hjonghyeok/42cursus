NAME		= push_swap
BNAME		= checker
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= 	main.c			\
			sort.c 			\
			sort_utils.c	\
			cmd_sp.c 		\
			cmd_r.c			\
			stacks.c		\
			stack_rotate.c	\
			input_check.c 	\
			ft_atol.c		\
			ft_abs.c		\
			get_min.c		\
			indexing.c		\
			greedy.c		\
			init_num.c		\
			memory_free.c

BSRCS	= 	main_bonus.c	\
			read_std.c		\
			checker.c 		\
			bonus_utils.c	\
			sort.c 			\
			sort_utils.c	\
			cmd_sp.c 		\
			cmd_r.c			\
			stacks.c		\
			stack_rotate.c	\
			input_check.c 	\
			ft_atol.c		\
			ft_abs.c		\
			get_min.c		\
			indexing.c		\
			greedy.c		\
			init_num.c		\
			memory_free.c

OBJS	= $(SRCS:.c=.o)

BOBJS	= $(BSRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

$(BNAME) : $(BOBJS)
	make -C $(LIBFTDIR) bonus
	$(CC) $(CFLAGS) $(BOBJS) -L./libft -lft -o $(BNAME)

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME) $(BNAME)

re : fclean all

bonus: $(BNAME)

.PHONY : all clean fclean re bonus