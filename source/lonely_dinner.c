/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/29 16:09:46 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    *lonely_dinner(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    
    printf("lonely dinner from philo %i\n", philo->id);
    return (NULL);
}