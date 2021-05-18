/*
Stampare la distanza minima dei pianeti del primo elenco che hanno distanza 
superiore a quella del corpo celeste corrispondente del secondo elenco.
*/

using namespace std;
#include <iostream>
#include <float.h>
#include <String>
#include "../../classi_diz/corpo_c.h"
#include "../../class_diz_din/diz_din.h"

typedef diz_din<corpo_celeste> diz;
typedef nodo<corpo_celeste> nodo_d;

void punto1(diz d1, diz d2);

void menu(int &sc){cout<<"Inserisci La tua scelta [p1-p2]: "; cin>>sc;}

int main(){
    diz dcc1,dcc2;
    dcc1.iniz_ord();
    dcc2.iniz_ord();
    
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(dcc1,dcc2);
        }
    }while(sc==1);
    return 0;
}


// Stampare la distanza minima dei pianeti del primo elenco che hanno distanza 
// superiore a quella del corpo celeste corrispondente del secondo elenco.
void punto1(diz d1, diz d2){
    float dist_min=FLT_MAX;
    corpo_celeste c1, c2;
    nodo_d *q1, *q2;
    for(q1=d1.get_primo(), q2=d2.get_primo(); q1!=0 && q2!=0; q1=(*q1).get_next(), q2=(*q2).get_next();)
    {
        c1 = (*q1).get_info();
        c2 = (*q2).get_info();
        if(c1.get_distanza_terra()>c2.get_distanza_terra())
            if(c1.get_distanza_terra()<dist_min) dist_min=c1.get_distanza_terra();
    }
}