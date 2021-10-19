/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:41:14 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/10/19 17:41:31 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handler(char *err_msg)
{
	printf("[Error] %s\n", err_msg);
	exit(1);
}

int	main(void)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = split_line("cat -e < file1 | echo <file	-n \'\"abcd    \' > file2");
	while (cmd_lst)
	{
		while (*cmd_lst->cmd)
			printf("[%s]\n", *(cmd_lst->cmd++));
		printf("\n");
		cmd_lst = cmd_lst->next;
	}
	return (0);
}
