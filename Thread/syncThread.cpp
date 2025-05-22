#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *fun1(void *arg);
void *fun2(void *arg);

pthread_mutex_t m;

int main()
{
    pthread_mutex_init(&m, NULL);

    pthread_t th1, th2;
    pthread_create(&th1, NULL, fun1, NULL);
    pthread_create(&th2, NULL, fun2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}

void *fun1(void *arg)
{
    pthread_mutex_lock(&m);
    cout << "Inside Thread 1\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 1: " << i << endl;
        sleep(1);
    }
    pthread_mutex_unlock(&m);
    return NULL;
}

void *fun2(void *arg)
{
    pthread_mutex_lock(&m);
    cout << "Inside Thread 2\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 2: " << i << endl;
        sleep(1);
    }
    pthread_mutex_unlock(&m);
    return NULL;
}