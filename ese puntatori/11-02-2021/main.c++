/*
* Aumentare di una generica percentuale i prezzi delle riviste quindicinali che sono 
* dello stesso genere della rivista corrispondente del secondo elenco.
*/

using namespace std;
#include <iostream>
#include <String>
#include "../../classi_diz/rivista.h"
#include "../../class_diz_din/diz_din.h"

typedef diz_din<rivista> diz;
typedef nodo<rivista> nodo_d;

void punto1(diz d1, diz d2);

void menu(int &sc){cout<<"Inserisci La tua scelta [p1-p2]: "; cin>>sc;}

int main(){
    diz dr1,dr2;
    dr1.iniz_ord();
    dr2.iniz_ord();
    
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(dr1,dr2);
        }
    }while(sc==1);
    return 0;
}


// Aumentare di una generica percentuale i prezzi delle riviste quindicinali che sono 
// dello stesso genere della rivista corrispondente del secondo elenco.
void punto1(diz d1, diz d2){
    int gen_per;
    cout<<"Inserisci una generica percentuale:\n>> "; cin>>gen_per;

    rivista r1,r2;
    nodo_d *q1, *q2;
    for(q1=d1.get_primo(), q2=d2.get_primo(); q1!=0 && q2!=0; q1=(*q1).get_next(), q2=(*q2).get_next())
    {
        r1 = q1->get_info();
        r2 = q2->get_info();

        if(r1.get_periodicita()=="quindicinale" && r1.get_settore()==r2.get_settore())
        {
            r1.set_prezzo(r1.get_prezzo() + (r1.get_prezzo()/100*gen_per));
            q1->set_info(r1);
        }
    }
}
