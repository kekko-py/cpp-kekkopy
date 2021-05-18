// De rosa Francesco 24/10/2020.

// Dati due elenchi di persone: 
// 1)Calcolare l’età media delle persone e di cognome Esposito e di altezza superiore ad un generico valore in entrambi gli elenchi e il minimo tra le due età medie
// 2)Verificare se una persona del primo elenco e una del secondo elenco hanno lo stesso cognome e nome diverso

using namespace std;

// -------- Librerie Importate. ----------

#include <iostream>
#include <string.h>

//_____________________________________________________________________
/*
* Dati 2 elenchi di Persone:
    - Nome
    - Cognome
    - Altezza
    - Età
*/
//______________________________________________________________________
// -------- Variabili Globali. ----------
const int LUNS=30;

struct persona{
	char nome[LUNS];
    char cognome[LUNS];
	float altezza;
    int eta;
};
//______________________________________________________________________
// -------- Prototipi delle funzioni. ----------

void inizializza_elenco(int l, int &num, persona vet[]);
void menu(int &scelta);

void punto1(int num1, persona vet1[], int num2, persona vet2[]);
void visita_p1(int num, persona vet[], int &eta_media);

void punto2(int num1, persona vet1[], int num2, persona vet2[]);

//______________________________________________________________________
// -------- Funzione Principale. ----------
int main() {
	const int LUN=50;
	int n1,n2;
	persona v1[LUN], v2[LUN];
	
	cout<<"Hey, Inserisci 2 enchi di Persone!\n";
	
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
			case 2:	punto2(n1,v1,n2,v2);
		}
			
	} while(sc<1||sc>2);
	
	return 0;
}
//______________________________________________________________________
// -------- Funzione Inizializza Elenco Persone. ----------

void inizializza_elenco(int l, int &num, persona vet[]){
	do{
		cout<<"Quanti Persone Vuoi aggiungere? \n";
		cin>>num;
		cout<<endl;
		
	}while(num<0||num>l);
	
	
	for(int i=0;i<num;++i) {
		
		cout<<"\nRegistrazione Persona N^"<<i+1<<"\n\n";	
        cout<<"NOME: ";
		cin>>vet[i].nome;
		cout<<"COGNOME: ";
		cin>>vet[i].cognome;
        cout<<"ETA': ";
        cin>>vet[i].eta;
        cout<<"ALTEZZA: ";
        cin>>vet[i].altezza;
		cout<<endl<<"____________________________ \n\n";
	}
}
// -------- Funzione Per la stampa del menÃ¹ per la scelta ----------

void menu(int &scelta){
	
	cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1 [Entrambi gli elenchi]\n";
  	cout<<"2] DF PUNTO 2 [Entrambi gli elenchi in parallelo]\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";

}

// -------- Funzione Per l'esecuzione del Punto 1. ----------

// 1)Calcolare l’età media delle persone e di cognome Esposito e di altezza superiore 
//   ad un generico valore in entrambi gli elenchi e il minimo tra le due età medie

void punto1(int num1, persona vet1[], int num2, persona vet2[]){	

    int eta_media1=0; int eta_media2=0;
    int min_eta_media = INT_MAX;

    cout<<"PRIMO ELENCO:\n";
    visita_p1(num1,vet1,eta_media1);
    cout<<"SECONDO ELENCO:\n";
    visita_p1(num2,vet2,eta_media2);

    if (eta_media1<min_eta_media) min_eta_media = eta_media1;
    else min_eta_media = eta_media2;    
    
    cout<<"l'eta media minima degli Esposito in totale \212 di "<<min_eta_media<<" Anni\n\n";
}

// -------- Funzione Per l'esecuzione della visita del Punto 1. ----------

void visita_p1(int num, persona vet[], int &eta_media){

    int somma_eta_esposito, cont_esposito;
    somma_eta_esposito = cont_esposito = 0;
    float gen_altezza;
    cout<<"Inserisci una generica altezza: "; cin>>gen_altezza;

    for (int i=0; i<num; i++)
    {
        if (strcmp(vet[i].cognome, "Esposito")==0 && vet[i].altezza > gen_altezza)
        {
            ++cont_esposito;
            somma_eta_esposito += vet[i].eta;
        }
    }
    if (cont_esposito>0)
    {
        eta_media = somma_eta_esposito/cont_esposito;
        cout<<"l'eta media minima degli Esposito \212 di "<<eta_media<<" Anni\n\n";
    }
}

// -------- Funzione Per l'esecuzione del Punto 2. ----------

// 2)Verificare se una persona del primo elenco e una del secondo elenco hanno lo stesso cognome e nome diverso

void punto2(int num1, persona vet1[], int num2, persona vet2[]){
	cout<<"Persone Con lo stesso cognome e nome diverso: \n"; 
	for (int i=0; i<num1 && i<num2; i++)
			for (int i2=0; i2<num2; i2++)
				if(strcmp(vet1[i].cognome, vet2[i2].cognome)==0 && strcmp(vet1[i].nome, vet2[i2].nome)!=0)
					cout<<vet1[i].nome<<' '<<vet1[i].cognome<<" e "<<vet2[i2].nome<<' '<<vet2[i2].cognome<<endl;
	cout<<endl<<endl;
}
