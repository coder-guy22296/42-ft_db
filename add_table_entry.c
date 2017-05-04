/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_table_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:52:07 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/04 16:51:44 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "string.h"

static	t_row  *row_new(char const *key, char const *value)
{
    t_row *node;

    if (!(node = (t_row *)calloc(1, sizeof(t_row))))
        return (NULL);
    if (key)
        node->key = strdup(key);
    else
        return (NULL);
    if (value)
        node->value = strdup(value);
    else
        node->value = NULL;
    node->next = NULL;
    return (node);
}

void add_table_entry(t_db *database, char *key, char *value)
{
	t_row *new_node;
	
	new_node = row_new(key, value);
	new_node->next = database->row;
	database->row = new_node;
}
