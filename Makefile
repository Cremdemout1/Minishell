# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:39:56 by ycantin           #+#    #+#              #
#    Updated: 2024/12/03 20:42:25 by brfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minishell

SRCS_DIR = ./srcs
SRCS = main.c $(addprefix aux/, $(AUX_SRCS)) $(addprefix lexer/, $(LEXER_SRCS)) $(addprefix expand/, $(EXPAND_SRCS)) $(addprefix executor/, $(EXECUTOR_SRCS)) $(addprefix builtins/, $(BUILTINS_SRCS))

CFLAGS = -Wall -Werror -Wextra -g
DEPS = -lreadline
RM = rm -f

AUX_SRCS = aux.c frees.c signal.c signals_utils.c
EXPAND_SRCS = expansion.c expansion_utils.c expansion_utils_2.c error_correction.c error_correction_utils.c 
LEXER_SRCS = lexer.c lexer_utils.c lexer_utils_2.c redirections.c tokenize.c tokenize_utils.c tokenize_utils2.c parse.c parse2.c parse3.c parse4.c
EXECUTOR_SRCS = executor.c executor_aux.c executor_redirs.c process.c process_aux.c heredoc.c heredoc_exp.c
BUILTINS_SRCS = builtins.c export.c pwd.c env.c unset.c cd.c echo.c exit.c

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -c $< -o $@

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(DEPS)
	@echo $(NAME) ready

$(LIBFT):
	@echo compiling
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo clean

re: fclean all

run: all
	clear && ./minishell
vrun: all
	clear && valgrind --leak-check=full --suppressions=includes/readline.supp ./minishell
fullvrun: all
	clear && valgrind --leak-check=full --track-fds=yes --suppressions=includes/readline.supp --show-leak-kinds=all --track-origins=yes ./minishell

fullvrunenv: all
	clear && env -i valgrind --leak-check=full --track-fds=yes --suppressions=includes/readline.supp --show-leak-kinds=all --track-origins=yes ./minishell
fullvrununset: all
	clear && unset PATH && /usr/bin/valgrind --track-fds=yes --leak-check=full --suppressions=includes/readline.supp --show-leak-kinds=all --track-origins=yes ./minishell


.PHONY: all fclean clean re
