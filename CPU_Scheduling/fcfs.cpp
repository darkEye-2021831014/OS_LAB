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

void fcfs(vector<Process> processes)
{
    cout << "\nFCFS Scheduling\n";
    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arrival < b.arrival; });

    int time = 0;
    for (auto &p : processes)
    {
        if (time < p.arrival)
            time = p.arrival;
        time += p.burst;
        p.completion = time;
        p.turnaround = p.completion - p.arrival;
        p.waiting = p.turnaround - p.burst;
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
    fcfs(processes);
    return 0;
}