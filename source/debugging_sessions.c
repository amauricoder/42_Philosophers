/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_sessions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/17 16:30:49 by aconceic         ###   ########.fr       */
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

void get_time_usleep(void)
{
	struct timeval 	start_time;
	struct timeval 	end_time;
	long			request_sleep_time;
	long			actual_sleep_time;

	request_sleep_time = 200 * 1000;
	gettimeofday(&start_time, NULL);
	usleep(request_sleep_time);
	gettimeofday(&end_time, NULL);
	actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000
		+ (end_time.tv_usec + end_time.tv_usec);
	
	printf("Requested sleep time %ld\n", request_sleep_time);
	printf("Actual sleep time %ld\n", actual_sleep_time);
}
void *printf_runningthr(void *arg)
{
 /*    t_data	*philo;
	philo = (t_data *)arg;
	pthread_mutex_lock(mtx);
	printf("%d\n", philo->n);
	philo->n++;
	pthread_mutex_unlock(mtx); */
	printf("Thread is running\n");
    usleep(500);
    printf("Ending thread\n");
	(void)arg;
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