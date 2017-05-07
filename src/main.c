/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 04:17:47 by jrameau           #+#    #+#             */
/*   Updated: 2017/05/06 19:52:30 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envv) {
	(void)ac;
	(void)av;
	char *input;
	int ret;

	while (1)
	{
		display_prompt(envv);
		get_next_line(0, &input);
		if (input[0] == '\0')
			continue ;
		ret = exec_command(input, envv);
		if (ret == -1)
			break ;
	}
	exit(0);
}