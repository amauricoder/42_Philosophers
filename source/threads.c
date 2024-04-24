/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 12:50:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].id = i + 1;
		if (pthread_create(data->ph[i].thread, NULL,
				&dinner_routine, &data->ph[i]) != 0)
			return (errormsg_and_exit("Error\nError creating threads",
					EXIT_FAILURE));
		i ++;
	}
	return (EXIT_SUCCESS);
}
