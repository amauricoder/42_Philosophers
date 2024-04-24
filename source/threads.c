/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 18:13:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	//if philo == 1
		//TODO
	//else
	while (i < data->philoandfork_qt)
	{
		data->ph[i].id = i + 1;
		if (pthread_create(data->ph[i].thread, NULL,
				&dinner_routine, &data->ph[i]) != 0)
			return (errormsg_and_exit("Error\nError creating threads\n",
					EXIT_FAILURE));
		i ++;
	}
	pthread_mutex_lock(data->table_mutex);
	data->table_is_ready ++;
	pthread_mutex_unlock(data->table_mutex);
	return (EXIT_SUCCESS);
}
void				preparing_table(t_philo *philo)
{
	int i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(philo->main->table_mutex);
		if (philo->main->table_is_ready)
		{
			pthread_mutex_unlock(philo->main->table_mutex);
			break;
		}
		pthread_mutex_unlock(philo->main->table_mutex);
		i ++;	
	}
}
//start "doctor thread and put it into the philosopher_health_check function"


