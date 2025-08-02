#include "philo.h"

void *lonely(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    wait_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    while (!simulation_finished(philo->table))
        usleep(200);
    return(NULL);
}

static void eat(t_philo *philo)
{
    safe_mutex_handle(&philo->fork1->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handle(&philo->fork2->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
    set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
    philo->nbr_meals++;
    write_status(EATING, philo, DEBUG_MODE);
    ft_usleep(philo->table->time_to_eat, philo->table);
    if(philo->table->nbr_limit_meals > 0 &&
        philo->nbr_meals == philo->table->nbr_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    safe_mutex_handle(&philo->fork1->fork, UNLOCK);
    safe_mutex_handle(&philo->fork2->fork, UNLOCK);
}

//avoiding philo eating 2 times in a row
void think(t_philo *philo, bool pre_sim)
{
    long ttt;
    long tte;
    long tts;

    if(!pre_sim)
        write_status(THINKING, philo, DEBUG_MODE);
    if (philo->table->philo_nbr % 2 == 0)
        return ;
    tte = philo->table->time_to_eat;
    tts = philo->table->time_to_sleep;
    ttt = (tte * 2) - tts;
    if (ttt < 0)
        ttt = 0;
    ft_usleep(ttt * 0.42, philo->table);
}

void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
    desynchro(philo);
    while (!simulation_finished(philo->table))
    {
        if(philo->full)
            break;
        eat(philo);
        write_status(SLEEPING, philo, DEBUG_MODE);
        ft_usleep(philo->table->time_to_sleep, philo->table);
        think(philo, false);
    }
    
    return (NULL);
}

void init_simulation(t_table *table)
{
    int i;

    i = 0;
    if(0 == table->nbr_limit_meals)
        return ;
    if(1 == table->philo_nbr)
        safe_thread_handle(&table->philos[0].thread_id, lonely, &table->philos[0], CREATE);
    else
    {
        table->start_simulation_time = gettime(MILISECOND);
        while (i < table->philo_nbr)
        {
            safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
                &table->philos[i], CREATE);
            i++;
        }
    }
    safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE);
    set_bool(&table->table_mutex, &table->threads_ready, true);
    i = 0;
    while(i < table->philo_nbr)
    {
        safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
        i++;
    }
    set_bool(&table->table_mutex, &table->end_simulation, true);
    safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
    printf("%s\n", "ALL PHILOS ARE FULL!");
}