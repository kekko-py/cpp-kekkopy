/*
Francesco De Rosa.

  [] Sono dati due elenchi di comuni. Per ogni comune sono dati:
     codice, 
     nome, 
     numero abitanti, 
     superficie, 
     regione, 
     posizione (M per montano C per collina P per pianura), 
     tipo (grande, medio o piccolo) .

Aumentare di una generica percentuale la superficie dei comuni medi della Campania 
aventi un numero di abitanti superiore ad un generico valore o maggiore di quello del
comune corrispondente del secondo elenco se quest' ultimo è anch' esso della Campania.
*/

//-----------------------------------------------------------------------------------------------

using namespace std;
#include <iostream>
#include <string>
#include <float.h>

//-----------------------------------------------------------------------------------------------

const int LUN=100;
#include "../../../classi_diz/comune2.h"
#include "../../../classi_diz/diz_stat.h"

//-----------------------------------------------------------------------------------------------

typedef diz_stat<comune> diz;

//-----------------------------------------------------------------------------------------------

void menu(int &scelta);
void punto1(diz d1, diz d2);
void el_mancanti_p1(diz d, int n_rim, int gen_val, int gen_per);

//-----------------------------------------------------------------------------------------------

int main(){
    diz dc1,dc2;
    dc1.iniz_ord();
    dc2.iniz_ord();
    
    int sc;
    do
    {
        menu(sc);
        switch(sc)
        {
        case 1: punto1(dc1,dc2);
        }
    }while(sc!=1);
    
    return 0;
}

void menu(int &scelta){
    cout<<"P1"; cin>>scelta;
}

//-----------------------------------------------------------------------------------------------
// Aumentare di una generica percentuale la superficie dei comuni medi della Campania 
// aventi un numero di abitanti superiore ad un generico valore o maggiore di quello del
// comune corrispondente del secondo elenco se quest' ultimo è anch' esso della Campania.
void punto1(diz d1, diz d2){
    int gen_val, gen_per;
    cout<<"Inserisci un generico valore intero: "; cin>>gen_val;
    cout<<"Inserisci una generica percentuale: "; cin>>gen_per;

    comune c1,c2;
    float sup_aum;
    int i;
    for (i=0; i<d1.get_num() && i<d2.get_num(); i++)
    {
        c1 = d1.get_elem(i);
        c2 = d2.get_elem(i);

        if(c1.get_tipo()=="medio"&&c1.get_regione()=="Campania" && (c1.get_n_abitanti()>gen_val || c1.get_n_abitanti()>c2.get_n_abitanti() && c2.get_regione()=="Campania"))
        {
            sup_aum= gen_per*c1.get_superfice()/100;
            cout<<"Superfice Modificata da "<<c1.get_superfice()<<"mq a "<<sup_aum<<"mq\n"; 
            c1.set_superfice(sup_aum);
        } 
    }
    el_mancanti_p1(d1, i, gen_val, gen_per); // CHIAMATA ALLA FUNZIONE CHE ELABOREA' GLI ELEMENTI RESTANTI ANCORA NON ESAMINATI
}

//-----------------------------------------------------------------------------------------------

void el_mancanti_p1(diz d, int n_rim, int gen_val, int gen_per){
    comune c1;
    float sup_aum;

    for (int j=n_rim; j<d.get_num(); j++)
    {
        c1 = d.get_elem(j);
        if(c1.get_tipo()=="medio" && c1.get_regione()=="Campania" && c1.get_n_abitanti()>gen_val)
        {
            sup_aum= gen_per*c1.get_superfice()/100;
            cout<<"Superfice Modificata da "<<c1.get_superfice()<<"mq a "<<sup_aum<<"mq\n"; 
            c1.set_superfice(sup_aum);
        } 
    }
}

//-----------------------------------------------------------------------------------------------