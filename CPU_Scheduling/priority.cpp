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

void priorityScheduling(vector<Process> processes)
{
    cout << "\nPriority Scheduling\n";
    int time = 0, completed = 0;
    int n = processes.size();
    vector<Process> result;

    while (completed < n)
    {
        vector<Process> ready;
        for (auto &p : processes)
        {
            if (p.arrival <= time && p.completion == 0)
                ready.push_back(p);
        }
        if (ready.empty())
        {
            time++;
            continue;
        }

        auto highPrio = *min_element(ready.begin(), ready.end(), [](Process a, Process b)
                                     { return a.priority < b.priority; });

        for (auto &p : processes)
        {
            if (p.id == highPrio.id)
            {
                if (time < p.arrival)
                    time = p.arrival;
                time += p.burst;
                p.completion = time;
                p.turnaround = p.completion - p.arrival;
                p.waiting = p.turnaround - p.burst;
                result.push_back(p);
                p.burst = -1;
                completed++;
                break;
            }
        }
    }
    printResults(result);
}

int main()
{
    vector<Process> processes = {
        {0, 0, 5, 2},
        {1, 2, 8, 4},
        {2, 1, 3, 1},
        {3, 3, 6, 3}};
    priorityScheduling(processes);
    return 0;
}