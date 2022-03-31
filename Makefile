## File stuff

SRCS		= $(SRCS_DIR)/push_swap.c
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

INCLUDE_DIR	= includes
SRCS_DIR	= srcs
OBJS_DIR	= objs
LIBFT		= libft


## Compilation

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I $(INCLUDE_DIR) -I $(LIBFT)
LIBS		= -L libft -lft


## Other

NAME		= push_swap
RM			= rm -rf

# Colors
BLACK			= \033[0;30m
RED				= \033[0;31m
GREEN			= \033[0;32m
ORANGE			= \033[0;33m
BLUE			= \033[0;34m
PURPLE			= \033[0;35m
CYAN			= \033[0;36m
GRAY			= \033[0;37m
WHITE			= \033[1;37m
RESET			= \033[0m


## Targets
all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS) $(OBJS_DIR)
	@echo "$(GREEN)>>>>> Compiling <<<<<$(RESET)"
	gcc -c $< -o $@

$(OBJS_DIR):
	@test -d $(OBJS_DIR) || \
	mkdir $(OBJS_DIR) && \
	echo "$(BLUE)Directory '$(CYAN)$(OBJS_DIR)/$(BLUE)' doesn't exist. Creating '$(CYAN)$(OBJS_DIR)/$(BLUE)'$(RESET)"

# regular targets
$(NAME): $(OBJS)
	@echo "$(GREEN)>>>>> Linking <<<<<$(RESET)"
	$(CC) $(OBJS) -o $(NAME)

clean:
	@echo "$(GREEN)>>>>> Cleaning <<<<<$(RESET)"
	$(RM) $(OBJS)
	@echo "Cleaning libft"
	@make -C libft clean

fclean: clean
	@echo "Applying full clean"
	@$(RM) $(OBJS_DIR) $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re