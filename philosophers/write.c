#include "philo.h"

static void debug_status(t_philo_state status, t_philo *philo, long elapsed)
{
    if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
        printf("%-6ld %d Has taken fork1\n", elapsed, philo->id);
    else if(TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
        printf("%-6ld %d Has taken fork2\n", elapsed, philo->id);
    else if(EATING == status && !simulation_finished(philo->table))
        printf("%-6ld %d Is eating\n", elapsed, philo->id);
    else if(SLEEPING == status && !simulation_finished(philo->table))
        printf("%-6ld %d Is sleeping\n", elapsed, philo->id);
    else if(THINKING == status && !simulation_finished(philo->table))
        printf("%-6ld %d Is thinking\n", elapsed, philo->id);
    else if(DIED == status && !simulation_finished(philo->table))
        printf("%-6ld %d died\n", elapsed, philo->id);
}

void write_status(t_philo_state status, t_philo *philo, bool debug)
{
    long elapsed;

    elapsed = gettime(MILISECOND) - philo->table->start_simulation_time;
    if(philo->full)
        return ;
    safe_mutex_handle(&philo->table->write_mutex, LOCK);
    if(debug)
        debug_status(status, philo, elapsed);
    else
    {
        if (TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status
            && !simulation_finished(philo->table))
            printf("%-6ld %d Has taken a fork\n", elapsed, philo->id);
        else if(EATING == status && !simulation_finished(philo->table))
            printf("%-6ld %d Is eating\n", elapsed, philo->id);
        else if(SLEEPING == status && !simulation_finished(philo->table))
            printf("%-6ld %d Is sleeping\n", elapsed, philo->id);
        else if(THINKING == status && !simulation_finished(philo->table))
            printf("%-6ld %d Is thinking\n", elapsed, philo->id);
        else if(DIED == status && !simulation_finished(philo->table))
            printf("%-6ld %d died\n", elapsed, philo->id);
    }
    safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
