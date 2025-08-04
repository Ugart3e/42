#include "philo.h"

void wait_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->threads_ready))
        ;
}

bool all_threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
   bool ret;
   ret = false;
   
   safe_mutex_handle(mutex, LOCK);
   if(*threads == philo_nbr)
    ret = true;
   safe_mutex_handle(mutex, UNLOCK);
   return (ret);
}

void increase_long(t_mtx *mutex, long *value)
{
    safe_mutex_handle(mutex, LOCK);
    (*value)++;
    safe_mutex_handle(mutex, UNLOCK);

}

void desynchro(t_philo *philo)
{
    if (philo->id % 2 == 0)
        return ;
    usleep(100); // o 100
}

void	check_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (!get_bool(&table->philos[i].philo_mutex, &table->philos[i].full))
			return ;
		i++;
	}
	set_bool(&table->table_mutex, &table->end_simulation, true);
	printf("ALL PHILOS ARE FULL!\n");
}
