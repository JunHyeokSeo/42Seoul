NAME = libftprintf.a
SRC = ft_printf.c print_lst.c put_x.c put_per.c put_mem.c error_check.c\
		put_chr.c put_nbr.c put_str.c ft_strchr.c ft_strlen.c
OBJ = $(SRC:.c=.o)
ARFLAG = -rcs
CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re