#include <time.h>
#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()
#include <sys/types.h>

using namespace std;

int main()
{
    while (true)
    {
        cout << getpid() << endl;
    }
}