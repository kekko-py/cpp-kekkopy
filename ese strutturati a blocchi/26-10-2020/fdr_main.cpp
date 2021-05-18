// Francesco De Rosa 26/10/2020
/*
Esercizio su due elenchi di calciatori
1. Verificare se un giocatore del primo elenco è straniero e gioca in un ruolo diverso da quello 
   di un altro giocatore DELLO STESSO ELENCO
2. Contare quanti sono i giocatori di una generica squadra del primo elenco
   che hanno un ingaggio compreso in un generico intervallo 
   O IL CUI ELEMENTO CORRISPONDENTE del secondo è inglese o olandese.
*/
/*
CALCIATORE:
    - Codice
    - Nazionalità
    - Ruolo
    - Squadra
    - Ingaggio
*/
using namespace std;

#include <iostream>
#include <string.h>

const int LUNS=30;
//______________________________________________________________________
// -------- Variabili Globali. ----------
struct calciatore{
	int codice;
    char nazionalita[LUNS];
    char ruolo[LUNS];
    char squadra[LUNS];
    float ingaggio;
}
//______________________________________________________________________
// -------- Prototipi delle funzioni. ----------

void inizializza_elenco(int l, int &num, calciatore vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, calciatore vet[], int &pos);

void punto1(int num, calciatore vet[]);
void punto2(int num1, calciatore vet1[], int num2, calciatore vet2[]);
//______________________________________________________________________
// -------- Funzione Principale. ----------

int main() {
	const int LUN=50;
	int n1,n2;
	calciatore v1[LUN], v2[LUN];
	
	cout<<"Hey, Inserisci 2 enchi di Calciatori!\n";
	
	cout<<"[Primo Elenco]: \n";
	inizializza_elenco(LUN,n1,v1);
	cout<<"[Secondo Elenco]: \n";
	inizializza_elenco(LUN,n2,v2);
	
	
	int sc;
	do
	{
		menu(sc);
		switch(sc)
		{
			case 1: punto1(n1,v1);break;
			case 2:	punto2(n1,v1,n2,v2);
		}
			
	} while(sc==1||sc==2);
	
	return 0;
}
//______________________________________________________________________
// -------- Funzione Inizializza Elenco Calciatori. ----------

void inizializza_elenco(int l, int &num, claciatore vet[]){
	do{
		cout<<"Quanti Calciatori Vuoi aggiungere? \n";
		cin>>num;
		cout<<endl;
		
	}while(num<0);
	
	for(int i=0;i<num;++i) {
		
		cout<<"\nRegistrazione Calciatore N^"<<i+1<<"\n\n";	
        cout<<"CODICE: ";
		cin>>vet[i].codice;
		cout<<"NAZIONALITA': ";
		cin>>vet[i].nazionalita;
        cout<<"RUOLO: ";
        cin>>vet[i].ruolo;
        cout<<"SQUADRA: ";
        cin>>vet[i].squadra;
        cout<<"INGAGGIO: ";
        cin>>vet[i].ingaggio;
		cout<<endl<<"____________________________ \n\n";
	}
}
//______________________________________________________________________
// -------- Funzione Per la stampa del menu' per la scelta ----------

void menu(int &scelta){
	
	cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1 [Primo Elenco]\n";
  	cout<<"2] DF PUNTO 2 [Entrambi gli elenchi in parallelo]\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";

}
//______________________________________________________________________
// -------- Funzione Per l'esecuzione della ricerca sequenziale. ----------

bool ric_seq(int k int num, calciatore vet[], int &pos){
    for (int pos = 0; pos<num && k!= vet[pos].codice; pos++);
    return pos<num;
}
//______________________________________________________________________
// -------- Funzione Per l'esecuzione del Punto 1. ----------

// -1. Verificare se un giocatore del primo elenco è straniero e gioca in un ruolo diverso da quello 
//     di un altro giocatore DELLO STESSO ELENCO

void punto1(int num, calciatore vet[]){
    int k1, pos1;
    cout<<"Inserisci l'ID di un primo giocatore: "; cin>>k1;

    if(ric_seq(k1,num1,ve1,pos1)){
        int k2, pos2;
        cout<<"Inserisci l'Id di un secondo giocatore: "; cin>>k2;
        cin>>k2;
        if (ric_seq(k2,num2,pos2))
        {
            calciatore c1, c2;
            c1=vet1[pos1];
            c2=vet2[pos2];
            if (strcmp(c1.nazionalita,"italiana")!=0 && strcmp(c1.ruolo,c2.ruolo)!=0)
            {
               cout<<"I giocatori "<<k1<<" e "<<k2<<" Giocano in ruoli diversi e il primo \212 straniero"<<endl;
            }
            
        }
    }
}
//______________________________________________________________________
// -------- Funzione Per l'esecuzione del Punto 2. ----------

//2. Contare quanti sono i giocatori di una generica squadra del primo elenco
//   che hanno un ingaggio compreso in un generico intervallo 
//   O IL CUI ELEMENTO CORRISPONDENTE del secondo è inglese o olandese.

void punto2(int num1, calciatore vet1[], int num2, calciatore vet2[]){
    float inf,sup;
    cout<<"Inserisci gli esremi di un generico intervallo: "<<endl;
    cin>>inf>>sup;
    
    for (int i=0; i<num1 && ; i++)
    {
        /* code */
    }
           
}