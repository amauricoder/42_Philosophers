/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/15 14:42:20 by aconceic         ###   ########.fr       */
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
# include <pthread.h> // thread_create, 
# include <sys/time.h> // gettimeofday
# include <sys/wait.h> // wait, waitpid, waitid
# include <fcntl.h> //sem_open
# include <sys/stat.h> //sem_open
# include <semaphore.h> //sem_open

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
t_data		*init_struct(int argc, char **argv);

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
void		errormsg_and_exit(char *msg);

/**************************************/
/*     frees -> source/fress.c        */
/**************************************/
//
void		free_struct(t_data *data);

#endif