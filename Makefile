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
	env/print_env_var env/create_env_var \

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
