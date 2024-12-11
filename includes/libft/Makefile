# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <bruno@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 12:26:26 by ycantin           #+#    #+#              #
#    Updated: 2024/11/13 17:24:32 by bruno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strcmp.c \
ft_printf_numbers.c ft_printf_str.c ft_printf.c ft_strcat.c ft_free_array.c ft_strcpy.c ft_lstnew.c \
ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_is_even.c ft_nl.c ft_strrem.c ft_count_strings.c \
ft_getenv.c ft_strndup.c get_next_line.c get_next_line_utils.c ft_replace_free.c

OBJDIR = ./objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -c $< -o $@

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re