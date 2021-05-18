/*
Stampare il prezzo medio delle riviste del primo elenco di un generico tipo 
che hanno periodicità diversa da quella del secondo elenco.
*/
using namespace std;
#include <iostream>
#include <float.h>
#include <String>
#include "../../classi_diz/rivista.h"
#include "../../class_diz_din/diz_din.h"

typedef diz_din<rivista> diz;
typedef nodo<rivista> nodo_d;

void punto1(diz d1, diz d2);

int main(){
    diz dr1,dr2;
    dr1.iniz_ord();
    dr2.iniz_ord();

    punto1(dr1,dr2);
    return 0;
}

/*
Stampare il prezzo medio delle riviste del primo elenco di un generico tipo 
che hanno periodicità diversa da quella del secondo elenco.
*/
void punto1(diz d1, diz d2){
    float som_pr=0,cont_gen_r=0;
    rivista r1,r2;
    nodo_d *q1, *q2;

    for(q1=d1.get_primo(), q2=d2.get_primo(); q1!=0 && q2!=0; q1=(*q1).get_next(), q12=(*q2).get_next())
    {
        r1=(*q1).get_info();
        r2=(*q2).get_info();

        if(r1.get_settore())
    }
}