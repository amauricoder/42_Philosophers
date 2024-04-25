/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/25 16:58:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*check_health(void *arg);

int	start_threads(t_data *data)
{
	int	i;
	pthread_t	doctor;
 
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
	pthread_create(&doctor, NULL, &check_health, data);
	pthread_join(doctor, NULL);
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

static void	*check_health(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(data->full_mutex);
		if (data->qt_philo_full == data->philoandfork_qt)
		{
			printf(ORANGE"EVERYBODY IS FULL\n"RESET);
			pthread_mutex_unlock(data->full_mutex);
			break;
		}
		pthread_mutex_unlock(data->full_mutex);
	} 
 	return (NULL);
}
