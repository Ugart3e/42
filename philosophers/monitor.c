#include "philo.h"

static bool philo_died(t_philo *philo)
{
    long elapsed;
    long ttd;

    if(get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    elapsed = gettime(MILISECOND) - get_long(&philo->philo_mutex, &philo->last_time_meal);
    ttd = philo->table->time_to_die / 1e3;
    if(elapsed > ttd)
        return (true);
    return (false);
}

void *monitor_dinner(void *data)
{
    int i;
    t_table *table;
    table = (t_table *)data;
    while (!all_threads_running(&table->table_mutex,&table->threads_running_nbr, table->philo_nbr))
        ;
    while (!simulation_finished(table))
    {
        i = 0;
        while (i < table->philo_nbr && !simulation_finished(table))
        {
            if(philo_died(table->philos + i))
            {
                write_status(DIED, table->philos + i, DEBUG_MODE);
                set_bool(&table->table_mutex, &table->end_simulation, true);
            }
            i++;
        }
    }
    
    return (NULL);
}