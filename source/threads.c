/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/06 11:01:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void		*check_health(void *arg);
static int		create_threads(t_data *data, int i, void *(*function)(void *));
static int		is_someone_dead(t_data *data, int i);

/**
 * @brief Start the threads for the philosophers and the doctor.
 * If there is only one philosopher, it will start the lonely_dinner function.
 * If there is more than one philo, it will start the dinner_routine function.
 * Also treat syncronization of the threads.
*/
int	start_threads(t_data *data)
{
	int			i;
	pthread_t	doctor;

	i = 0;
	if (data->philoandfork_qt == 1)
	{
		create_threads(data, i, lonely_dinner);
		pthread_create(&doctor, NULL, &check_health, data);
		pthread_join(doctor, NULL);
		return (EXIT_SUCCESS);
	}
	while (i < data->philoandfork_qt)
		create_threads(data, i ++, dinner_routine);
	pthread_mutex_lock(data->table_mutex);
	data->table_is_ready ++;
	pthread_mutex_unlock(data->table_mutex);
	pthread_create(&doctor, NULL, &check_health, data);
	pthread_detach(doctor);
	return (EXIT_SUCCESS);
}

/**
 * @brief Function responsable to lock the "table" 
 * until all philosophers are ready.
*/
void	preparing_table(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->main->table_mutex);
		if (philo->main->table_is_ready)
		{
			pthread_mutex_unlock(philo->main->table_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->main->table_mutex);
	}
}

/**
 * @brief Function to check if the philosopher is dead or 
 * if all philosophers are full.
*/
static void	*check_health(void *arg)
{
	t_data	*data;
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
			break ;
		}
		if (is_someone_dead(data, i))
			break ;
		pthread_mutex_unlock(data->full_mutex);
		i ++;
	}
	return (NULL);
}

/**
 * @brief Create the threads for the philosophers.
 * @param void *(*function)(void *) Function to be executed by the thread.
*/
static int	create_threads(t_data *data, int i, void *(*function)(void *))
{
	data->ph[i].id = i + 1;
	if (pthread_create(data->ph[i].thread, NULL, function, &data->ph[i]) != 0)
		return (errormsg_and_exit("Error\n Error creating threads\n",
				EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

/**
 * @brief hecks if a philo has exceeded the time limit since their last meal
 * and if they are not full. If both conditions are met, someone is dead.
 * @return Boolean. SUCCESS (0) for no deads and FAILURE(1) for deads.
*/
static int	is_someone_dead(t_data *data, int i)
{
	if ((get_time() - data->start_time) - data->ph[i].last_meal_time
		>= (convert_sizet(data->die_timeto) / 1000) && !data->ph[i].is_full)
	{
		data->stop_simulation ++;
		printf(RED"%zu %i died \n"RESET, get_time()
			- data->start_time, data->ph[i].id);
		pthread_mutex_unlock(data->full_mutex);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
