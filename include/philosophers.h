/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/16 17:47:03 by aconceic         ###   ########.fr       */
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
typedef struct s_data
{
	int	argc_qt;
	int	philoandfork_qt;
	int	die_timeto;
	int	eat_timeto;
	int	sleep_timeto;
	int	musteat_times;
	pthread_t **threads_arr;
}	t_data;

/**************************************/
/*       MAIN -> source/main.c        */
/**************************************/
//
int			main(int argc, char **argv);

/**************************************/
/*   FT_UTILS -> source/ft_utils.c    */
/**************************************/
//
int			ft_strlen(char *str);
int			ft_strcmp(char *str1, char *str2);
int			ft_atoi(char *number);


/**************************************/
/* INPUT_VALID -> source/input_valid.c */
/**************************************/
//
int			argument_isvalid(int argc, char **argv);
int			is_digit(char **argv);
int			is_null(char **argv);

/**************************************/
/*     error -> source/error.c        */
/**************************************/
//
int			errormsg_and_exit(char *msg, int exit_code);

/**************************************/
/*     frees -> source/fress.c        */
/**************************************/
//
void		free_struct(t_data *data);

/**************************************/
/*INIT VALUES -> source/init_values.c */
/**************************************/
//
void		init_struct(int argc, char **argv, t_data *values);
pthread_t	**alloc_thread(int qt);

/**************************************/
/*   diner -> source/dinner_table.c   */
/**************************************/
//
//void    *eating_philosophers();

/**************************************/
/*                DEBUG               */
/**************************************/
//
void		get_time_test(void);
void 		*printf_runningthr();

#endif