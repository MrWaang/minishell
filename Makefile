NAME    := minishell

SRC_DIR := src
OBJ_DIR := obj
BI_DIR  := $(SRC_DIR)/built-in

CC      := clang
CFLAGS  := -Wextra -Wall -Werror -g

INCLUDE := -I ./include

SRC     := main.c \
		   utils.c \
		   built_in_utils.c \
		   export_utils.c \
		   prompt.c \
		   parsing/lexer/token_create.c \
		   parsing/lexer/lexer.c \
		   parsing/lexer/lexer_utils.c \
		   parsing/lexer/quote_utils.c \
		   parsing/lexer/quote.c \
		   parsing/expansion/expand_manager.c \
		   parsing/expansion/expand_quotes.c \
		   parsing/expansion/expand_vars.c \
		   parsing/expansion/expand_utils.c \
		   parsing/expansion/expand_split.c \
		   parsing/expansion/expand_split_utils.c \
		   parsing/syntax/syntax_checker.c \
		   parsing/syntax/syntax_error.c \
		   parsing/syntax/syntax_pipe.c \
		   parsing/syntax/syntax_redir.c \
		   parsing/syntax/syntax_utils.c \
		   parsing/parser/arg_collector.c \
		   parsing/parser/cmd_builder.c \
		   parsing/parser/parser_utils.c \
		   parsing/parser/parser.c \
		   parsing/parser/redir_parser.c \
		   exec/executor.c \
           exec/exec_cmd.c \
           exec/exec_builtin.c \
           exec/exec_external.c \
           exec/exec_pipes.c \
           exec/redirections.c \
           exec/heredoc.c \
           exec/path_finder.c \
           exec/signals.c \
           exec/wait_process.c \


BI		:= cd.c \
		   pwd.c \
		   env.c \
		   echo.c \
		   exit.c \
		   unset.c \
		   export.c \


OBJ     := $(SRC:%.c=$(OBJ_DIR)/%.o)

OBJ_BI	:= $(BI:%.c=$(OBJ_DIR)/%.o)

GREEN   := \033[1;32m
NC      := \033[0m

LIB     := make -sC libft
LIB.A	:= libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BI)
	@$(LIB)
	@$(CC) $(OBJ) $(OBJ_BI) $(LIB.A) -lreadline -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(BI_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)
	@printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"


re: fclean all

clean:
	@rm -rf $(OBJ_DIR)
	make clean -sC libft

fclean: clean
	@rm -f $(NAME)
	make fclean -sC libft

.PHONY:
	all clean fclean re
