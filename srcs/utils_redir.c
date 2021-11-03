/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:10:00 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/11/03 16:56:01 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirect	*create_redir(char *line)
{
	t_redirect	*new;

	new = (t_redirect *)malloc(sizeof(t_redirect));
	if (!new)
		return (NULL);
	if (ft_strncmp(line, "<<", 2) == 0)
	{
		new->type = REDIRECT_INPUT_DOUBLE;
		line += 2;
	}
	else if (ft_strncmp(line, ">>", 2) == 0)
	{
		new->type = REDIRECT_OUTPUT_DOUBLE;
		line += 2;
	}
	else if (*line == '<')
	{
		new->type = REDIRECT_INPUT_SINGLE;
		line++;
	}
	else if (*line == '>')
	{
		new->type = REDIRECT_OUTPUT_DOUBLE;
		line++;
	}
	while (ft_isspace(*line))
		line++;
	new->file = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void	redir_add_back(t_redirect **lst, t_redirect *new)
{
	t_redirect	*p;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}
