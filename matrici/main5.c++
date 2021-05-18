/*
Un metodo elabora Array che riceve una matrice quadrata di interi m e restituisce un vettore v contenente gli
elementi situati nel triangolo avente come base l’ultima riga e come vertice opposto l’elemento centrale di m
(si veda l’esempio sottostante);

Un metodo confronta che riceve una matrice di interi m ed un intero c, e restituisce un booleano. In
particolare, il metodo restituisce true se la somma degli elementi di m che si trovano a destra della colonna c è
uguale alla somma degli elementi che si trovano a sinistra della colonna c, altrimenti restituisce false. Il
metodo restituisce false anche se c<1 o c>dimM-2 (dove dimM è 5 nel nostro caso);
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../funzioni/include.h"

const int LUN=100;

#include "../funzioni/funct_base.h"
#include "../funzioni/matrice.h"
#include <cmath>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//PROTOTIPI
void punto1(int vet[][LUN], unsigned int righe, unsigned int colonne);
//void punto2(int vet[][LUN], unsigned int righe, unsigned int colonne);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE PRINCIPALE
int main()
{
    int matrice[LUN][LUN];
    unsigned int righe,colonne;
    inizializza_matrice(matrice,righe,colonne);
    visualizza_matrice(matrice,righe,colonne);
    int sc;
    do
    {
        menu(sc, 2);
        switch(sc)
        {
            case 1: punto1(matrice,righe,colonne);break;
            //case 2: punto2(matrice,righe,colonne);break;
        } 
    } while (sc>=1&&sc<=2);
    
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
Un metodo elabora Array che riceve una matrice quadrata di interi m e restituisce un vettore v contenente gli
elementi situati nel triangolo avente come base l’ultima riga e come vertice opposto l’elemento centrale di m
(si veda l’esempio sottostante);
*/
void punto1(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    if(righe=!colonne) cout<<"NON \212 UN QUADRATO"<<endl;
    else
    {
        int vet_final[colonne*2], j=0;
        int riga_mover=righe/2, colonna_mover=colonne/2;

        for(int elem=1; elem<=colonne; elem+2)
        {
            
        }
        


        visualizza_array(vet_final, colonne*2);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*void punto2(int vet[][LUN], unsigned int righe, unsigned int colonne)
{

}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
