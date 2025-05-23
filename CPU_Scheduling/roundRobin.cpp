#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

void printResults(const vector<Process> &processes)
{
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto &p : processes)
    {
        cout << "P" << p.id << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.completion << "\t" << p.turnaround << "\t" << p.waiting << "\n";
    }
}

void roundRobin(vector<Process> processes, int quantum)
{
    cout << "\nRound Robin Scheduling\n";
    queue<int> q;
    int time = 0, n = processes.size(), completed = 0;

    for (auto &p : processes)
    {
        p.remaining = p.burst;
    }

    vector<bool> inQueue(n, false);
    q.push(0);
    inQueue[0] = true;

    while (completed < n)
    {
        if (q.empty())
        {
            time++;
            for (int i = 0; i < n; i++)
            {
                if (!inQueue[i] && processes[i].arrival <= time && processes[i].remaining > 0)
                {
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        auto &p = processes[idx];

        if (p.arrival > time)
        {
            time++;
            q.push(idx);
            continue;
        }

        int t = min(quantum, p.remaining);
        p.remaining -= t;
        time += t;

        for (int i = 0; i < n; i++)
        {
            if (!inQueue[i] && processes[i].arrival <= time && processes[i].remaining > 0)
            {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p.remaining == 0)
        {
            p.completion = time;
            p.turnaround = p.completion - p.arrival;
            p.waiting = p.turnaround - p.burst;
            completed++;
        }
        else
        {
            q.push(idx);
        }
    }

    printResults(processes);
}

int main()
{
    vector<Process> processes = {
        {0, 0, 5, 2},
        {1, 2, 8, 4},
        {2, 1, 3, 1},
        {3, 3, 6, 3}};
    int timeQuantum = 5;
    roundRobin(processes, timeQuantum);
    return 0;
}