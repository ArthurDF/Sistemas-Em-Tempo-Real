#include <time.h>
#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/time.h> // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <sched.h>  // sched_setaffinity
#include <signal.h> // definição dos sinais de interrupções
#include <bits/stdc++.h>
//using std::cout;
using namespace std;

int main()
{
    pid_t numeroDoProcesso;
    cpu_set_t mask;
    int cpu, status, acao, PIM;
    cout << getpid() << endl;
    system("ps -ef");
    while (true)
    {
        cout << endl
             << "digite a ação desejada" << endl
             << "0 - Alocar CPU" << endl
             << "1 - Filtrar Processos" << endl
             << "2 - pausar/continuar ou matar um processo" << endl
             << "3 - mudar a prioridade de um processo" << endl
             << "4 - imprimir o monitor de sistema" << endl
             << "5 - fechar o monitor" << endl
             << "Ação desejada:";
        cin >> acao;

        if (acao == 0)
        {
            cout << "Alocar CPU" << endl;
            cout << "digite o numero do pŕocesso desejado" << endl;
            cin >> numeroDoProcesso;
            cout << "digite CPU a ser alocada" << endl;
            cin >> cpu;
            CPU_ZERO(&mask);
            CPU_SET(cpu, &mask);
            status = sched_setaffinity(numeroDoProcesso, sizeof(mask), &mask);
        }
        if (acao == 1)
        {
            cout << "Filtrar" << endl;
            string filtro;
            cin >> filtro;
            string sistema = "ps -ef | grep " + filtro;
            system(sistema.c_str());
            /*cout << "digite o numero do pŕocesso desejado" << endl;
            cin >> numeroDoProcesso;*/
            //string sistema="ps -ef | grep "
            //system("ps -ef | grep apache");
        }
        if (acao == 2)
        {
            cout << "0 - Pausa Processo" << endl
                 << "1 - Mata Processo" << endl
                 << "2 - Continua Processo" << endl
                 << "Ação desejada:";
            cin >> PIM;
            if (PIM == 0)
            {
                cout << "digite o numero do processo a ser pausado desejado:";
                cin >> numeroDoProcesso;
                kill(numeroDoProcesso, SIGTSTP);
            }
            else if (PIM == 1)
            {
                cout << "digite o numero do processo a ser morto" << endl;
                cin >> numeroDoProcesso;
                kill(numeroDoProcesso, SIGKILL);
                //while(true){}
            }
            else if (PIM == 2)
            {
                cout << "digite o numero do processo a ser continuado" << endl;
                cin >> numeroDoProcesso;
                kill(numeroDoProcesso, SIGCONT);
            }
        }
        if (acao == 3)
        {
            int prioridade;
            cout << "Mudar Prioridade De Processo" << endl;
            cout << "digite o numero do processo desejado" << endl;
            cin >> numeroDoProcesso;
            cout << "digite a prioridade desejada" << endl;
            cin >> prioridade;
            setpriority(numeroDoProcesso, 0, prioridade);
        }
        if (acao == 4)
        {
            system("ps -ef");
        }
        if (acao == 5)
        {
            return (0);
        }
    }
}