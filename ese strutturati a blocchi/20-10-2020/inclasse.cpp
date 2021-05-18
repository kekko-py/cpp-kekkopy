using namespace std;
#include <iostream>
#include <string.h>

void inizializza(int l, int &num, claciatori vet[]);
void menu(int &scelta);
void punto1(int num1, calciatore vet1[], int num2, calciatore vet2[]);
void visita_p1(int num, calciatore vet[], float &max_ing);
void punto2(int num, calciatore vet[]);

const int LUN = 50;
struct calciatore{
    int codice;
	char cognome[LUN];
	char nome[LUN];
	char nazionalita[LUN];
	char ruolo[LUN];
	char squadra[LUN];
	float ingaggio;
}

int main(){
    int n1,n2;
	calciatore v1[LUN], v2[LUN];
	cout<<"Inserisci 2 enchi di calciatore:\n";
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

void inizializza(int l, int &num, claciatori vet[]){
    do{
		cout<<"Quanti calciatore Vuoi aggiungere? \n";
		cin>>num;
		cout<<endl;
	}while(num<0||num>l);

    for(int i=0; i<num; ++i){
        cout<<"CODICE UNIVOCO: "; cin>>vet[i].codice;
		cout<<"COGNOME: "; cin>>vet[i].cognome;
		cout<<"NOME: "; cin>>vet[i].nome;
		cout<<"NAZIONALITA': "; cin>>vet[i].nazionalita;
		cout<<"RUOLO: "; cin>>vet[i].ruolo;
		cout<<"SQUADRA: "; cin>>vet[i].squadra;
		cout<<"INGAGGIO: "; cin>>vet[i].ingaggio;
        cout<<endl;
    }
}

void menu(int &scelta){
    cout<<"1] DF PUNTO 1\n";
  	cout<<"2] DF PUNTO 2\n";
  	cout<<">> ";
  	cin>>scelta;
  	cout<<"\n\n";
}

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

void punto2(int num, calciatore vet[]){
    
}