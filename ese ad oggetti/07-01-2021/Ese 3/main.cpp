/*
Stampare il numero delle opere di uno tra due generici autori in entrambi gli elenchi e in totale.
Verificare se due opere del primo elenco hanno un valore minimo superiore a quello di 
un'opera del secondo elenco.
*/

using namespace std;
#include <iostream>
#include <string>
#include <float.h>

const int LUN=100;
#include "../../../classi_diz/opera2.h"
#include "../../../classi_diz/diz_stat.h"

typedef diz_stat<opera> diz;

void menu(int &scelta);
void punto1(diz d1, diz d2);
void visita_p1(diz d, int &n_op);

int main(){
    diz do1,do2;
    do1.iniz_ord();
    do2.iniz_ord();

    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(do1,do2);
        }
    }while(sc==1);
    return 0;
}

void menu(int &scelta)
{
	cout<<"P1\n";
	cout<<">> ";cin>>scelta;
}


// Stampare il numero delle opere di uno tra due generici autori in entrambi gli elenchi e in totale.
// Verificare se due opere del primo elenco hanno un valore minimo superiore a quello di 
// un'opera del secondo elenco.
void punto1(diz d1, diz d2){
    int n_op1=0,n_op2=0;
    cout<<"PRIMO ELENCO\n";
    visita_p1(d1,autore,n_op1);
    cout<<"SECONDO ELENCO\n";
    visita_p1(d2,autore,n_op2);

    cout<<"Il totale delle opere dell'autore '"<<autore<<"' \212 di: "<<n_op1+n_op2<<endl;
}

void visita_p1(diz d, int &n_op){
    string autore;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}
