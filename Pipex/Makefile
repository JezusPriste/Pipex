NAME = pipex

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = 	pipex.c \
		utils.c \
		utils2.c \
		cleaner.c \

OBJ = ${SRC:.c=.o}

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.o:.c
		${cc} ${CFLAGS} -c $< -o ${NAME}

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
		${CC} ${OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
		make -C $(LIBFT_PATH)

clean:
		${RM} ${OBJ}
		make clean -C ${LIBFT_PATH}

fclean: clean
		${RM} ${LIBFT}
		${RM} ${NAME}

re: fclean all