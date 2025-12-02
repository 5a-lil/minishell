CC = cc
INCLUDES_FOLDER = headers
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_FOLDER)
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c free_char_table.c \
			is_number.c is_biggest_str.c error_handler.c print_table_of_table.c file_check.c \
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c  table_of_table_len.c \
			split_and_free.c is_in_charset.c strchr_table.c is_positive.c check_args.c \
			strlen_till_char.c free_and_replace.c \
			\
			$(addprefix ./get_next_line/, get_next_line.c get_next_line_utils.c ) \
			\
			$(addprefix ./ft_printf/srcs/, ft_printf.c putchar_fd.c putstr_fd.c putnbr_fd.c print_hexa_upper.c \
			print_hexa_lower.c print_ptr.c putnbr_unsigned_fd.c utils.c dot_flag.c \
			hash_flag.c left_justify.c minimum_field.c plus_flag.c print_char.c \
			space_flag.c zero_min_field.c assert.c) \
			
OBJS = $(SRCS:.c=.o)

# COLORS

BIGREEN = '\033[1;92m'
BIWHITE = '\033[1;97m'
BICYAN = '\033[1;96m'
BIPURPLE = '\033[1;95m'
BIYELLOW = '\033[1;93m'

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo $(BIGREEN)"[ COMPILED "libft.a" ]"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(BIPURPLE)"[ COMPILED $@ ]" 

n:
	@norminette -R CheckDefine

clean:
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re