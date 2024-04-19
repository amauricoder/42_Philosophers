/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 15:42:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/**************************************/
/*             External Libs          */
/**************************************/
//
# include <stdlib.h> //malloc
# include <sys/types.h> //fork
# include <unistd.h> //write, fork, usleep
# include <stdio.h> //ft_printf
# include <string.h> //memset
# include <sys/time.h> // gettimeofday
# include <sys/wait.h> // wait, waitpid, waitid
# include <fcntl.h> //sem_open
# include <sys/stat.h> //sem_open
# include <semaphore.h> //sem_open
# include <pthread.h> // thread_create

/**************************************/
/*             Structs                */
/**************************************/
typedef	struct s_philo
{
	int	id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	struct s_data	*main;
}	t_philo;

//main struct
typedef struct s_data
{
	int				argc_qt;
	int				philoandfork_qt;
	int				die_timeto;
	int				eat_timeto;
	int				sleep_timeto;
	int				musteat_times;
	pthread_t		*thr_arr;
	pthread_mutex_t	*mtx_arr;
	t_philo			*ph;
}	t_data;

/**************************************/
/*       MAIN -> source/main.c        */
/**************************************/
//
int					main(int argc, char **argv);

/**************************************/
/*   FT_UTILS -> source/ft_utils.c    */
/**************************************/
//
int					ft_strlen(char *str);
int					ft_strcmp(char *str1, char *str2);
int					ft_atoi(char *number);
__uint64_t					get_time();

/**************************************/
/* INPUT_VALID -> source/input_valid.c */
/**************************************/
//
int					argument_isvalid(int argc, char **argv);
int					is_digit(char **argv);
int					is_null(char **argv);

/**************************************/
/*     error -> source/error.c        */
/**************************************/
//
int					errormsg_and_exit(char *msg, int exit_code);

/**************************************/
/*     frees -> source/fress.c        */
/**************************************/
//
void				free_struct(t_data *data);

/**************************************/
/*INIT VALUES -> source/init_values.c */
/**************************************/
//
void				init_data(int argc, char **argv, t_data *values);
void    			init_threads(t_data *data);
pthread_t			*alloc_thread(int qt);
pthread_mutex_t		*alloc_mutex(int qt);
void				init_mutex(t_data *data);

/**************************************/
/*   diner -> source/dinner_table.c   */
/**************************************/
//
//void    			*eating_philosophers();
/**************************************/
/*   threads -> source/threads.c      */
/**************************************/
//
void				*start_routine(void *arg);
void				atribute_fork(t_philo *philo);
/**************************************/
/*                DEBUG               */
/**************************************/
//
void				get_time_test(void);
void 				*printf_runningthr(void *arg);
void				get_time_usleep(void);

#endif