NAME = chess

CARGS = -g
CC = cc

files = $(wildcard *.c)
objects = $(patsubst %.c,%.o,$(files))

all: $(NAME)

$(NAME): $(objects)
	$(CC) $(CARGS) $^ -o $@

%.o: %.c chess.h
	$(CC) $(CARGS) -c $< -o $@

clean:
	rm -rf $(objects)

fclean: clean
	rm -rf $(NAME)

re:
	make -C . fclean
	make -C . all

.PHONY: clean fclean re
