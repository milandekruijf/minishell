# ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     
# ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
# ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
# ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
# ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
# ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

NAME = minishell

SRCS = \
	main strcmp is_builtin create_token add_token \
	get_last_token strlen strchr exec exec_builtin \
	ms_assert ms_malloc assert_is_builtin get_builtin \
	exec_cd exec_echo exec_env exec_exit exec_pwd \
	exec_export exec_unset exec_external parse_tokens

TESTS = is_builtin

SRC_DIR = src
TESTS_DIR = tests
INC_DIR = include
OUT_DIR = out
OBJ_DIR = $(OUT_DIR)/obj

OUT = $(OUT_DIR)/$(NAME)

CC = cc
CFLAGS = -I$(INC_DIR) 
LDFLAGS = -lreadline

ifneq ($(STRICT), 0)
	CFLAGS += -Wall -Wextra -Werror -g3
endif

MAKEFLAGS += --no-print-directory

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))
DIRS = $(sort $(dir $(OBJS)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OUT)

$(OUT): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(OUT) $(LDFLAGS)
	@echo "$@: $(GREEN)compiled $@ to $(OUT)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)compiled $< to $@$(RESET)"

$(DIRS):
	@mkdir -p $@
	@echo "$(NAME): $(GREEN)created directory $@$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) has been cleaned up$(RESET)"

fclean:
	@rm -rf $(OUT_DIR)
	@echo "$(NAME): $(GREEN)$(OUT_DIR) directory has been cleaned up$(RESET)"

re: fclean all

.PHONY: $(NAME) all re clean fclean
