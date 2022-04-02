## File stuff

FNAMES 		=	push_swap.c stack.c parsing_utils.c

SRCS		= 	$(addprefix $(SRCS_DIR)/,$(FNAMES))

OBJS		= 	$(addprefix $(OBJS_DIR)/,$(FNAMES:.c=.o))

INCLUDE_DIR	= includes
SRCS_DIR	= srcs
OBJS_DIR	= objs
LIBFT		= libft/libft.a


## Compilation

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I $(INCLUDE_DIR) -I libft
LIBS		= -L libft -lft


## Other

NAME		= push_swap
RM			= rm -rf
ECHO		= echo -e

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(ECHO) "$(GREEN)>>>>> Compiling <<<<<$(RESET)"
	gcc $(INCLUDES) $(LIBS) -c $< -o $@

$(OBJS_DIR):
	@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR) && $(ECHO) "$(BLUE)Directory '$(CYAN)$(OBJS_DIR)/$(BLUE)' doesn't exist. Creating '$(CYAN)$(OBJS_DIR)/$(BLUE)'$(RESET)"

$(LIBFT):
	make -C libft bonus

# regular targets
$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(ECHO) "$(GREEN)>>>>> Linking <<<<<$(RESET)"
	$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	@$(ECHO) "$(GREEN)>>>>> Cleaning <<<<<$(RESET)"
	$(RM) $(OBJS)
	@$(ECHO) "Cleaning libft"
	@make -C libft clean

fclean: clean
	@$(ECHO) "Applying full clean"
	@$(RM) $(OBJS_DIR) $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re