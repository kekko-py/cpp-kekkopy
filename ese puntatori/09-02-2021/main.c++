/*
1.   Dati due elenchi di riviste, per ogni rivista sono dati: codice,settore (S sport, M moda), 
     periodicità (quotidiano, settimanale) casa editrice e prezzo. Calcolare:

1.1. Il prezzo minimo delle riviste settimanali pubblicate 
     dalla Mondadori in un elenco a scelta

1.2. Verificare se una rivista del secondo elenco è di uno 
     tra due generici settori e appartiene alla stessa case 
     editrice di un'altra rivista dello stesso elenco
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
void menu_el(int &sc){cout<<"Inserisci L'elenco: ' [1-2]: "; cin>>sc;}
void visita_p1(diz d);
void punto2(diz d1, diz d2);

int main(){
    diz dr1,dr2;
    dr1.iniz_ord();
    dr2.iniz_ord();
    
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1: punto1(dr1,dr2);break;
            case 2: punto2(dr1,dr2);
        }
    }while(sc==1||sc==2);

    return 0;
}

// Il prezzo minimo delle riviste settimanali pubblicate 
// dalla Mondadori in un elenco a scelta
void punto1(diz d1, diz d2){
    int sc;
    do{
        menu(sc);
        switch(sc){
            case 1:visita_p1(d1);break;
            case 2:visita_p1(d2);
        }
    }while(sc=!1&&sc!=2);
}


void visita_p1(diz d, int &n_riv){
    float pr_min=FLT_MAX;
    rivista r;
    nodo_d *q;

    for(q=d.get_primo(); q!=0; q=(*q).get_next())
    {
        r=(*q).get_info();

        if(r.get_periodicita()=="settimanale")
            if(r.get_prezzo()<pr_min) pr_min=r.get_prezzo();
    }
    cout<<"Il minimo prezzo delle riviste settimanali è di: "<<pr_min<<endl;
}

// Verificare se una rivista del secondo elenco è di uno 
// tra due generici settori e appartiene alla stessa casa 
// editrice di un'altra rivista dello stesso elenco
void punto2(diz d1, diz d2){
    string gen1,gen2;
    cin>>gen1>>gen2;

    nodo_d *q1,*q2;
    if(d2.ric_seq_ord(q1))
        if(d1.ric_seq_ord(q2))
        {
            rivista r1,r2;
            r1 = (q1)->get_info();
            r2 = (q2)->get_info();

            if((r1.get_casa_ed()==r2.get_casa_ed()) cout<<"OK\n";
            else cout<<"NO\n";
        }else cout<<"Secondo non trovato\n";
    else cout<<"Primo non trovato\n";
}