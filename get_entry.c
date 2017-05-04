/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:17:57 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 16:19:02 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*get_table_entry(t_db *database, char *key)
{
	t_row	*cur;

	cur = database->row;
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
			return cur->value;
		cur = cur->next;
	}
	// key not found
	return NULL;
}
