/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:06:54 by jshi              #+#    #+#             */
/*   Updated: 2017/05/05 12:30:59 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# define FN ".database"

typedef struct		s_args
{
	char			**args;
	int				count;
}					t_args;

typedef struct		s_row
{
	char			*key;
	char			*value;
	struct s_row	*next;
}					t_row;

typedef struct		s_table
{
	t_row			*row;
}					t_table;

/*
**	write our t_table (table) from memory into a file
**	@param table: the table to be written to file
*/
void				write_table_to_file(t_table *table);

/*
**	add a key value pair to the table passed as a param
**	@param table: the table that the entry will be added to
*/
void				insert_table_entry(t_table *table, char *key, char *value);

/*
**	remove a key value pair from the specified table
**	@param table: the table to search through
**	@param key: the key of the key value pair to delete
*/
void				delete_table_entry(t_table *table, char *key);

/*
**	update the value of a key value pair
**	@param table: the table to search through
**	@param key: the key of the entry you want to update
**	@param new_value: the new value for the found entry
*/
void				update_table_entry(t_table *table, char *key,
					char *new_value);

/*
**	get the value for the entry with specified key
**	@param table: the table to search through
**	@param key: the key used to find the entry to display
**	@return the value associated with the key in the table
*/
void				select_table_entry(t_table *table, char *key);

/*
**	displays all the key value pairs inside the table
**	@param table: the table that will be displayed
*/
void				display_table(t_table *table);

/*
**	loads a table from file into our struct
**	@param table: the table struct that you want to load the file into
*/
void				load_table(t_table *table);

/*
**	cleans up the table struct
**	@param table: the table to remove
*/
void				free_table(t_table *table);

/*
**	display message and wait for a command in standard input
**	@param msg: display this message for the user before getting command
**	@return returns struct with command and parameters
*/
t_args				command_prompt(char *msg);

/*
**	counts the number of tokens separated by a delimiter character
**	@param str: the string that contatins tokens
**	@param delim: the character that separates the tokens
**	@return	number of tokens in the string
*/
int					ft_cntwords(char const *str, char delim);

/*
**	splits the string into an array of tokens separated by a delimiter
**	@param str: the string that contatins tokens
**  @param delim: the character that separates the tokens
**	@return array of c-string tokens
*/
char				**ft_strsplit(char const *s, char c);

/*
**	Libft functions
*/
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_stradel(char ***arr);
#endif
