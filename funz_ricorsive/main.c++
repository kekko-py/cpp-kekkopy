/*
Dato un elenco di interi:
1. Calcolare il minimo di un insieme di elementi.
2. Calcolare il minimo dei negativi e il massimo dei positivi.
*/
//-----------------------------------------------------------

#include "kekko.h"

//-----------------------------------------------------------

void punto1(int vet[], int n);
void punto2(int vet[], int n);

//-----------------------------------------------------------

int main(){
    const int LUN=50;
    int v[LUN], n;
    
    inizializza(LUN, v, n);

    int sc;
    do
    {
        menu(sc);
        switch(sc)
        {
            case 1: punto1(v,n);break;
            case 2: punto2(v,n);
        }
    }while(sc==1||sc==2);
    return 0;
}

//-----------------------------------------------------------

//1. Calcolare il minimo di un insieme di elementi.
void punto1(int vet[], int n)
{
    int min=INT_MAX;
    minimo_int(vet, n, min, "all");
    cout<<"Il minimo \212: "<<min<<endl;
}

//-----------------------------------------------------------

//2. Calcolare il minimo dei negativi e il massimo dei positivi.
void punto2(int vet[], int n)
{
    int min_neg=INT_MAX, max_pos=INT_MIN;

    minimo_int(vet, n, min_neg, "neg");
    massimo_int(vet, n, max_pos, "pos");

    cout<<"Il minimo \212: "<<min_neg<<endl;
    cout<<"Il massimo\212: "<<max_pos<<endl;
}

void punto2(int vet[], int n);
