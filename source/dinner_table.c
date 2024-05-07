/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/07 14:53:16 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	has_taken_a_fork(t_philo *philo, size_t current_time);
static void	is_eating(t_philo *philo, size_t current_time);
static void	is_sleeping(t_philo *philo, size_t current_time);
static void	is_thinking(t_philo *philo, size_t current_time, int f);

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
	if (philo->id % 2 == 0 || philo->id == 1)
		is_thinking(philo, 10000, 1);
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
		is_thinking(philo, current_time, 0);
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
		even_philo_take_fork(philo, current_time);
	else
		odd_philo_take_fork(philo, current_time);
}

/**
 * @brief Simulates the philosopher eating.
 * Compares if the qt of meals of the philosopher is equal to the quantity of 
 * meals that they need to take. If yes, the philosopher is full.
 * Also checks if the simu is stopped to prevent the simulation to continue.
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
	ft_usleep(philo->main->eat_timeto, philo);
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
	ft_usleep(philo->main->sleep_timeto, philo);
}

/**
 * @brief Simulates the philosopher thinking.
 * Gives time to think if qt of philo is odd. To prevent they from dying with 
 * lower sleep times.
 * Checks if the simulation is stopped to prevent the simulation to continue.
 * @attention If odd - time_to_think = (time_to_eat * 2) - time_to_sleep)
*/
static void	is_thinking(t_philo *philo, size_t current_time, int f)
{
	if (stop_sim(philo))
		return ;
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i is thinking\n", current_time, philo->id);
	if (philo->main->philoandfork_qt % 2 == 0 || f == 1)
	{
		ft_usleep(1000, philo);
	}
	else
	{
		ft_usleep((philo->main->eat_timeto * 2)
			- philo->main->sleep_timeto, philo);
	}
}
