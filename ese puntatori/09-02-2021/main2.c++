/*
2. Dati due elenchi di corpi celesti per ogni corpo celeste sono dati: 
codice,
tipo (p Pianeta, s satellite),
massa, 
distanza dalla terra  
nome.

-----------------------------

2.1. Calcolare la distanza media dei pianeti la cui massa è esterna
     a un generico intervallo in un elenco a scelta

2.2. Verificare se un corpo celeste del primo elenco ha una massa 
     compresa in un generico intervallo e una distanza superiore a 
     quella media di due corpi celesti del secondo elenco.

-----------------------------
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
void visita_p1(diz d);
void punto2(diz d1, diz d2);

void menu(int &sc){cout<<"Inserisci La tua scelta [p1-p2]: "; cin>>sc;}
void menu_el(int &sc){cout<<"Inserisci L'elenco: ' [1-2]: "; cin>>sc;}

int main(){
    diz dcc1,dcc2;
    dcc1.iniz_ord();
    dcc2.iniz_ord();
    
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(dcc1,dcc2);break;
            case 2: punto2(dcc1,dcc2);
        }
    }while(sc==1||sc==2);
    return 0;
}


// Calcolare la distanza media dei pianeti la cui massa è esterna
// a un generico intervallo in un elenco a scelta
void punto1(diz d1, diz d2){
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1:visita_p1(d1);break;
            case 2:visita_p1(d2);
        }
    }while(sc!=1&&sc!=2);
}


void visita_p1(diz d){
    float somm_dist=0,cont_ext=0;
    float inf,sup;
    cout<<"Inserisci gli estremi di un generico intervallo:\n>> ";cin>>inf;cout<<">> ";cin>>sup;
    
    corpo_celeste c;
    nodo_d *q;
    for(q=d.get_primo(); q!=0; q=(*q).get_next()){
        c = (*q).get_info();
        if(c.get_massa()<inf||c.get_massa()>sup){somm_dist+=c.get_distanza_terra(); cont_ext++;}
    }
}

// Verificare se un corpo celeste del primo elenco ha una massa 
// compresa in un generico intervallo e una distanza superiore a 
// quella media di due corpi celesti del secondo elenco.
void punto2(diz d1, diz d2){
    nodo_d *q1, *q2, *q3;
    float inf,sup;
    if(d1.ric_seq_ord(q1))
        if(d2.ric_seq_ord(q2))
            if(d2.ric_seq_ord(q3))
            {
                corpo_celeste c1,c2,c3;
                c1 = (*q1).get_info();
                c2 = (*q2).get_info();
                c3 = (*q2).get_info();
                
                if(c1.get_massa()>=inf&&c1.get_massa()<=sup && c1.get_distanza_terra()>((c2.get_distanza_terra()+c3.get_distanza_terra())/2))
                    cout<<"Ok!\n";
                else cout<<"No! \n";

            }else cout<<"Terzo Non Trovato! \n";
        else cout<<"Secondo Non Trovato! \n";
    else cout<<"Primo Non Trovato! \n";
}