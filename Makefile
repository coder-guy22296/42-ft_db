NAME = ft_db
SRC =   main.c\
		insert_table_entry.c\
		delete_table_entry.c\
		select_table_entry.c\
		update_table_entry.c\
		write_table_to_file.c\
		load_table.c\
		free_table.c\
		command_prompt.c\
		ft_cntwords.c\
		ft_strsplit.c\
		ft_strnew.c\
		ft_memalloc.c\
		ft_stradel.c\
		display_table.c
OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
