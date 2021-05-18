using namespace std;

const int LUN = 50;

#include <iostream>
#include <string>
#include <float.h>
#include "../../classi_diz/diz_stat.h"
#include "../../classi_diz/rivista.h"

typedef diz_stat<rivista> diz;

void menu(int &sc){cout<<"Punto 1 o 2? ";cin>>sc;}
void menu_el(int &sc){cout<<"Elenco 1 o 2? ";cin>>sc;}
void punto1(diz d1, diz d2);
void visita_p1(diz d);
void punto2(diz d);

int main(){
    diz dr1,dr2;
    
    dr1.iniz_ord();
    dr2.iniz_ord();

    int sc;
    do
    {
        menu(sc);
        switch (sc)
        {
            case 1: punto1(dr1,dr2);
            case 2: punto2(dr2);
        }
    }while(sc==1||sc==2);

    return 0;
}

void punto1(diz d1, dir d2){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
            case 1:visita_p1(d1);break;
            case 2:visita_p1(d2);
        }
}

void visita_p1(diz d){
    float prezzo_min = FLT_MAX;

    for (int i = 0; i<d.get_num(); i++)
    {
        r = d.get_elem(i);
        if(r.get_periodo()=="settimanale" && r.casa_ed()=="mondatori")
            if(r.get_prezzo()<prezzo_min)
                prezzo_min=r.get_prezzo();
    }
    
    cout<<"Prezzo minimo: "<<prezzo_min<<endl;
}

void punto2(diz d){
    int med1,med2;
    if(d.ric_bin(med1))
        if(d.ric_bin(med2))
        {
            rivista r1,r2;
            r1 = d.get_elem(med1);
            r2 = d.get_elem(med2);

            char gen_s1,gen_s2;
            cout<<"Inserisci 2 generici Settori: "; cin>>gen_s1>>gen_s2;

            if((r1.get_settore()==gen_s1 || r1.get_settore()==gen_s2) && r1.get_casa_ed()==r2.get_casa_ed())  cout<<"ok\n"; 
            else cout<<"No\n"; 
        }
        else cout<<"Seconda non trovata!\n";
    else cout<<"Prima non trovata!\n";
    
}