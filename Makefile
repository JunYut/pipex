# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft

# Files
SOURCE = main.c
OBJECTS = $(SOURCE:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex

# Rules & Recipes
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re