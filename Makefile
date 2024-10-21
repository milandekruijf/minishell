# ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗
# ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║
# ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║
# ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║
# ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
# ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

NAME = minishell

SRCS = \
	main utils/strcmp builtins/is_builtin utils/strlen utils/strchr \
	exec/exec exec/exec_builtin utils/assert utils/malloc \
	builtins/assert_is_builtin builtins/get_builtin exec/exec_cd \
	exec/exec_echo exec/exec_env exec/exec_exit exec/exec_pwd \
	exec/exec_export exec/exec_unset exec/exec_external \
	tokens/parse_tokens tokens/tkn_create_str utils/strdup \
	tokens/tkn_add_token_to_list tokens/tkn_create_substr \
	tokens/tkn_init_token_list utils/strndup tokens/print_token \
	tokens/print_tokens tokens/get_token_type_name \
	signals/handle_sigint signals/listen_sigint env/print_envp \
	env/parse_envp env/add_env_var env/init_env_var_list \
	env/print_env_var env/create_env_var tokens/free_token \
	tokens/free_tokens env/print_env_var_list env/get_env_var \

TESTS = \
	main test_parse_tokens test_is_builtin test_parse_envp \

SRC_DIR = src
TESTS_DIR = tests
INC_DIR = include
OUT_DIR = out
OBJ_DIR = $(OUT_DIR)/obj
TESTS_OBJ_DIR = $(OBJ_DIR)/tests

OUT = $(OUT_DIR)/$(NAME)
TESTS_OUT = $(OUT_DIR)/$(NAME)_tests

CC = cc
CFLAGS = -I$(INC_DIR)
LDFLAGS = -lreadline

ifneq ($(STRICT), 0)
	CFLAGS += -Wall -Wextra -Werror
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -fsanitize=address
endif

MAKEFLAGS += --no-print-directory

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))
TESTS_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(addprefix $(TESTS_OBJ_DIR)/, $(addsuffix .o, $(TESTS)))

DIRS = $(sort $(dir $(OBJS) $(TESTS_OBJS)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OUT)

$(OUT): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(OUT) $(LDFLAGS)
	@echo "$(NAME): $(GREEN)compiled exec file '$(OUT)'$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)compiled '$<' -> '$@'$(RESET)"

test: $(TESTS_OUT)
	@echo "$(NAME): $(GREEN)running tests '$(TESTS_OUT)'$(RESET)"
	@./$(TESTS_OUT)

$(TESTS_OUT): $(TESTS_OBJS)
	@$(CC) $(CFLAGS) $(TESTS_OBJS) -o $(TESTS_OUT) $(LDFLAGS)
	@echo "$(NAME)_tests: $(GREEN)compiled tests exec file '$(TESTS_OUT)'$(RESET)"

$(TESTS_OBJ_DIR)/%.o: $(TESTS_DIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME)_tests: $(GREEN)compiled test '$<' -> '$@'$(RESET)"

$(DIRS):
	@mkdir -p $@
	@echo "$(NAME): $(GREEN)created dir '$@'$(RESET)"

lint:
	@norminette src include/minishell.h

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)cleaned dir '$(OBJ_DIR)'$(RESET)"

fclean:
	@rm -rf $(OUT_DIR)
	@echo "$(NAME): $(GREEN)cleaned dir '$(OUT_DIR)'$(RESET)"

re: fclean all

.PHONY: $(NAME) all re clean fclean tests lint
