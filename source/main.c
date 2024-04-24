/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 12:33:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//number_of_philosophers[1] time_to_die[2] time_to_eat[3] time_to_sleep[4]
//[number_of_times_each_philosopher_must_eat[5]
//./philo 5 200 50 50 5
//I need to receive miliseconds
//usleep() suspend execution with microseconds
//need to convert miliseconds to microseconds
int	main(int argc, char **argv)
{
	t_data		d;

	memset(&d, 0, sizeof(t_data));
	if (argument_isvalid(argc, argv) != 0)
		return (errormsg_and_exit("Error\nInvalid Arguments", EXIT_FAILURE));
	init_data(argc, argv, &d);
	if (attribute_forks(&d) != 0)
		return (errormsg_and_exit("Error\nInvalid Mutex", EXIT_FAILURE));
	if (start_threads(&d) != 0)
		return (errormsg_and_exit("Error\nInvalid Thread", EXIT_FAILURE));
	//-----------------------------------------------//
	
	//-----------------------------------------------//
	//all philos are full or a philo is dead
	free_struct(&d);
}

//int gettimeofday ( struct timeval *tp ,  struct timezone *tz );

//timestamp_in_ms X has taken a fork
//timestamp_in_ms X is eating
//timestamp_in_ms X is sleeping
//timestamp_in_ms X is thinking
//timestamp_in_ms X died