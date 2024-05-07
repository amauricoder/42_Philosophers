/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:27:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/06 10:55:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Destroy the mutexes
*/
void	destroy_mutex(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->philoandfork_qt)
	{
		pthread_mutex_destroy(data->all_forks[i].fork);
		i ++;
	}
	pthread_mutex_destroy(data->table_mutex);
	pthread_mutex_destroy(data->full_mutex);
}

/**
 * @brief Free the allocated memory
*/
void	free_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		if (pthread_join(*(data)->ph[i].thread, NULL) != 0)
			errormsg_and_exit("Error\nError thread join\n", EXIT_FAILURE);
		free(data->ph[i].thread);
		i ++;
	}
	i = 0;
	while (i < data->philoandfork_qt)
	{
		free(data->all_forks[i].fork);
		i ++;
	}
	free(data->full_mutex);
	free(data->table_mutex);
	free(data->all_forks);
	free(data->ph);
}
