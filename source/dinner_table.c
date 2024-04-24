/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 17:20:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	has_taken_a_fork(t_philo *philo, size_t current_time);
static void	is_eating(t_philo *philo, size_t current_time);
static void	is_sleeping(t_philo *philo, size_t current_time);
static void	is_thinking(t_philo *philo, size_t current_time);

void	*dinner_routine(void *arg)
{
	t_philo	*philo;
	size_t	current_time;

	current_time = 0;
	philo = (t_philo *)arg;
	preparing_table(philo);
	while (!philo->main->is_someone_dead)
	{
		has_taken_a_fork(philo, current_time);
		is_eating(philo, current_time);
		is_sleeping(philo, current_time);
		is_thinking(philo, current_time);
		if (philo->is_full)
			break ;
	}
	return (NULL);
}

static void	has_taken_a_fork(t_philo *philo, size_t current_time)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Has taken a fork %i\n", current_time,
			philo->id, philo->left_fork->fork_id);
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Has taken a fork %i\n", current_time,
			philo->id, philo->right_fork->fork_id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Has taken a fork %i\n", current_time,
			philo->id, philo->right_fork->fork_id);
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Has taken a fork %i\n", current_time,
			philo->id, philo->left_fork->fork_id);
	}
}

static void	is_eating(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	philo->last_meal_time = current_time;
	printf("%zu %i Is eating\n", current_time, philo->id);
	philo->meals_qt ++;
	usleep(philo->main->eat_timeto);
	if (philo->meals_qt == philo->main->musteat_times)
	{
		philo->is_full ++;
		printf(RED"Philo %i is full!\n"RESET, philo->id);
	}
	pthread_mutex_unlock(philo->left_fork->fork);
	pthread_mutex_unlock(philo->right_fork->fork);
}

static void	is_sleeping(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i Is sleeping\n", current_time, philo->id);
	usleep(philo->main->sleep_timeto);
}

static void	is_thinking(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i Is thinking\n", current_time, philo->id);
}
