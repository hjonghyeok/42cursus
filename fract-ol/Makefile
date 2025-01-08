NAME		= 	fract-ol
LIBFTDIR	= 	./ft_printf
LIBFTLIB	= 	libftprintf.a
MINILIBDIR	= 	./minilibx-linux
MINILIB		= 	libmlx_Linux.a

CFLAGS		= 	cc -Wall -Werror -Wextra
RM			= 	rm -rf
LINKS		= 	-I$(LIBFTDIR) -L$(LIBFTDIR) -lftprintf					\
				-I$(MINILIBDIR) -L$(MINILIBDIR) -lmlx -lXext -lX11 -lm

SRCS		= 	main.c					\
				math/math.c				\
				draw/color.c			\
				draw/draw.c				\
				draw/iter_count.c		\
				event/event.c			\
				mandatory/error.c		\
				mandatory/help.c		\
				mandatory/check.c		\
				utils/ft_atod.c			\
				utils/set.c				\

BSRCS 		= 	main_bonus.c			\
				math/math.c				\
				draw/color.c			\
				draw/draw.c				\
				draw/iter_count.c		\
				event/event.c			\
				bonus/error.c			\
				bonus/help.c			\
				bonus/check.c			\
				utils/ft_atod.c			\
				utils/set.c				\

MOBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

ifndef BONUS
	OBJ = $(SRCS:.c=.o)
else
	OBJ = $(BSRCS:.c=.o)
endif

%.o: %.c
	$(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	make -C $(LIBFTDIR)
	make -C $(MINILIBDIR)
	$(CC) $(OBJ) -o $(NAME) $(LINKS)

all	: $(NAME)

clean : 
	make -C $(LIBFTDIR) fclean
	make -C $(MINILIBDIR) clean
	$(RM) $(MOBJS) $(BOBJS) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : 
	@make BONUS=1 all

.PHONY : all clean fclean re bonus