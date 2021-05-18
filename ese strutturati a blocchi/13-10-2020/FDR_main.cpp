// De rosa Francesco 13/10/2020.
using namespace std;

// -------- Librerie Importate. ----------

#include <iostream>
#include <string.h>

//_____________________________________________________________________
/*
* Dati 2 elenchi di immobile:
	- Tipo
	- Zona
	- Superfice
	- Prezzo
*/
//______________________________________________________________________
// -------- Variabili Globali. ----------
struct immobile{
	char tipo[40];
	char zona;
	float superfice;
	float prezzo;
};

//______________________________________________________________________
// -------- Prototipi delle funzioni. ----------

void inizializza_elenco(int l, int &num, immobile vet[]);
void menu(int &scelta);
void punto1(int num, immobile vet[]);
void punto2(int num1, immobile vet1[], int num2, immobile vet2[]);
void visita_p2(int num, immobile vet[]);


//______________________________________________________________________
// -------- Funzione Principale. ----------
int main() {
	const int LUN=100;
	int n1,n2;
	immobile v1[LUN], v2[LUN];
	
	cout<<"Hey, Inserisci 2 enchi di immobili!\n";
	
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
	} while(sc<1||sc>2);
	
	return 0;
}
//______________________________________________________________________
// -------- Funzione Inizializza Elenco immobile. ----------

void inizializza_elenco(int l, int &num, immobile vet[]){
	do{
		cout<<"Quanti immobile Vuoi aggiungere? \n";
		cin>>num;
		cout<<endl;
		
	}while(num<0||num>l);
	
	
	for(int i=0;i<num;++i) {
		
		cout<<"\nRegistrazione immobile N^"<<i+1<<"\n\n";
		cout<<"TIPO: ";
		cin>>vet[i].tipo;
		cout<<"ZONA: ";
		cin>>vet[i].zona;
		cout<<"SUPERFICE: ";
		cin>>vet[i].superfice;
		cout<<"PREZZO: ";
		cin>>vet[i].prezzo;
		cout<<endl<<"____________________________ \n\n";
	}
}
// -------- Funzione Per la stampa del menù per la scelta ----------

void menu(int &scelta){
	
	cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1 [Primo elenco]\n";
  	cout<<"2] DF PUNTO 2 [Secondo Elenco]\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";

}

// -------- Funzione Per l'esecuzione del Punto 1. ----------

void punto1(int num, immobile vet[]){
	
	float somma_prezzo_appartamento, cont_prezzo_appartamento;
	float min_prezzo_appartamento;
	somma_prezzo_appartamento = cont_prezzo_appartamento = 0;
	min_prezzo_appartamento = INT_MAX;
	
	for(int i=0; i<num; ++i){
		if (strcmp(vet[i].tipo, "appartamento") == 0){
			somma_prezzo_appartamento += vet[i].prezzo;
			++cont_prezzo_appartamento;
			
			if(vet[i].prezzo<min_prezzo_appartamento)
				min_prezzo_appartamento =vet[i].prezzo;
		}
	}
	
	if (cont_prezzo_appartamento>0){
		cout<<"Il prezzo medio di un appartamento \212: "<<somma_prezzo_appartamento/cont_prezzo_appartamento<<endl;
		cout<<"L'appartamento più economico costa: "<<min_prezzo_appartamento<<endl;
		
	}
}

// -------- Funzione Per l'esecuzione del Punto 2. ----------

void punto2(int num1, immobile vet1[], int num2, immobile vet2[]){
	cout<<"PRIMO ELENCO DI IMMOBILI"<<endl;
	visita_p2(num1, vet1);
	cout<<"SECONDO ELENCO DI IMMOBILI"<<endl;
	visita_p2(num2, vet2);
}

// -------- Funzione Per l'esecuzione della visita del Punto 2. ----------

void visita_p2(int num, immobile vet[]){
	char input_tipo[40];
	cout<<"Inserisci Il tipo di Immobile sul quale lavorare zona [a]: "; cin>>input_tipo;
	
	float somma_prezzo_gentipo=0, cont_prezzo_gentipo=0;
	
	for(int i=0; i<num; ++i){
		if(vet[i].zona=='a' && strcmp(vet[i].tipo, input_tipo)==0){
			somma_prezzo_gentipo += vet[i].prezzo;
			++cont_prezzo_gentipo;
		}
	}
	
	if(cont_prezzo_gentipo>0)
		cout<<"Il prezzo medio di un immobile di tipo "<<input_tipo<<" nella zona [a] \212: "<<somma_prezzo_gentipo/cont_prezzo_gentipo<<endl;
	
}

