/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:48 by aconceic         ###   ########.fr       */
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
	while (1)
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
		printf("%zu %i Has taken the fork %i\n", current_time,
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
		printf("%zu %i Has taken the fork %i\n", current_time,
			philo->id, philo->left_fork->fork_id);
	}
}

static void	is_eating(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i Is eating\n", current_time, philo->id);
	philo->meals_qt ++;
	usleep(philo->main->eat_timeto);
	pthread_mutex_unlock(philo->left_fork->fork);
	pthread_mutex_unlock(philo->right_fork->fork);
	if (philo->main->musteat_times > 0
		&& philo->meals_qt == philo->main->musteat_times)
	{
		philo->is_full ++;
		printf(RED"Philo %i is full!\n"RESET, philo->id);
	}
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
