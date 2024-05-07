/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:09 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/07 11:08:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Convert int to size_t.
*/
size_t	convert_sizet(int number)
{
	size_t	converted;

	converted = number;
	return (converted);
}

int	is_simulation_stoped(t_philo *philo)
{
	pthread_mutex_lock(philo->main->full_mutex);
	if (philo->main->stop_simulation)
	{
		pthread_mutex_unlock(philo->main->full_mutex);	
		return (EXIT_FAILURE);		
	}
	else
	{
		pthread_mutex_unlock(philo->main->full_mutex);	
		return (EXIT_SUCCESS);
	}
}