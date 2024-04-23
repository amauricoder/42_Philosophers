/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:27:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/23 10:42:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_struct(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		if (pthread_join(*(data)->ph[i].thread, NULL) != 0)
			errormsg_and_exit("Error\nError thread join\n", EXIT_FAILURE);
		free(data->ph[i].thread);
		i ++;
	}
	free(data->all_forks);
	free(data->ph);
}
