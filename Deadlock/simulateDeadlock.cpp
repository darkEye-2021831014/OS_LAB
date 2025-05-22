#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

// we use two mutex resouse to simulate deadlock
pthread_mutex_t m1, m2;

void *fun1(void *arg);
void *fun2(void *arg);

int main()
{
    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, fun1, NULL);
    pthread_create(&th1, NULL, fun2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}

void *fun1(void *arg)
{
    cout << "Thread 1 Trying To Acquire Resource 1\n";
    pthread_mutex_lock(&m1);
    cout << "Thread 1 Acquired Resource 1\n";
    sleep(1); // simulate deadlock
    cout << "Thread 1 Trying To Acquire Resource 2\n";
    pthread_mutex_lock(&m2);
    cout << "Thread 1 Acquired Resource 2\n";
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
    cout << "Thread 1 Released All Resources\n";
    return NULL;
}
void *fun2(void *arg)
{
    cout << "Thread 2 Trying To Acquire Resource 2\n";
    pthread_mutex_lock(&m2);
    cout << "Thread 2 Acquired Resource 2\n";
    sleep(1); // simulate deadlock
    cout << "Thread 2 Trying To Acquire Resource 1\n";
    pthread_mutex_lock(&m1);
    cout << "Thread 2 Acquired Resource 1\n";
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
    cout << "Thread 2 Released All Resources\n";
    return NULL;
}