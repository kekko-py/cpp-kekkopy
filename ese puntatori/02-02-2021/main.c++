using namespace std;
#include <iostream>
#include <float.h>
#include "../../classi_diz/comune.h"
#include "../../class_diz_din/diz_din.h"

typedef diz_din<comune> diz;
typedef nodo<comune> nodo_d;

void punto1(diz d1, diz d2);
void visita_p1(diz d, float &min_sup);
void punto2(diz d1, diz d2);

int main(){
    diz dc1,dc2;
    dc1.iniz_ord();
    dc2.iniz_ord();
    
    int sc;
    do
    {
        menu(sc);
        switch(sc){
            case 1: punto1(dc1,dc2);break;
            case 2: punto2(dc1,dc2);
        }
    } while (sc==1 || sc==2);
    
    return 0;
}

void punto1(diz d1, diz d2){
    float min_sup1, min_sup2;

    visita_p1(d1,min_sup1);
    visita_p1(d2,min_sup2);

    if(min_sup1<min_sup2) 
}


void visita_p1(diz d, float &min_sup){
    max_sup=FLT_MIN;
    min_sup=FLT_MAX;

    float gen_val;
    cin>>gen_val;
}

void punto2(diz d1, diz d2);
