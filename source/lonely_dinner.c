/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/03 13:07:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Treat the case of only 1 philosopher.
 * He will never be able to eat, then he will just pacefully die.
 * @param arg Is casted to t_philo with the structure of the philosophers.
*/
void    *lonely_dinner(void *arg)
{
	size_t current_time;
	t_philo *philo;
	
	philo = (t_philo *)arg;
	current_time = get_time() - philo->main->start_time;
	
	pthread_mutex_lock(philo->left_fork->fork);
	printf("%zu %i has taken a fork\n", current_time, philo->id);
	
	return (NULL);
}