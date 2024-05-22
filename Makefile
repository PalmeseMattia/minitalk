CLIENT_EXEC = client
SERVER_EXEC = server

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CFLAGS = #-Wall -Wextra -Werror
CC = gcc

all: $(LIBFT_LIB) $(CLIENT_EXEC) $(SERVER_EXEC)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(CLIENT_EXEC): $(CLIENT_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(SERVER_EXEC): $(SERVER_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)

re: fclean all

.PHONY: all clean fclean re
