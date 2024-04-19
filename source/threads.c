/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 14:20:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    *start_routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	
	printf("Philosopher ID-> %i\n", philo->id);
	return (NULL);
}