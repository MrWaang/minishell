NAME    := minishell

SRC_DIR := src
OBJ_DIR := obj
BI_DIR  := $(SRC_DIR)/built-in

CC      := clang
CFLAGS  := -Wextra -Wall -Werror

INCLUDE := -I ./include

SRC     := main.c

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

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BI)	
	@$(LIB)
	@$(CC) $(OBJ) $(OBJ_BI) $(LIB.A) -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
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
