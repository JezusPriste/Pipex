NAME = libft.a

HEADER = ${NAME:.a=.h}

SOURCES = 	ft_bzero.c \
			ft_calloc.c \
			ft_memmove.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c \




OBJECTS = ${SOURCES:.c=.o}


LIBC = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
		${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
		${LIBC} ${NAME} ${OBJECTS}
		ranlib ${NAME}

all: 	${NAME}

clean:
		${RM} ${OBJECTS} ${OBJECT_BONUS}

fclean: clean
		${RM} ${NAME}

re: fclean all

BONUS: ${OBJECTS} ${OBJECT_BONUS}
	   ${LIBC} ${NAME} ${OBJECTS} ${OBJECT_BONUS}
	   ranlib ${NAME}