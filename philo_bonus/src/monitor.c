#include "../include/philo_bonus.h"

bool	did_someone_die(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0);
	if (death == SEM_FAILED)
		return (false);
	sem_close(death);
	return (true);
}

void	announce_dead(void)
{
	sem_open("/death", O_CREAT, 0644, 0);
}

bool	is_philo_dead(t_data *data)
{
	if (get_philo_state(data) != EATING
		&& get_time() - get_time_last_eat(data) > data->die_time)
		return (true);
	return (false);
}

void	*monitor_death(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == false)
	{
		if (did_someone_die())
			return (set_philo_state(data, FINISH), NULL);
		if (is_philo_dead(data))
		{
			sem_wait(data->sem_print);
			if (is_philo_dead(data) && did_someone_die() == false)
			{
				set_philo_state(data, DEAD);
				announce_dead();
				printf("%llu %d %s\n", get_time() - get_time_start(data),
					data->philo.id, DIED);
				sem_post(data->sem_print);
				break ;
			}
			sem_post(data->sem_print);
		}
		usleep(1000);
	}
	return (NULL);
}
