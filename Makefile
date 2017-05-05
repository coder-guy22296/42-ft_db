NAME = ft_db
SRC =   main.c\
		add_table_entry.c\
		delete_entry.c\
		get_entry.c\
		update_entry.c\
		update_file.c\
		load_db.c\
		command_prompt.c\
		ft_cntwords.c\
		ft_strsplit.c
OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
