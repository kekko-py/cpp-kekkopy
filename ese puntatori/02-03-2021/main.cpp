//De Rosa FrancescoS
/*
posizione (M per montano C per collina P per pianura),
tipo (grande, medio o piccolo) .

1. Stampare la superficie minima e quella massima dei comuni che si trovano in pianura o hanno
superficie superiore ad un generico valore aumentandone del 2%  la superficie in entrambi gli 
elenchi e il minimo tra le due superfici minime

2. Verificare se un comune del primo elenco si trova in pianura o ha superficie compresa 
nell' intervallo che ha come estremi la superficie di due comuni del secondo elenco.
*/

using namespace std;
#include <iostream>
#include <float.h>
#include <String>
#include "..\..\classi_diz\comune.h"
#include "..\..\class_diz_din\diz_din.h"

typedef diz_din<comune> diz;
typedef nodo<comune> nodo_d;

void punto1(diz d1, diz d2);
void visita_p1(diz d, float &sup_min);
void punto2(diz d1, diz d2);

int main(){
    diz dc1,dc2;
    dc1.iniz_ord();
    dc2.iniz_ord();
    
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(dc1,dc2);break;
            case 2: punto2(dc1,dc2);
        }
    }while(sc==1||sc==2);
    return 0;
}

/*
1. Stampare la superficie minima e quella massima dei comuni che si trovano in pianura o hanno
superficie superiore ad un generico valore aumentandone del 2%  la superficie in entrambi gli 
elenchi e il minimo tra le due superfici minime
*/
void punto1(diz d1, diz d2){
    float sup_min1=FLT_MAX, sup_min2=FLT_MAX;

    visita_p1(d1,sup_min1);
    visita_p1(d2,sup_min2);

    if(sup_min1<sup_min2) cout<<"La superfice minima \212 la prima!\n";
    else if(sup_min2<sup_min1) cout<<"La superfice minima \212 la seconda!\n";
    else cout<<"Le due superfici minime sono uguali!\n";
}

void visita_p1(diz d, float &sup_min){
    float sup_max=FLT_MIN, gen_val;
    cout<<"Inserisci un generico valore: "; cin>>gen_val;

    comune c;
    nodo_d q;
    for(q=d.get_primo(); q!=0; (*q).get_next()){
        c = (*q).get_info();
        if(c.get_posizione()=='P' || c.get_superfice()>gen_val+(gen_val/100*2)){
            if(c.get_superfice()>sup_max) sup_max=c.get_superfice();
            if(c.get_superfice()<sup_min) sup_min=c.get_superfice();
        }
    }
    cout<<sup_min<<endl<<sup_max;
}

/*
2. Verificare se un comune del primo elenco si trova in pianura o ha superficie compresa 
nell' intervallo che ha come estremi la superficie di due comuni del secondo elenco.
*/
void punto2(diz d1, diz d2){
    nodo_d q1,q2,q3;
    if(d1.ric_seq_ord(q1))
        if(d2.ric_seq_ord(q2))
            if(d2.ric_seq_ord(q3))
            {
                comune c1,c2,c3;
                c1=q1->get_info();
                c2=q2->get_info();
                c3=q3->get_info();

                if(c1.get_posizione()='P' || c1.get_superfice()>=c2.get_superfice()&&c1.get_superfice()<=c3.get_superfice())
                    cout<<"Condizione Verificata!\n";
                else
                    cout<<"NO\n";
            }else cout<<"Terzo non trovato\n";
        else cout<<"Secondo non trovato\n";
    else cout<<"Primo non trovato\n";
}