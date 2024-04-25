

Eat
Think
Sleep
>The philosopher can only do one per time.

Forks: There are as many forks as philosophers.
>One fork per philosopher.

The philosopher needs to eat with 2 forks, this means that he will take a fork of another philosopher. So, the philosopher that is just on the side can't eat while this is eating.

When a philo finish eating -> but the fork on the table and start sleeping.

Once awake, they start thinking again.

The simulation stops when a philosopher dies of starvation.

>every philosopher needs to eat and should never starve.
>philosopher dont speak with each other.
>philosopher dont know if another philosopher is about to die.
>Philosophers should avoid dying!

ARGUMENTS -> 
nb_philo(int) 
time_todie(int) 
time_toeat(int) 
time_tosleep(int) 
number_of_times_each_philosopher_must_eat(int)



To initialize a thread.

phthread_t -> declare this variable to hold the value of a thread.
pthread_create(pointer to the phthread_t, NULL, pointer to function, NULL);
pthread_join(varaible to thread, ptr that get the result of the thread) -> wait but for tthreads
int pthread_deteach(pthread_t specific thread) -> "Hey, once this particular thread finishes its job, you can immediately free up any resources it used."

## Difference between threads and processes
threads are sharing memories.
processes are instantes on the code that has his own memory and stuff.

## Race conditions


## Mutex
pthread_mutex_t nameofmutex;

pthread_mutex_init(addres_to_mutex, attribute); ->needs to destroy at the end,
**inside the function that the mutex will be used**
pthread_mutex_lock(&mutex);
pthread_mutex_unlock(&mutex);

pthread_mutex_destroy(&mutex);


## SOURCES

https://medium.com/@jalal92/the-dining-philosophers-7157cc05315

https://nafuka11.github.io/philosophers-visualizer/