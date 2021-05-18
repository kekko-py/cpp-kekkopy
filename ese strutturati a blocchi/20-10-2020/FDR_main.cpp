// De rosa Francesco 13/10/2020.

// Sono dati du elenchi di calciatori. Per ogni calciatore sono date le seguenti informazioni:
// codice, cognome, nome, nazionalità, ruolo, squadra, ingaggio
// 1) stampare l’ingaggio più alto tra quelli dei giocatori italiani e quello medio dei giocatori della juventus stranieri in entrambi gli elenchi e il max tra i due ingaggi massimi
// 2) contare quanti sono i giocatori di una generica squadra del primo elenco che hanno un ingaggio compreso in un generico intervallo e l'ingaggio medio dei giocatori inglesi o olandesi.

using namespace std;

// -------- Librerie Importate. ----------

#include <iostream>
#include <string.h>

//_____________________________________________________________________
/*
* Dati 2 elenchi di Calciatori:
	- Codice
	- Cognome
	- Nome
	- Nazionalità
	- Ruolo
	- Squadra
	- Ingaggio
*/
//______________________________________________________________________
// -------- Variabili Globali. ----------
const int LUN=50;

struct calciatore{
	int codice;
	char cognome[LUN];
	char nome[LUN];
	char nazionalita[LUN];
	char ruolo[LUN];
	char squadra[LUN];
	int ingaggio;
};

//______________________________________________________________________
// -------- Prototipi delle funzioni. ----------

void inizializza_elenco(int l, int &num, calciatore vet[]);
void menu(int &scelta);

void punto1(int num1, calciatore vet1[], int num2, calciatore vet2[]);
void visita_p1(int num, calciatore vet[], float &max_ing);

void punto2(int num, calciatore vet[]);

//______________________________________________________________________
// -------- Funzione Principale. ----------
int main() {
	int n1,n2;
	calciatore v1[LUN], v2[LUN];
	
	cout<<"Hey, Inserisci 2 enchi di calciatori!\n";
	
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
			case 1: punto1(n1,v1,n2,v2);break;
			case 2:	punto2(n1,v1);
		}
			
	} while(sc<1||sc>2);
	
	return 0;
}
//______________________________________________________________________
// -------- Funzione Inizializza Elenco calciatore. ----------

void inizializza_elenco(int l, int &num, calciatore vet[]){
	do{
		cout<<"Quanti Calciatori Vuoi aggiungere? \n";
		cin>>num;
		cout<<endl;
		
	}while(num<0||num>l);
	
	
	for(int i=0;i<num;++i) {
		
		cout<<"\nRegistrazione Calciatore N^"<<i+1<<"\n\n";
		cout<<"CODICE UNIVOCO: ";
		cin>>vet[i].codice;
		cout<<"COGNOME: ";
		cin>>vet[i].cognome;
		cout<<"NOME: ";
		cin>>vet[i].nome;
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
// -------- Funzione Per la stampa del menù per la scelta ----------

void menu(int &scelta){
	
	cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1 [Entrambi gli elenchi]\n";
  	cout<<"2] DF PUNTO 2 [Primo Elenco]\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";

}

// -------- Funzione Per l'esecuzione del Punto 1. ----------

// 1) stampare l’ingaggio più alto tra quelli dei giocatori italiani e quello medio dei giocatori della juventus stranieri in entrambi gli elenchi
//	  e il max tra i due ingaggi massimi

void punto1(int num1, calciatore vet1[], int num2, calciatore vet2[]){	

	float max_ing1, max_ing2;
	float max_ing_tot;

	max_ing1 = max_ing2 = max_ing_tot = INT_MIN;

	cout<<"PRIMO ELENCO DI CALCIATORI:"<<endl;
	visita_p1(num1,vet1,max_ing1);
	cout<<"SECONDO ELENCO DI CALCIATORI:"<<endl;
	visita_p1(num2,vet2,max_ing1);

	if(max_ing1>max_ing2) max_ing_tot = max_ing1;
	else max_ing_tot = max_ing2;

	cout<<endl<<"L'ingaggio massimo Tra i 2 elenchi \212 di: "<<max_ing_tot<<endl;
}

// -------- Funzione Per l'esecuzione della visita del Punto 1. ----------

void visita_p1(int num, calciatore vet[], float &max_ing){

	float max_ing_it, somma_ing_juve_stanieri;
	int cont_ing_juve_stanieri;

	cont_ing_juve_stanieri = somma_ing_juve_stanieri = 0; max_ing_it = INT_MIN;

	for (int i=0; i<num; i++){
		if(!strcmp(vet[i].nazionalita, "italiana") && vet[i].ingaggio>max_ing_it) max_ing_it = vet[i].ingaggio;

		if(!strcmp(vet[i].squadra, "juventus") && strcmp(vet[i].nazionalita, "italiana") != 0){
			++cont_ing_juve_stanieri;
			somma_ing_juve_stanieri += vet[i].ingaggio;
		}

		if(vet[i].ingaggio>max_ing) max_ing = vet[i].ingaggio;
	}

	cout<<"L'ingaggio piu' alto tra i calciatori Italiani \212 di: "<<max_ing_it<<endl;
	if(cont_ing_juve_stanieri>0) cout<<"L'ingaggio medio dei giocatori juventini stranieri \212 di: "<<somma_ing_juve_stanieri/cont_ing_juve_stanieri<<endl<<endl;
}

// -------- Funzione Per l'esecuzione del Punto 2. ----------

// 2) contare quanti sono i giocatori di una generica squadra del primo elenco che hanno un ingaggio compreso in un generico intervallo
//    e l'ingaggio medio dei giocatori inglesi o olandesi.

void punto2(int num, calciatore vet[]){

	int cont_ing_gen_squadra_intervallo = 0;
	float somma_ing_engORola = 0; 
	int cont_ing_engORola = 0;

	char gen_squadra[LUN];
	int inf, sup;
	cout<<"Inserisci Una generica squadra: ";cin>>gen_squadra;
	cout<<"Inserisci Gli estremi di un Generico intervallo: \n";
	cout<<"[INF]>> ";cin>>inf;
	cout<<"[SUP]>> ";cin>>sup;

	for (int i=0; i<num; i++){
		if(!strcmp(vet[i].squadra, gen_squadra) && vet[i].ingaggio>=inf && vet[i].ingaggio<=sup) ++cont_ing_gen_squadra_intervallo;
		if(!strcmp(vet[i].nazionalita, "inglese") || !strcmp(vet[i].nazionalita, "olandese")){
			++cont_ing_engORola;
			somma_ing_engORola += vet[i].ingaggio;
		}
	}

	cout<<"Il numero dei giocatori Del/la "<<gen_squadra<<" Sono : "<<cont_ing_gen_squadra_intervallo<<endl;
	if(cont_ing_engORola>0) cout<<"L'ingaggio medio dei giocatori inglesi o olandesi \212 di: "<<somma_ing_engORola/cont_ing_engORola<<endl<<endl;
}
