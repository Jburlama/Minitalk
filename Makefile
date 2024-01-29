NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES_SERVER = server.c
CFILES_CLIENT = client.c
LIBFT = libft/libft.a

all: $(NAME)

server: $(CFILES_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o server

client: $(CFILES_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o client

$(LIBFT):
	@make -C libft

bonus: all

clean:
	@make $@ -C libft

fclean:
	@make $@ -C libft
	rm -rf $(NAME)

re: fclean all
