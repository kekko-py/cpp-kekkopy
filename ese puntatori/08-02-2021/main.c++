// De Rosa Francesco 08/02/2021

/*
    Il numero delle riviste di sport il cui prezzo è compreso in un generico intervallo in entrambi gli elenchi e in totale

    Verificare se il prezzo medio di due riviste (una del primo elenco e una del secondo) è superiore a 2 euro.
*/
using namespace std;
#include <iostream>
#include <float.h>
#include <String>
#include "../../classi_diz/rivista.h"
#include "../../class_diz_din/diz_din.h"

typedef diz_din<rivista> diz;
typedef nodo<rivista> nodo_d;

void menu(int &sc){cout<<"Inserisci La tua scelta [p1-p2]: "; cin>>sc;}
void punto1(diz d1, diz d2);
void visita_p1(diz d, int &n_riv);
void punto2(diz d1, diz d2);

int main(){
    diz dr1,dr2;
    dr1.iniz_ord();
    dr2.iniz_ord();
    
    int sc;
    do{
        menu(sc)
        switch(sc){
            case 1: punto1(dr1,dr2);break;
            case 2: punto2(dr1,dr2);
        }
    }while(sc==1||sc==2);

    return 0;
}

//Il numero delle riviste di sport il cui prezzo è compreso in un generico intervallo in entrambi gli elenchi e in totale
void punto1(diz d1, diz d2){
    int n_riv1=0,n_riv2=0;
    visita_p1(d1,n_riv1);
    visita_p1(d2,n_riv2);

    cout<<"Il numero di riviste il cui prezzo è compreso in un generico intervallo in entrambi gli elenchi e in totale di :"<<n_riv1+n_riv2<<endl;
}

void visita_p1(diz d, int &n_riv){
    int inf,sup;
    cout<<"inserisci due estremi del generico intervallo: ";
    cin>>inf>>sup;

    rivista r;
    nodo_d *q;

    for(q=d.get_primo(); q!=0; q=(*q).get_next())
    {
        r=(*q).get_info();

        if(r.get_settore()=='S' && r.get_prezzo()>=inf&&r.get_prezzo()<=sup)
            ++n_riv;
    }
    cout<<"Il numero delle riviste di sport vale: "<<n_riv<<endl;
}


//Verificare se il prezzo medio di due riviste (una del primo elenco e una del secondo) è superiore a 2 euro.
void punto2(diz d1, diz d2){
    nodo_d *q1,*q2;
    if(d1.ric_seq_ord(q1))
        if(d2.ric_seq_ord(q2))
        {
            rivista r1,r2;
            r1 = (q1)->get_info();
            r2 = (q2)->get_info();

            if((r1.get_prezzo()+r2.get_prezzo())/2 > 2.0) cout<<"OK\n";
            else cout<<"NO\n";
        }else cout<<"Secondo non trovato\n";
    else cout<<"Primo non trovato\n";
}
