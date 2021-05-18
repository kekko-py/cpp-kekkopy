/*
Esercizio da fare durante la lezione sull'implementazione di insiemi di entità tramite array di oggetti:
    1. Dati due elenchi di riviste, per ogni rivista sono dati: codice,settore, periodicità, casa editrice e prezzo. Calcolare:
        1.1. Il prezzo minimo delle riviste settimanali pubblicate dalla Mondadori in un elenco a scelta
    
*/
using namespace std;
#include <iostream>
#include <float.h>
#include <string.h>
#include "../../classi/rivista.h"
//-------------------------------------
void inizializza(int l, int &num, rivista vet[]);
void punto1(int num1, rivista vet1[], int num2, rivista vet2[]);
void menu_el(int &scelta_el){cout<<"Elenco 1 o 2? ";cin>>scelta_el;}
void visita_p1(int num, rivista vet[]);
//------------------------------------- 
int main(){
    const int LUN=50;
    int n1,n2;
    rivista v1[LUN], v2[LUN];
    inizializza(LUN,n1,v1);
    inizializza(LUN,n2,v2);
    punto1(n1,v1,n2,v2);
    return 0; }
//-------------------------------------
void inizializza(int l, int &num, rivista vet[]){
    do{cout<<"Inserisci il numero di riviste: ";cin>>num;}while(num>l||num<0);
    for (int i = 0; i < num; i++){vet[i].inser_inf();}}
//-------------------------------------
void punto1(int num1, rivista vet1[], int num2, rivista vet2[]){
    int sc;
    do{menu_el(sc);}while(sc!=1 && sc!=2);
    switch (sc){
        case 1:visita_p1(num1,vet1);break;
        case 2:visita_p1(num2,vet2);}}
//-------------------------------------
void visita_p1(int num, rivista vet[]){
    float prezzo_min=FLT_MAX; 
    for (int i=0; i<num; i++){
        if(!strcmp(vet[i].get_casa_ed(),"Mondatori")&&!strcmp(vet[i].get_periodicita(),"settimanale"))
            if(prezzo_min>vet[i].get_prezzo())prezzo_min=vet[i].get_prezzo();}
    cout<<"Il minimo tra i prezzi delle riviste settimanali della Mondatori \212 di: "<<prezzo_min;}
//-------------------------------------