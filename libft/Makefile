CC=cc
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putnbr_fd.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strlcpy.c ft_calloc.c ft_putendl_fd.c ft_putstr_fd.c ft_striteri.c ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_strtrim.c \
ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c ft_printf_s.c ft_printf_u.c ft_printf_upper_x.c ft_printf_x.c ft_strcmp.c\
get_next_line.c
HEADER = libft.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJSB = $(SRCSB:.c=.o)
FTPRINTF_DIR = ft_printf/

all:$(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

bonus: $(OBJSB) $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS) $(OBJSB)

run:
	paco

re: fclean all

.PHONY: all fclean clean run re bonus
