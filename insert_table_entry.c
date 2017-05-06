/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_table_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:52:07 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/04 20:15:06 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static t_row	*row_new(char const *key, char const *value)
{
	t_row *node;

	if (!(node = (t_row *)calloc(1, sizeof(t_row))))
		return (NULL);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
	return (node);
}

static int		search_table_entry(t_table *table, char *key)
{
	t_row	*cur;

	cur = table->row;
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			printf("Key already exists\n");
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void			insert_table_entry(t_table *table, char *key, char *value)
{
	t_row	*new_node;

	if (!key || !value || search_table_entry(table, key) ||
			!(new_node = row_new(key, value)) ||
			strchr(key, ',') || strchr(value, ','))
	{
		printf("Invalid input\n");
		return ;
	}
	new_node->next = table->row;
	table->row = new_node;
	write_table_to_file(table);
}
