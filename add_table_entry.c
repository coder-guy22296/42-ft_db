/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_table_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:52:07 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/04 16:10:01 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	t_row  *row_new(void const *key, size_t key_size, void const *content,
							size_t content_size)
{
    t_row *node;

    if (!(node = (t_row *)ft_memalloc(sizeof(t_row))))
        return (NULL);
    if (key && (node->key = ft_memalloc(key_size)))
    {
        node->key_size = key_size;
        ft_memcpy(node->key, key, key_size);
    }
    else
        return (NULL);
    if (content)
    {
        node->content_size = content_size;
        if (!(node->content = ft_memalloc(content_size)))
            return (NULL);
        ft_memcpy(node->content, content, content_size);
    }
    else
    {
        node->content_size = 0;
        node->content = NULL;
    }
    node->next = NULL;
    return (node);
}

void add_table_entry(t_db *database, char *key, char *value)
{
	t_row *new_node;
	
	new_node = row_new(key, strlen(key), value, strlen(value));
	new_node->next = database->row;
	database->row = new_node;
}
