NAME = pipex
LIB = libpipex.a

MAIN = pipex.c

SOURCES = \
	ft_strlen.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_substr.c \
	ft_strjoin.c ft_split.c ft_putstr_fd.c ft_strdup.c ft_check_args.c \
	ft_path.c utils.c ft_execute.c ft_exit.c

MAINOBJECT = $(MAIN:.c=.o)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MAINOBJECT) $(OBJECTS)
	ar -rcs $(LIB) $(OBJECTS)
	$(CC) -o $(NAME) $(CFLAGS) $(MAINOBJECT) -L. -l$(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(LIB) $(MAINOBJECT) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
