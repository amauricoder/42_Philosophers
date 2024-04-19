/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 15:48:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    *start_routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	
	
	//funcao dos garfos
	atribute_fork(philo);
	printf("Philosopher ID-> %i\n", philo->id);
	return (NULL);
}

void	atribute_fork(t_philo *philo)
{
	philo->left_fork = &philo->main->mtx_arr[philo->id];
	if (philo->id == 0)
		philo->right_fork = &philo->main->mtx_arr[philo->main->philoandfork_qt - 1];
	else
		philo->right_fork = &philo->main->mtx_arr[philo->id - 1];
}