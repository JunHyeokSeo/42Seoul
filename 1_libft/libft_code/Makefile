NAME = libft.a
SRC_M = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c \
      ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
      ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c \
      ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
      ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
      ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c \
      ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c

SRC_B = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
		ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

ARFLAG = -rcs
CFLAG = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJS = $(OBJ_M) $(OBJ_B)
else
	OBJS = $(OBJ_M)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all bonus clean fclean re