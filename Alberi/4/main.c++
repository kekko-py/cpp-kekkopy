#include "../../funzioni/include.h"
#include "../../funzioni/funct_base.h"
#include "../../class_alb_bin/wrapper.h"
#include "../../class_alb_bin/alb_bin.h"

//------------------------------------------------------------

typedef alb_bin<integer> alb;
typedef nodo<integer> nodo_a;

//------------------------------------------------------------
/*
void punto1(alb a);
void visita_p1(alb a, int &cont);
void punto2(alb a);
void visita_p2(alb a, int &cont, int inf, int sup);
*/
void punto(alb a);
void visita(alb a, int &somma, int livello);

void punto2(alb a);
void visita2(alb a,int k, int livello);

void punto3(alb a);
void visita3(alb a, int &minimo,int k, int livello);

//------------------------------------------------------------

int main()
{
    alb a; a.crea(); a.preorder(); cout<<"\n\n";
    switch(menu(1)){ case 1: punto(a);}
    return 0;
}

//------------------------------------------------------------
/*
void punto1(alb a)
{
    int cont=0;
    visita_p1(a,cont);
    cout<<"Il numero di elem \212: "<<cont<<endl;
}

void visita_p1(alb a, int &cont)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
    {
        int n=rad->get_info().get_n();
        if(rad->get_albsin().get_radice()==0 && rad->get_albdes().get_radice()==0) cont++;
        else
        {
            visita_p1(rad->get_albsin(),cont);
            visita_p1(rad->get_albdes(),cont);    
        }
    }
}

//------------------------------------------------------------

void punto2(alb a)
{
    int cont=0, inf,sup;
    cout<<"Estremi: "; cin>>inf>>sup;
    visita_p2(a,cont, inf, sup);
    cout<<"Il numero di elem \212: "<<cont<<endl;
}

void visita_p2(alb a, int &cont, int inf, int sup)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
    {
        if(rad->get_albsin().get_radice()==0 && rad->get_albdes().get_radice()==0) 
        {
            int n=rad->get_info().get_n();
            if(n>=inf&&n<=sup) cont++;
        }
        else
        {
            visita_p2(rad->get_albsin(),cont, inf,sup);
            visita_p2(rad->get_albdes(),cont, inf,sup);    
        }
    }
}
*/
/*
stampare
la somma degli elementi di livello k


void punto(alb a)
{
    int k, somma=0;
    cout<<"inserisci k: ";cin>>k;
    visita(a,somma,k,0);
    cout<<"La somma \212: "<<somma<<endl;
}
void visita(alb a, int &somma, int k, int livello)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
        if(livello==k)
        {
            int n=rad->get_info().get_n();
            somma+=n;
        }
        else
        {
            visita(rad->get_albsin(),somma, k,livello+1);
            visita(rad->get_albdes(),somma, k,livello+1);
        }  
}
*/

void punto(alb a)
{
    int somma=0;
    visita(a,somma,0);
    cout<<"La somma \212: "<<somma<<endl;
}
void visita(alb a, int &somma, int livello)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
    {
        if(livello%2==0)
        {
            int n=rad->get_info().get_n();
            somma+=n;
        }
        visita(rad->get_albsin(),somma,livello+1);
        visita(rad->get_albdes(),somma,livello+1);
    }
}
/*
stampare le informazioni sui nodi di un livello <k le cui informazioni sono pari
*/
void punto2(alb a)
{
    int k;
    cout<<"inserisci k: ";cin>>k;
    visita2(a,k,0);
}
void visita2(alb a,int k, int livello)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
        if(livello<k)
        {
            int n=rad->get_info().get_n();
            if(n%2==0) cout<<"INFO: "<<n<<endl;
        }
        else
        {
            visita2(rad->get_albsin(),k,livello+1);
            visita2(rad->get_albdes(),k,livello+1);
        }
}
/*
calcolare il minimo dei nodi di livello >k
*/
void punto3(alb a)
{
    int k, minimo=INT_MAX;
    cout<<"inserisci k: ";cin>>k;
    visita3(a,minimo,k,0);
}
void visita3(alb a, int &minimo,int k, int livello)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
        if(livello>k)
        {
            int n=rad->get_info().get_n();
            if(n<minimo) minimo=n;
        }
        else
        {
            visita3(rad->get_albsin(),minimo,k,livello+1);
            visita3(rad->get_albdes(),minimo,k,livello+1);
        }
}

/*
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 1
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 2
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 4
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 5
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 3
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?s
Inserisci un numero intero: 6
vuoi inserire un nuovo albero?n
vuoi inserire un nuovo albero?n

Il numero e': 1
Il numero e': 2
Il numero e': 4
Il numero e': 5
Il numero e': 3
Il numero e': 6


Ottimo, Adesso Procediamo!
Quele operazioni vuoi che io esegua?

1] PUNTO 1
>> 1


inserisci k: 1
La somma è: 5
*/