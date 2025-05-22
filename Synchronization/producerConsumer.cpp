#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;
#define BUFFER_SIZE 5

queue<int> buffer;
pthread_mutex_t m;
sem_t emptySlots, fullSlots;

void *producer(void *arg)
{
    int item = 0;
    while (true)
    {
        sleep(1);
        sem_wait(&emptySlots);
        pthread_mutex_lock(&m);

        buffer.push(++item);
        cout << "Produced: " << item << "\n";

        pthread_mutex_unlock(&m);
        sem_post(&fullSlots);
    }
    return NULL;
}

void *consumer(void *arg)
{
    while (true)
    {
        sleep(2);
        sem_wait(&fullSlots);
        pthread_mutex_lock(&m);

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << "\n";

        pthread_mutex_unlock(&m);
        sem_post(&emptySlots);
    }
    return NULL;
}

int main()
{
    pthread_t proThread, conThread;

    pthread_mutex_init(&m, NULL);
    sem_init(&emptySlots, 0, BUFFER_SIZE); // BUFFER_SIZE empty slots initially
    sem_init(&fullSlots, 0, 0);            // 0 full slots initially

    pthread_create(&proThread, NULL, producer, NULL);
    pthread_create(&conThread, NULL, consumer, NULL);

    pthread_join(proThread, NULL);
    pthread_join(conThread, NULL);
    return 0;
}
