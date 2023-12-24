# Directories
SRC_DIR 			  	= sources
INCLUDES_DIR 			= includes
LIBS_DIR 					= libs
LIBFT_DIR 				= $(LIBS_DIR)/libft
PRINTF_DIR 				= $(LIBS_DIR)/printf
OBJ_DIR 					= objects

# colors
GREEN 						= \033[0;32m
RED 							= \033[0;31m
RESET 						= \033[0m
ORANGE 						= \033[0;33m

# Compiler and flags
CC 								= gcc -g3 -o -fsanitize=address
CFLAGS 						= -Wall -Werror -Wextra -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I/usr/local/opt/readline/include

# Libraries
LIBFT 						= $(LIBFT_DIR)/libft.a
PRINTF 						= $(PRINTF_DIR)/libftprintf.a

# Header files
HEADERS 					= $(INCLUDES_DIR)/minishell.h

# Source files
SRC 							= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/parsing/expansion/*.c) $(wildcard $(SRC_DIR)/parsing/rediraction/*.c) $(wildcard $(SRC_DIR)/parsing/strtok/*.c) $(wildcard $(SRC_DIR)/parsing/utils/*.c)

OBJ 							= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Output executable
NAME 							= minishell

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Compiling libft bonus...$(RESET)"
	@make bonus -C ${LIBFT_DIR} > /dev/null
	@$(CC) $(CFLAGS) $^ -lreadline -o $@
	@echo "$(GREEN)Minishell is ready!!!$(RESET)"
	@echo "$(ORANGE)Run ./minishell to start$(RESET)"

$(LIBFT):
	@echo "\n$(GREEN)Compiling $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF):
	@echo "$(GREEN)Compiling $(PRINTF)...$(RESET)"
	@$(MAKE) -sC $(PRINTF_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/utils
	# @echo "$(GREEN)Compiling minishell...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $(OBJ_DIR)/$*.o)
	@$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$*.o
	@echo "$(GREEN).\c$(RESET)"

clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(PRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

fclean: clean
	@echo "$(RED)Removing libraries...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)

re: fclean all
