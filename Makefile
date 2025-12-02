CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I$(INCLUDES_DIR)
NAME = minishell
SRCS_BUILTINS = $(addprefix builtins/, echo.c cd.c pwd.c exit.c export.c env.c \
					unset.c utils_builtins/is_builtin.c utils_builtins/redir_builtins.c )
SRCS_UTILS = $(addprefix utils/, find_env_var.c split_quote.c split_quote_loop.c temp_func.c exit_free.c list_to_table.c print_alph_sorted.c split_ign_quote.c mini_split_ign_quotes.c strdup_quotes.c table_to_string.c )
SRCS_PARSING = $(addprefix parsing/, env_expansion.c recursive_descent_pars.c processes.c signals.c exec.c exec_builtins.c list_inits.c list_wredir_inits.c list_wredir_inits_handle.c list_inits_handle.c checks.c checks_list.c checks_quotes.c last_cmd_process.c redirs.c mini_redirs.c redirs_handle.c mini_env_expansion.c )
SRCS_BASH_FEATURES = $(addprefix bash_features/, is_dir.c is_executable.c )
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_BUILTINS) $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_BASH_FEATURES) minishell.c )
OBJS = $(SRCS:.c=.o)
INCLUDES_DIR = headers
SRCS_DIR = srcs
OBJS_DIR = objs
LIBRARIES = ./libft/libft.a

BIGREEN = '\033[1;92m'
BIWHITE = '\033[1;97m'
BICYAN = '\033[1;96m'
BIPURPLE = '\033[1;95m'
BIYELLOW = '\033[1;93m'
COLEND = \e[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) -lreadline $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES) 
	@echo $(BIGREEN)"[ COMPILED $(NAME) ]$(COLEND)"
	@echo $(BIWHITE)"use with : ./$(NAME)$(COLEND)"

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo $(BIPURPLE)"[ COMPILED $@ ]$(COLEND)"

clean:
	@make -C libft clean
	@rm -rf $(OBJS)
	@echo $(BIYELLOW)"[ CLEANDED .o files ]$(COLEND)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo $(BIYELLOW)"[ CLEANDED $(NAME) ]$(COLEND)"

re: fclean all