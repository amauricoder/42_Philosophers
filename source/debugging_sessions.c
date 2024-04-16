/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_sessions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/16 15:17:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//https://linuxhint.com/gettimeofday_c_language/
void get_time_test(void)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds %li\n", current_time.tv_sec);
    printf("microseconds %li\n", current_time.tv_usec);
}

void *printf_runningthr()
{
    printf("Thread is running\n");
    usleep(500);
    printf("Ending thread\n");
    return NULL;
}

//------------------------------------------------------------------
//Learning Threads, more information on notes.
/* int i = 0;
	printf("quantity of philo from main => %i\n", philo->philoandfork_qt);
	while (i < philo->philoandfork_qt)
	{
		//printf("i from main => %i\n", i);
		if (pthread_create(philo->threads_arr[i], NULL, &printf_runningthr, NULL) != 0)
			return (1);
		i ++;
	}
	i = 0;
	while (i < philo->philoandfork_qt)
		if (pthread_join(*(philo->threads_arr[i ++]), NULL) != 0)
			return (1);
	 */
//-------------------------------------------------------------------