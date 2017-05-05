/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:17:51 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 22:07:47 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	load_table(t_table *table)
{
	FILE	*fp;
	t_row	**cur;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	char	*tok;

	table->row = NULL;
	if (!(fp = fopen(FN, "r")))
		return ;
	cur = &table->row;
	line = NULL;
	linecap = 0;
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		if (!strchr(line, ',') || strchr(line, ',') != strrchr(line, ','))
			return ;
		*strchr(line, '\n') = '\0';
		*cur = (t_row*)malloc(sizeof(**cur));
		(*cur)->key = strdup(strtok(line, ","));
		tok = strtok(NULL, ",");
		(*cur)->value = (tok) ? strdup(tok) : strdup("");
		(*cur)->next = NULL;
		cur = &(*cur)->next;
		free(line);
	}
	fclose(fp);
}
