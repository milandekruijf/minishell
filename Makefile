# ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗
# ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║
# ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║
# ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║
# ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
# ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

NAME = minishell
NAME_TESTS = $(NAME)_tests

SRCS = \
	main utils/strcmp utils/strlen utils/strchr \
	exec/exec utils/assert utils/malloc  \
	exec/exec_exit exec/exec_pwd exec/exec_bin \
	tkns/parse_tkns run/run_it utils/join_argv \
	tkns/create_tkn utils/strdup tkns/add_tkn \
	tkns/init_tkn_list utils/strndup tkns/print_tkn \
	tkns/print_tkn_list tkns/get_tkn_type_name \
	signals/handle_sigint signals/listen_sigint env/print_envp \
	env/parse_envp env/add_env_var env/init_env_var_list \
	env/print_env_var env/create_env_var tkns/free_tkn \
	tkns/free_tkn_list env/print_env_var_list env/get_env_var \
	env/free_env_var env/free_env_var_list tkns/create_tkn_list \
	env/create_env_var_list env/env_var_list_to_envp \
	env/get_env_var_list_size utils/strcat utils/strncat \
	utils/strcpy cmds/add_cmd cmds/create_cmd_list cmds/create_empty_cmd \
	cmds/init_cmd_list cmds/parse_cmds cmds/free_cmd_list \
	cmds/free_cmd utils/strtok run/run_c exec/exec_env \
	exec/exec_unset env/unset_env_var exec/exec_export \
	env/set_env_var exec/exec_cd exec/exec_abs exec/exec_path \
	cwd/get_cwd cwd/set_cwd env/ensure_env_var \
	utils/sprintf utils/realloc utils/memcpy utils/fputs \
	err/print_err err/exit_err exec/exec_echo vars/expand_vars \
	utils/strncpy utils/isspace utils/abs utils/itoa \
	utils/ndigits utils/strcspn exit/exit_msg utils/dprintf \
	utils/vsprintf utils/vsnprintf utils/snprintf utils/vdprintf \

TESTS = \
	main test_parse_tokens test_parse_envp test_get_env_var \
	test_snprintf

SRC_DIR = src
TESTS_DIR = tests
INC_DIR = include
OUT_DIR = out
OBJ_DIR = $(OUT_DIR)/obj
TESTS_OBJ_DIR = $(OBJ_DIR)/tests

OUT = $(OUT_DIR)/$(NAME)
TESTS_OUT = $(OUT_DIR)/$(NAME_TESTS)

CC = cc
CFLAGS = -I$(INC_DIR)
LDFLAGS = -lreadline

VALGRINDFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

ifneq ($(STRICT), 0)
	CFLAGS += -Wall -Wextra -Werror
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

MAKEFLAGS += --no-print-directory

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))
TESTS_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(addprefix $(TESTS_OBJ_DIR)/, $(addsuffix .o, $(TESTS)))

DIRS = $(sort $(dir $(OBJS) $(TESTS_OBJS)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME) $(NAME_TESTS)

$(NAME): $(OUT)

$(OUT): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(OUT) $(LDFLAGS)
	@echo "$(NAME): $(GREEN)compiled exec file '$(OUT)'$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)compiled '$<' -> '$@'$(RESET)"

run: $(OUT)
	@echo "$(NAME): $(GREEN)running '$(OUT)'$(RESET)"
	@./$(OUT)

test:
	@DEBUG=1 make re_tests
	@echo "$(NAME): $(GREEN)running tests '$(TESTS_OUT)'$(RESET)"
	@valgrind $(VALGRINDFLAGS) ./$(TESTS_OUT)

debug:
	@DEBUG=1 make re_main
	@echo "$(NAME): $(GREEN)running debug mode '$(OUT)'$(RESET)"
	@valgrind $(VALGRINDFLAGS) ./$(OUT)

tests: $(NAME_TESTS)

$(NAME_TESTS): $(TESTS_OUT)

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

clean_tests:
	@rm -rf $(TESTS_OBJ_DIR)
	@echo "$(NAME)_tests: $(GREEN)cleaned dir '$(TESTS_OBJ_DIR)'$(RESET)"

re_tests: fclean $(NAME_TESTS)

re_main: fclean $(NAME)

re: fclean all

.PHONY: $(NAME) $(NAME_TESTS) all tests re re_main re_tests clean clean_tests fclean run lint debug
