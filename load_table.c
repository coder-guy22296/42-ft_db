/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:17:51 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 21:19:13 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	load_table(t_table *table)
{
	FILE	*fp;
	t_row	**cur;
	char	*line;
	ssize_t	linelen;
	char	*tok;

	table->row = NULL;
	if (!(fp = fopen(FN, "r")))
		return;
	cur = &table->row;
	line = NULL;
	while ((linelen = getline(&line, NULL, fp)) > 0)
	{
		if (!strchr(line, ',') || strchr(line, ',') != strrchr(line, ','))
			return;
		*strchr(line, '\n') = '\0';
		*cur = (t_row*)malloc(sizeof(**cur));
		(*cur)->key = strdup(strtok(line, ","));
		(*cur)->value = (tok = strtok(NULL, ",")) ? strdup(tok) : strdup("");
		(*cur)->next = NULL;
		cur = &(*cur)->next;
		free(line);
	}
	fclose(fp);
}
