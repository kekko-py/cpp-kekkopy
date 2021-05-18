/*
     1. Calcolare la profondità media e quella minima dei mobili del settecento di uno tra due generici
      tipi e la larghezza massima dei mobili di un generico stile in entrambi gli elenchi e il massimo 
      tra le due profondità minime.

    2. Verificare che un mobile del primo elenco sia un tavolo e abbia una larghezza superiore a quella
       media di due mobili dle secondo elenco.
*/

#include <iostream>
#include <string>
#include <float.h>

const int LUN=50;

#include "diz_stat.h"
#include "mobili.h"

typedef diz_stat<mobile> diz;

void menu(int &sc);
void punto1(diz d1, diz d2);
void visita_p1(diz d, float &prof_min);
void punto2(diz d1, diz d2;)

int main(){
    diz dm1,dm2;
    dm1.iniz_ord();
    dm2.iniz_ord();

    int sc;
    do
    {
        menu(sc);
        switch (sc)
        {
        case 1:punto1(dm1,dm2);break;
        case 2:punto2(dm1,dm2);
        }
    } while (sc==1 || sc==2);
    return 0;
}

void menu(int &sc){
    cout<<"....";
    cin>>sc;
}


/*
     1. Calcolare la profondità media e quella minima dei mobili del settecento di uno tra due generici
      tipi e la larghezza massima dei mobili di un generico stile in entrambi gli elenchi e il massimo 
      tra le due profondità minime.
*/
void punto1(diz d1, diz d2){
    float prof_min1=FLT_MAX, prof_min2=FLT_MAX;
    visita_p1(d1,prof_min1);
    visita_p1(d2,prof_min2);

    if(prof_min1>prof_min2)cout<<"la massima \212: "<<prof_min1;
    else if(prof_min2>prof_min1)
}

void visita_p1(diz d, float &prof_min){
    float somma_prof=0, cont_prof=0, larg_max=FLT_MIN;
    string gen_t1,gen_t2;

    cout<<"....";
    cin>>gen_t1>>gen_t2;

    mobile m;
    for (int i=0; i<d.get_num(); i++)
    {
        m = d.get_elem(i);
        if((m.get_tipo()==gen_t1 || m.get_tipo()==gen_t2) && m.get_stile()=='O'){
            somma_prof += m.get_profondita();
            cont_prof++;

            if(m.get_profondita()<prof_min) prof_min==m.get_profondita();

        
        }
        
    }
}

 2. Verificare che un mobile del primo elenco sia un tavolo e abbia una larghezza superiore a quella
       media di due mobili dle secondo elenco.
void punto2(diz d1, diz d2){
    int med1,med2,med3;
    
    if(d1.ric_bin(med1))
      if(d2.ric_bin(med2))
        if(d2.ric_bin(med3)){
            mobile m1,m2,m3;
            m1= d1.get_elem(med)
            if()
        }else cout<<"terzo non trovato"; 
      else ....
    else cout<<"primo non trovato";
}