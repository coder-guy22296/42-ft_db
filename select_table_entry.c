/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_table_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:17:57 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 20:11:40 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	select_table_entry(t_table *table, char *key)
{
	t_row	*cur;

	if (!key)
	{
		// key is NULL
		return;
	}
	cur = table->row;
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			printf("%s\n", cur->value);
			return;
		}
		cur = cur->next;
	}
	printf("Key not found\n");
}
