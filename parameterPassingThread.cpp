#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *fun(void *arg);

int main()
{
    int n;
    cout << "Using Thread To Combine Two Half Sum.\n";
    cout << "Enter Array Size N: ";
    cin >> n;
    cout << "Enter Array Elements:\n";
    int a[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int n1 = n / 2;
    int a1[n1 + 1], a2[(n - n1) + 1];
    a1[0] = n1 + 1;
    for (int i = 0; i < n1; i++)
        a1[i + 1] = a[i];

    a2[0] = (n - n1) + 1;
    for (int i = n1; i < n; i++)
        a2[(i - n1) + 1] = a[i];

    pthread_t th1, th2;
    pthread_create(&th1, NULL, fun, (void *)a1);
    pthread_create(&th2, NULL, fun, (void *)a2);

    void *r1, *r2;
    int s1, s2;
    pthread_join(th1, &r1);
    pthread_join(th2, &r2);
    s1 = *(int *)r1, s2 = *(int *)r2;

    int s = s1 + s2;
    cout << "Sum of first half: " << s1 << endl;
    cout << "Sum of second half: " << s2 << endl;
    cout << "Total Sum: " << s << endl;

    return 0;
}

void *fun(void *arg)
{
    int *x = (int *)arg;
    int n = x[0];
    int *sum = (int *)malloc(sizeof(int));
    for (int i = 1; i < n; i++)
    {
        *sum += x[i];
    }
    pthread_exit((void *)sum);
    return NULL;
}