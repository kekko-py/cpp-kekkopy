/*
Somma dei pari e prodotto dei dispari
*/

#include "../funzioni/include.h"
#include "../class_alb_bin/wrapper.h"
#include "../class_alb_bin/alb_bin.h"

typedef alb_bin<integer> alb;
typedef nodo<integer> nodo_a;

void punto(alb a);
void visita(alb a, int &somma, int &prod);

int main()
{
    alb a;
    a.crea();
    a.preorder();
    punto(a);

    system("PAUSE");
    return 0;
}

void punto(alb a)
{
    int somma=0,prod=1;
    visita(a,somma,prod);
    cout<<endl;
    cout<<"La somma dei pari \212 "<<somma<<endl;
    cout<<"Il prodotto dei dispari \212 "<<prod<<endl;
}

void visita(alb a, int &somma, int &prod)
{
    nodo_a *rad = a.get_radice();

    if(rad!=0)
    {
        int n=rad->get_info().get_n();

        if(n%2==0) somma+=n;
        else prod*=n;

        visita(rad->get_albsin(),somma,prod);
        visita(rad->get_albdes(),somma,prod);
    }
}