// De Rosa Francesco 01/12/2020
using namespace std; //Spazio tra i nomi std:: per cout e cin

//------------LIBRERIE-----------------
#include <iostream> //Libreria standard C++
#include <string.h> //Libreria per la gestione delle stringhe
#include "../../classi/rivista.h" //Libreria contenente la classe rivista

//------------PROTOTIPI----------------
void inizializza(int l, int &num, rivista vet[]); //Prototipo Funz. Inizializza
void punto1(int num, rivista vet[]); //Prototipo Funz. Punto1

//-----------FUNZ PICCOLE---------------
void menu(int &scelta){cout<<"Che punto vuoi che io svolga? "; cin>>scelta;} //Funzione menu

//----------FUNZ PRINCIPALE-------------
int main(){
    const int LUN=30; int n1,n2;
    rivista v1[LUN], v2[LUN];
    cout<<"PRIMO ELENCO\n";
    inizializza(LUN,n1,v1);
    cout<<"SECONDO ELENCO\n";
    inizializza(LUN,n2,v2);

    int sc; do{
        menu(sc); switch(sc){
            case 1: punto1(n1,v1);punto1(n2,v2); 
    }   }while(sc==1);
}

//---------FUNZ INIZIALIZZA------------
void inizializza(int l, int &num, rivista vet[]){
    do{cout<<"Inserisci il numero di Riviste: ";cin>>num;}while(num>l||num<0);
    for (int i = 0; i < num; i++){vet[i].inser_inf();}
}

//-----------FUNZ PUNTO 1--------------
void punto1(int num, rivista vet[]){
    float inf,sup; int cont;
    cout<<"Iserisci 2 estremi di un elenco decimale: ";cin>>inf>>sup;
    for (int i=0; i<num; i++){
        if((vet[i].get_prezzo()<inf || vet[i].get_prezzo()>sup) && vet[i].get_settore()=='S') cont++;
    } 
    cout<<"Il numero di riviste Sport il cui prezzo \212 compreso in un generico intervallo \212 di "<<cont<<endl;
  }
