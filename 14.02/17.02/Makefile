NAME = minitalk

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: server client

libft/libft.a:
	make -C libft

server: server.o libft/libft.a
	$(CC) $(CFLAGS) -o server server.o libft/libft.a

client: client.o libft/libft.a
	$(CC) $(CFLAGS) -o client client.o libft/libft.a

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft fclean
	rm -rf server client

re: fclean all
