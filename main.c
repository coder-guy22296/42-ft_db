/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:50 by jshi              #+#    #+#             */
/*   Updated: 2017/05/05 12:34:48 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static void	print_usage(void)
{
	printf("Commmands (not case sensitive):\n"
				"INSERT <key> <value>\n"
				"SELECT <key>\n"
				"UPDATE <key> <value>\n"
				"DELETE <key>\n"
				"EXIT\n");
}

static int	menu(t_args args, t_table *table)
{
	char	*command;

	if (args.args)
		command = args.args[0];
	if (args.count == 3 && strcasecmp(command, "INSERT") == 0)
		insert_table_entry(table, args.args[1], args.args[2]);
	else if (args.count == 2 && strcasecmp(command, "SELECT") == 0)
		select_table_entry(table, args.args[1]);
	else if (args.count == 3 && strcasecmp(command, "UPDATE") == 0)
		update_table_entry(table, args.args[1], args.args[2]);
	else if (args.count == 2 && strcasecmp(command, "DELETE") == 0)
		delete_table_entry(table, args.args[1]);
	else if (args.count == 1 && strcasecmp(command, "EXIT") == 0)
		return (1);
	else
		printf("Invalid command\n");
	ft_stradel(&args.args);
	return (0);
}

int			main(void)
{
	t_table	table;
	t_args	args;

	load_table(&table);
	print_usage();
	while (1)
	{
		args = command_prompt("> ");
		if (menu(args, &table))
			break ;
	}
	free_table(&table);
	ft_stradel(&args.args);
	return (0);
}
