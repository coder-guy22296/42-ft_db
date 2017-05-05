/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:50 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 19:59:05 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		main(void)
{
	t_table	table;
	t_args	args;
	char	*command;

	load_table(&table);
	printf("Commmands:\n"
				"INSERT <key> <value>\n"
				"SELECT <key>\n"
				"UPDATE <key> <value>\n"
				"DELETE <key>\n"
				"EXIT\n");
	while (1)
	{
		args = command_prompt("> ");
		if (args.args)
			command = args.args[0];
		if (args.count == 3 && strcmp(command, "INSERT") == 0)
			insert_table_entry(&table, args.args[1], args.args[2]);
		else if (args.count == 2 && strcmp(command, "SELECT") == 0)
			select_table_entry(&table, args.args[1]);
		else if (args.count == 3 && strcmp(command, "UPDATE") == 0)
			update_table_entry(&table, args.args[1], args.args[2]);
		else if (args.count == 2 && strcmp(command, "DELETE") == 0)
			delete_table_entry(&table, args.args[1]);
		else if (args.count == 1 && strcmp(command, "EXIT") == 0)
		{
			free_table(&table);
			return (0);
		}
		else
			printf("Invalid command\n");
	}
	return (0);
}
