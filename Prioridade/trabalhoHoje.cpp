#include <time.h>
#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/time.h> // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <sched.h> // sched_setaffinity

//using std::cout;
using namespace std;

void carga(int k)
{
    float f = 0.999999;
    for (int i = 0; i < k; i++)
    {
        f = f * f * f * f * f;
        f = 1.56;
        for (int j = 0; j < k; j++)
        {
            f = sin(f) * sin(f) * f * f * f;
        }
    }
}

int main()
{
    cpu_set_t mask;
    int status;

    pid_t pid1,pid;
    pid1 = fork();
    

    switch (pid1)
    {
    case -1:
        cout << "erro" << endl;
        while (true)
            ;
        break;

    case 0:
        cout << "processo filho" << endl;
        CPU_ZERO(&mask);
        CPU_SET(5, &mask);
        pid=getpid();
        status = sched_setaffinity(pid, sizeof(mask), &mask);
        while (true)
            ;
        break;

    default:
        cout << "processo pai" << endl;
        CPU_ZERO(&mask);
        CPU_SET(7, &mask);
        pid=getpid();
        status = sched_setaffinity(pid, sizeof(mask), &mask);
        while (true)
            ;
    }
}