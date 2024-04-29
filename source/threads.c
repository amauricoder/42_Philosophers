/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/29 12:33:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*check_health(void *arg);
static size_t convert_sizet(int number);

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
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		if (i == data->philoandfork_qt)
			i = 0;
		pthread_mutex_lock(data->full_mutex);
		if (data->qt_philo_full == data->philoandfork_qt)
		{
			pthread_mutex_unlock(data->full_mutex);
			break;
		}
		if ((get_time() - data->start_time) - data->ph[i].last_meal_time > 
			(convert_sizet(data->die_timeto) / 1000) && !data->ph[i].is_full)
		{
			data->stop_simulation ++;
			printf(RED"%zu %i died \n"RESET, get_time() - data->start_time, data->ph[i].id);
			pthread_mutex_unlock(data->full_mutex);
			break;
		}
		pthread_mutex_unlock(data->full_mutex);
		i ++;
	} 
 	return (NULL);
}

static size_t convert_sizet(int number)
{
	size_t converted;

	converted = number;
	return (converted);
}


/* 
if (get_time() - philo->main->start_time - philo->last_meal_time > 
		(convert_sizet(philo->main->die_timeto) / 1000))
	{
		printf("convert size_t %zu\n", convert_sizet(philo->main->die_timeto) / 1000);
		printf("get_time() - philo->last_meal_time %zu\n", get_time() - philo->last_meal_time);
		printf("Dead\n");
	} 
*/



/* 
pthread_mutex_lock(data->full_mutex);
if (data->qt_philo_full == data->philoandfork_qt)
{
	printf(ORANGE"EVERYBODY IS FULL\n"RESET);
	pthread_mutex_unlock(data->full_mutex);
	break;
}
pthread_mutex_unlock(data->full_mutex);
*/