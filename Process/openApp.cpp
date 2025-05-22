#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    cout << "Parent Process Running\n";
    pid_t pid = fork(); // create a child process
    if (pid < 0)
    {
        cout << "Failed To Create Process. Error!\n";
        return 1;
    }
    else if (pid == 0)
    {
        // This Is Child Process Code
        cout << "I Am Child Process With Pid: " << getpid() << endl;
        cout << "My Parent's Pid: " << getppid() << endl;
        cout << "Enter An Exact Application Name To Open It: ";
        string appName;
        cin >> appName;
        string command = "open -a " + appName;
        execl("/bin/bash", "bash", "-c", command.c_str(), NULL);
    }
    else
    {
        // This is parent process code
        wait(NULL); // wait for child to finish to avoid orphan or zoombie process
        cout << "I Am Parent Process With pid: " << getpid() << endl;
        cout << "My Child's Pid: " << pid << endl;
    }
    // code here is common in both Parent and Child Process
    cout << "Common Statement Executed By Process PID: " << getpid() << endl;
    return 0;
}