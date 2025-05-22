#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t res;
pthread_mutex_t rc_mtx;

int rc = 0;
int info = 0;

void *reader(void *arg)
{
    int id = *(int *)arg;
    while (true)
    {
        pthread_mutex_lock(&rc_mtx);
        rc++;
        if (rc == 1)
            pthread_mutex_lock(&res);
        pthread_mutex_unlock(&rc_mtx);

        cout << "Reader " << id << " reads " << info << endl;
        sleep(1);

        pthread_mutex_lock(&rc_mtx);
        rc--;
        if (rc == 0)
            pthread_mutex_unlock(&res);
        pthread_mutex_unlock(&rc_mtx);

        sleep(1);
    }
    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;
    while (true)
    {
        pthread_mutex_lock(&res);
        info++;
        cout << "Writer " << id << " writes " << info << endl;
        sleep(1);
        pthread_mutex_unlock(&res);
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&res, NULL);
    pthread_mutex_init(&rc_mtx, NULL);

    int R = 3, W = 2;
    pthread_t readers[R], writers[W];
    int ids[max(R, W)];

    for (int i = 0; i < R; ++i)
    {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    for (int i = 0; i < W; ++i)
    {
        ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    for (int i = 0; i < R; ++i)
        pthread_join(readers[i], NULL);
    for (int i = 0; i < W; ++i)
        pthread_join(writers[i], NULL);

    return 0;
}
