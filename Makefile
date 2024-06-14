NAME	= printf_ft
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I ./includes/printf_ft

LPATH	= ./libft/

SRCS	= $(addprefix src/, main.c formats_cspdiu.c format_manager.c transformToHexadecimal.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LPATH)
	$(CC) $(OBJS) $(CFLAGS) $(LPATH)libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LPATH)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LPATH)

re: fclean all

.phony: all libft clean fclean