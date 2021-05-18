/*

1. Verificare se un pilota del primo elenco è della Ferrari e ha vinto un numero di campionati
   compreso nell’intervallo avente come estremi il numero di campionati vinti da due piloti del 
   secondo elenco

2. Calcolare l’ ingaggio medio e quello minimo dei piloti Italiani che appartengono a una tra 
   due generiche scuderie in entrambi gli elenchi e il minimo tra i due ingaggi medi

*/
using namespace std;

#include <iostream>
#include <string>
#include <float.h>

const int LUN=50;

#include "../../classi_diz/piloti.h"
#include "../../classi_diz/diz_stat.h"

typedef diz_stat<pilota> diz;

void menu(int &scelta);
void punto1(diz d1, diz d2);
void punto2(diz d1, diz d2);
void visita_p2(diz d, float ing_med);

int main(){
    diz dp1,dp2;
    dp1.iniz_ord();
    dp2.iniz_ord();

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1: punto1(dp1,dp2);break;
        case 2: punto2(dp1,dp2);
        }
    }while(sc==1||sc==2);
    return 0;
}

void menu(int &sc){
    cout<<"P1 - P2";
    cin>>sc;
}

// Verificare se un pilota del primo elenco è della Ferrari e ha vinto un numero di campionati
// compreso nell’intervallo avente come estremi il numero di campionati vinti da due piloti del 
// secondo elenco
void punto1(diz d1, diz d2){
    int med1,med2,med3;

    if(d1.ric_bin(med1))
        if(d2.ric_bin(med2))
            if(d2.ric_bin(med3))
            {
                pilota p1,p2,p3;
                p1 = d1.get_elem(med1);
                p2 = d2.get_elem(med2);
                p3 = d2.get_elem(med3);

                int inf,sup;
                if(p2.get_vittorie()>p3.get_vittorie()){sup=p2.get_vittorie(); inf=p1.get_vittorie();}
                else {sup=p1.get_vittorie(); inf=p2.get_vittorie();}

                if(p1.get_scuderia()=='F' && p1.get_vittorie()>=inf && p1.get_vittorie()<=sup) cout<<"OK\n";
                else cout<<"NO\n";
            }
            else cout<<"Terzo non trovato\n";
        else cout<<"Secondo non trovato\n";
    else cout<<"Primo non trovato\n";
}

// Calcolare l’ ingaggio medio e quello minimo dei piloti Italiani che appartengono a una tra 
// due generiche scuderie in entrambi gli elenchi e il minimo tra i due ingaggi medi
void punto2(diz d1, diz d2){
    float ing_med1,ing_med2;
    visita_p2(d1,ing_med1);
    visita_p2(d2,ing_med2);

    if(ing_med1<ing_med2) cout<<"La prima media \212 è più piccola della seconda.\n";
    else if(ing_med2<ing_med1) cout<<"La seconda media \212 è più piccola della prima.\n";
    else cout<<"Le due medie sono uguali.\n";
}

void visita_p2(diz d, float ing_med){
    float ing_som,ing_min=FLT_MAX;
    int ing_cont;
    char gen_s1,gen_s2;

    cin>>gen_s1>>gen_s2;

    pilota p;
    for (int i=0; i<d.get_num(); i++)
    {
        p = d.get_elem(i);
        if(p.get_nazionalita()=="italiana" && (p.get_scuderia()==gen_s1||p.get_scuderia()==gen_s2))
        {
            if(p.get_ingaggio()<ing_min) ing_min= p.get_ingaggio();
            ing_som += p.get_ingaggio();
            ing_cont++;
        }
    }

    if(ing_cont>0){ing_med=ing_som/ing_cont; cout<<"La media \212: "<<ing_med;}
    cout<<"Il minimo \212: "<<ing_min;
}