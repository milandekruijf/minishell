# ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     
# ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
# ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
# ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
# ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
# ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

NAME = minishell

SRCS = main

SRC_DIR = src
INC_DIR = include
OUT_DIR = out
OBJ_DIR = $(OUT_DIR)/obj

OUT = $(OUT_DIR)/$(NAME)

CC = cc
CFLAGS = -I$(INC_DIR)

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
	@$(CC) $(CFLAGS) $(OBJS) -o $(OUT)
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