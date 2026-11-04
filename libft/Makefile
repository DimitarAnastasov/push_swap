# Name of the output library
NAME = libft.a

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# All source files grouped by section
# Part 1: Libc functions
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c \
       \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c \
       \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
       ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Convert all .c files to .o files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Compile the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files AND the library
fclean: clean
	rm -f $(NAME)

# Clean everything and recompile from scratch
re: fclean all

# Phony targets to prevent conflicts with files named "all", "clean", etc.
.PHONY: all clean fclean re