/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:02:29 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 16:11:04 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	remove_table_entry(t_db *database, char *key)
{
	t_row	**cur;
	t_row	*to_delete;

	cur = &database->row;
	while (*cur && strcmp((*cur)->key, key))
		cur = &(*cur)->next;
	if (!*cur)
	{
		// key not found
		return;
	}
	to_delete = *cur;
	*cur = (*cur)->next;
	free(to_delete);
}
