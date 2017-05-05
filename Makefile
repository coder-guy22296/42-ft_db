NAME = ft_db
SRC =   main.c\
		insert_table_entry.c\
		delete_table_entry.c\
		select_table_entry.c\
		update_table_entry.c\
		write_table_to_file.c\
		load_table.c\
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
