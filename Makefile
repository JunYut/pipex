# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

# Files
SOURCE = $(SRC_DIR)/validation.c $(SRC_DIR)/read.c $(SRC_DIR)/command.c\
		 $(SRC_DIR)/utils.c $(SRC_DIR)/parser.c
OBJECTS = $(SOURCE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDE = pipex.h
LIBFT = $(LIBFT_DIR)/libft.a
LIBPIPEX = libpipex.a
NAME = pipex

# Rules & Recipes
all: $(NAME)

$(NAME): $(LIBPIPEX) main.c
	$(CC) $(CFLAGS) -o $(NAME) main.c -L. -L$(LIBFT_DIR) -lpipex -lft

$(LIBPIPEX): $(LIBFT) $(OBJECTS)
	ar rcs $(LIBPIPEX) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT) $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I.$(INCLUDE) -I$(LIBFT_DIR) $< -o $@

$(LIBFT):
	mkdir -p $(LIBFT_DIR)/$(OBJ_DIR)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re