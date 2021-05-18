using namespace std;
#include <iostream>

//COPYRIGTH: 2020 Francesco De Rosa

//_____________________________________________________________________________

//Dati tre elenchi di interi:
//
//1] Calcolare il minimo e la media dei valori esterni ad un generico intervallo in un elenco a scelta;
//
//2] Calcolare il massimo dei valori interni ad un generico intervallo o multipli di 33 e negativi in tutti e tre gli elenchi, e il numero dei pari in tutti e tre gli elenchi e in totale;
//
//3] Calcolare somma e prodotto di tutti i valori, media e minimo dei dispari che non sono multipli di un generico k nel terzo elenco.

//_____________________________________________________________________________
//______________________________PROTOTIPI FUNZ.________________________________

void inizializza(int l, int &num, int vet[]);
void menu(int &scelta);

void punto1(int num1, int vet1[], int num2, int vet2[], int num3, int vet3[]);
void menu_el(int &scelta_el);
void visita_p1(int num, int vet[]);

void punto2(int num1, int vet1[], int num2, int vet2[], int num3, int vet3[]);
void visita_p2(int num, int vet[], int &cont_pari);

void punto3(int num, int vet[]);

//_____________________________________________________________________________
//__________________________________MAIN_______________________________________

int main() {
	
	const int LUN=100;
	int n1,n2,n3;
	int v1[LUN],v2[LUN],v3[LUN];
	
	cout<<"PRIMO ELENCO\n";
	inizializza(LUN,n1,v1);
	cout<<"SECONDO ELENCO\n";
	inizializza(LUN,n2,v2);
	cout<<"TERZO ELENCO\n";
	inizializza(LUN,n3,v3);
	
	int sc;
	do
	{
		menu(sc);
		switch(sc)
		{
			case 1: punto1(n1,v1,n2,v2,n3,v3);break;
			case 2:	punto2(n1,v1,n2,v2,n3,v3);break;
			case 3: punto3(n3,v3);
		}
	} while(sc<1||sc>2);
}

//_____________________________________________________________________________
//_______________________________FUNZIONI______________________________________

//INIZIALIZZA

void inizializza(int l, int &num, int vet[]){
	
	do{
		
	    cout<<"Inserisci il Numero di valori che desideri inserire:  \n>> ";
	    cin>>num; 
		  
	} while(num<0||num>l);
	
	
	for(int i=0;i<num;++i)
	{
		cout<<"Inserisci il "<<i+1<<"^ Valore: \n>> ";
		cin>>vet[i];
	}
	
	cout<<"\n\n";
	
}	

//___________________________________________________

//MENU

void menu(int &scelta){ 

  cout<<"1] DF PUNTO 1 []\n";
  cout<<"2] DF PUNTO 2 []\n";
  cout<<"2] DF PUNTO 3 []\n";
  
  cout<<">> ";
  cin>>scelta;
  
  cout<<"\n\n";
}

//___________________________________________________

//PUNTO1

void punto1(int num1, int vet1[], int num2, int vet2[], int num3, int vet3[]){
	
	int sc_el;
	menu_el(sc_el);
	switch(sc_el)
	{
		case 1: visita_p1(num1,vet1);break;
		case 2: visita_p1(num2,vet2);break;
		case 3: visita_p1(num3,vet3);
	}
}

//___________________________________________________

//MENU_EL

void menu_el(int &scelta_el){
	
		do
		{
			cout<<"In quale elenco vuoi operare: \n";
			cin>>scelta_el;
			
		} while(scelta_el<1 || scelta_el>3);
}

//___________________________________________________

//VISITA_P1

void visita_p1(int num, int vet[]){
	//1] Calcolare il minimo e la media dei valori esterni ad un generico intervallo in un elenco a scelta;
	int inf,sup;
	int min_ext, somma_ext, cont_ext;
	
	min_ext = INT_MAX;
	somma_ext = cont_ext = 0;
	
	cout<<"Inserisci gli etremi di un genrico intervallo:\n>> ";
	cin>>inf;
	cout<<">> ";
	cin>>sup;
	
	for(int i=0; i<num; i++){
		if(vet[i]<inf || vet[i]>sup){
			somma_ext += vet[i];
			++cont_ext;
			
			if(vet[i]<min_ext)
				min_ext = vet[i];
		}
	}
	
	cout<<"Il valore più piccolo tra gli esterni \212: "<<min_ext<<endl;
	if (cont_ext>0)
		cout<<"La media tra i valori esterni \212: "<<somma_ext/cont_ext<<endl;
}

//___________________________________________________

//PUNTO2

void punto2(int num1, int vet1[], int num2, int vet2[], int num3, int vet3[]){
	int cont_pari1, cont_pari2, cont_pari3;
	cont_pari1 = cont_pari2 = cont_pari3 = 0;
	
	cout<<endl<<endl<<"PRIMO ELENCO:"<<endl;
	visita_p2(num1,vet1,cont_pari1);
	cout<<endl<<endl<<"SECONDO ELENCO:"<<endl;
	visita_p2(num2,vet2,cont_pari2);
	cout<<endl<<endl<<"TERZO ELENCO:"<<endl;
	visita_p2(num3,vet3,cont_pari3);
	
	int cont_pari_tot;
	cont_pari_tot = cont_pari1 + cont_pari2 + cont_pari3;
	
	cout<<endl<<endl<<"Numero dei pari in totale: "<<cont_pari_tot<<endl;
}

//___________________________________________________

//VISITA_P2

void visita_p2(int num, int vet[], int &cont_pari){
	//2] Calcolare il massimo dei valori interni ad un generico intervallo o multipli di 33 e negativi in tutti e tre gli elenchi, e il numero dei pari in tutti e tre gli elenchi e in totale;
	int inf,sup;
	int max_in_o_33_neg = INT_MIN;
		
	cout<<"Inserisci gli etremi di un genrico intervallo:\n>> ";
	cin>>inf;
	cout<<">> ";
	cin>>sup;
	
	for(int i=0; i<num; i++){
		if(vet[i]>=inf&&vet[i]<=sup || vet[i]%33==0&&vet[i]<0)
		 	if(vet[i]>max_in_o_33_neg)
		 		max_in_o_33_neg = vet[i];
		 	
		if(vet[i]%2==0)
			++cont_pari;
	}
	
	cout<<"il massimo dei valori interni ad un generico intervallo o multipli di 33 e negativi \212: "<<max_in_o_33_neg<<endl;
	cout<<"Il numero dei valori pari \212: "<<cont_pari<<endl;
}

//___________________________________________________

/
//___________________________________________________

