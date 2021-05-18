/*

.1. Verificare se due piloti del primo elenco appartengono a scuderie diverse e 
      il primo dei due ha ingaggio superiore a quello di un pilota del secondo elenco
        
        
.2. Calcolare l'ingaggio minimo  e quello massimo dei piloti di una tra due generiche scuderie,
      l'ingaggio medio dei piloti di nazionalità francese che hanno vinto un numero di campionati 
      esterno ad un generico intervallo in entrambi gli elenchi e il minimo tra i due ingaggi medi.

*/

//-----------------------------------------------------------------------------------------------

using namespace std;
#include <iostream>
#include <string>
#include <float.h>

//-----------------------------------------------------------------------------------------------

const int LUN=100;
#include "../../classi_diz/piloti.h"
#include "../../classi_diz/diz_stat.h"

//-----------------------------------------------------------------------------------------------

typedef diz_stat<pilota> diz;

//-----------------------------------------------------------------------------------------------

void menu(int &scelta);
void punto1(diz d1, diz d2);
void punto2(diz d1, diz d2);
void visita_p1(diz d, float ing_med);

//-----------------------------------------------------------------------------------------------

int main(){
    diz dp1,dp2;
    dp1.iniz_ord();
    dp2.iniz_ord();
    
    int sc;
    do
    {
        menu(sc);
        switch(sc)
        {
        case 1: punto1(dp1,dp2);
        }
    }while(sc!=1);
    
    return 0;
}

void menu(int &scelta){
    cout<<"P1"; cin>>scelta;
}

//-----------------------------------------------------------------------------------------------
// Verificare se due piloti del primo elenco appartengono a scuderie diverse e 
// il primo dei due ha ingaggio superiore a quello di un pilota del secondo elenco
void punto1(diz d1, diz d2){

}

//-----------------------------------------------------------------------------------------------
// Calcolare l'ingaggio minimo  e quello massimo dei piloti di una tra due generiche scuderie,
// l'ingaggio medio dei piloti di nazionalità francese che hanno vinto un numero di campionati 
// esterno ad un generico intervallo in entrambi gli elenchi e il minimo tra i due ingaggi medi.
void punto2(diz d1, diz d2){
    cout<<"";
}

// ******* //
void visita_p1(diz d, float ing_med){
    cout<<"";
}