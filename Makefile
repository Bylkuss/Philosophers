
NAME = philo

SRCS_PATH = srcs/

CC = gcc
# CFLAGS = -Wall -Werror -Wextra -lpthread -fsanitize=thread -g
CFLAGS = -Wall -Werror -Wextra #-lpthread
RM = rm -rf

SRCS_FILES = main.c logs.c utils.c routine.c philo.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

all: 	$(NAME)
	@echo "$(GREEN)Your program compiled succefully!💥\n$(DEFAULT)"


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created!$(DEFAULT)💯"
	
clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)💯"

fclean:	clean
	@$(RM) $(NAME) $(LIBFT)

commit:
	git add .
	git commit -m "$m $(COMMIT)"
	git push origin "$b"


re:		fclean all



.PHONY:	all clean libft fclean re



#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COMMIT = $(shell date "+%d %B %T")