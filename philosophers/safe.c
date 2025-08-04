/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:17:28 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 21:41:32 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Malloc with its own protection
void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		ft_error("Error with malloc");
	return (ret);
}
/*
This function allows a propper wat to handle mutexes
posible errors giving a message depending on the mutex
error (POSIX) so you can understand where is the problem
*/

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		ft_error("The value specified by mutex is invalid.");
	else if (status == EINVAL && opcode == INIT)
		ft_error("The value specified by attr is invalid.");
	else if (status == EINVAL && opcode == DESTROY)
		ft_error("The value specified by mutex is not a valid mutex");
	else if (status == EDEADLK)
		ft_error("A deadlock can occur if thread blocked waiting for mutex.");
	else if (status == EPERM)
		ft_error("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		ft_error("The process cannot allocate enough memory to another mutex");
	else if (status == EBUSY)
		ft_error("Mutex is locked (EBUSY). Cannot destroy.");
	else
		ft_error("Unknown pthread mutex error.");
}

/* MUTEX SAFE FUNCTIONS
    Function gets which kind of option are you
    choosing by the enum opcode, if error, you get
    status and opcode and you send to handle error
    to get a propper feedback, if everything goes
    propper, it will return 0 so no error message
*/
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		ft_error("Wrong opcode for mutex handle");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		ft_error("No resorces to create new thread");
	else if (status == EPERM)
		ft_error("The caller does not have propper permision");
	else if (status == EINVAL && CREATE == opcode)
		ft_error("The value specified is invalid");
	else if (status == EINVAL && JOIN == opcode || DETACH == opcode)
		ft_error("The value specified by threda isnt joinable");
	else if (ESRCH == status)
		;
}
/*
THREAD SAFE FUNCTIONS
same application than with mutexes
*/

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
	void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		ft_error("Wrong opcode for thread handle");
}
