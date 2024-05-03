/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/03 18:58:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	has_taken_a_fork(t_philo *philo, size_t current_time);
static void	is_eating(t_philo *philo, size_t current_time);
static void	is_sleeping(t_philo *philo, size_t current_time);
static void	is_thinking(t_philo *philo, size_t current_time);
static int	stop_sim(t_philo *philo);

/**
 * @brief Simulation of the dinner of the philosophers.
 * The philosopher will take the forks, eat, sleep and think.
*/
void	*dinner_routine(void *arg)
{
	t_philo	*philo;
	size_t	current_time;

	current_time = 0;
	philo = (t_philo *)arg;
	preparing_table(philo);
	if (philo->id % 2 == 0)
		ft_usleep(10000);
	while (1)
	{
		pthread_mutex_lock(philo->main->full_mutex);
		if (philo->main->qt_philo_full == philo->main->philoandfork_qt
			|| philo->main->stop_simulation == 1)
		{
			pthread_mutex_unlock(philo->main->full_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->main->full_mutex);
		has_taken_a_fork(philo, current_time);
		is_eating(philo, current_time);
		is_sleeping(philo, current_time);
		is_thinking(philo, current_time);
	}
	return (NULL);
}

/**
 * @brief Simulates the philosopher taking a fork.
 * Checks constantly if the simulation is stopped to prevent
 * the simulation to continue rouling when it should be stopped.
 * @param philo Struct with the philosopher data -> leads to main struct too.
 * @param current_time Current time of the simulation.
*/
static void	has_taken_a_fork(t_philo *philo, size_t current_time)
{
	if (stop_sim(philo))
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		if (stop_sim(philo))
			return ;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		if (stop_sim(philo))
			return ;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		if (stop_sim(philo))
			return ;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		if (stop_sim(philo))
			return ;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
	}
}

/**
 * @brief Simulates the philosopher eating.
 * Compares if the qt of meals of the philosopher is equal to the quantity of 
 * meals that they need to take. If yes, the philosopher is full.
 * Also checks if the simulation is stopped to prevent the simulation to continue.
*/
static void	is_eating(t_philo *philo, size_t current_time)
{
	if (stop_sim(philo))
		return ;
	current_time = get_time() - philo->main->start_time;
	pthread_mutex_lock(philo->main->full_mutex);
	philo->last_meal_time = current_time;
	pthread_mutex_unlock(philo->main->full_mutex);
	printf("%zu %i is eating\n", current_time, philo->id);
	philo->meals_qt ++;
	ft_usleep(philo->main->eat_timeto);
	pthread_mutex_lock(philo->main->full_mutex);
	if (philo->meals_qt == philo->main->musteat_times)
	{
		philo->is_full ++;
		philo->main->qt_philo_full ++;
	}
	pthread_mutex_unlock(philo->main->full_mutex);
	pthread_mutex_unlock(philo->left_fork->fork);
	pthread_mutex_unlock(philo->right_fork->fork);
}

/**
 * @brief Simulates the philosopher sleeping.
 * Checks if the simulation is stopped to prevent the simulation to continue.
*/
static void	is_sleeping(t_philo *philo, size_t current_time)
{
	if (stop_sim(philo))
		return ;
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i is sleeping\n", current_time, philo->id);
	ft_usleep(philo->main->sleep_timeto);
}

/**
 * @brief Simulates the philosopher thinking.
 * Checks if the simulation is stopped to prevent the simulation to continue.
*/
static void	is_thinking(t_philo *philo, size_t current_time)
{
	if (stop_sim(philo))
		return ;
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i is thinking\n", current_time, philo->id);
	ft_usleep(1000);
}

/**
 * @brief Checks if the simulation is stopped.
 * @return 1 if the simulation is stopped, 0 if not.
*/
static int	stop_sim(t_philo *philo)
{
	pthread_mutex_lock(philo->main->full_mutex);
	if (philo->main->stop_simulation)
	{
		pthread_mutex_unlock(philo->main->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->main->full_mutex);
	return (0);
}
