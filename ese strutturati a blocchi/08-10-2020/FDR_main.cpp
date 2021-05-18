using namespace std;
#include <iostream>

//COPYRIGTH: 2020 Francesco De Rosa

//_____________________________________________________________________________
//______________________________PROTOTIPI FUNZ.________________________________

//INIZIALIZZAZIONE E MENU
void inizializza(int l, int &num, int vet[]);
void menu(int &scelta);
void punto1(int num, int vet[]);
void punto2(int num1, int vet1[], int num2, int vet2[]);
void visita_p2(int num, int vet[]);
void menu_el(int &scelta_el);
void punto3(int num1, int vet1[], int num2, int vet2[]);
void visita_p3(int num, int vet[]);

//_____________________________________________________________________________
//__________________________________MAIN_______________________________________

int main() {
	
	const int LUN=100;
	int n1,n2;
	int v1[LUN],v2[LUN];
	
	cout<<"PRIMO ELENCO\n";
	inizializza(LUN,n1,v1);
	cout<<"SECONDO ELENCO\n";
	inizializza(LUN,n2,v2);
	
	int sc;
	do
	{
		menu(sc);
		switch(sc)
		{
			case 1: punto1(n2,v2);break;
			case 2: punto2(n1,v1,n2,v2);break;
			case 3: punto3(n1,v1,n2,v2);
		}
	}while(sc>=1&&sc<=3);
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
		cout<<"Inserisci il "<<i+1<<"^ numero: \n>> ";
		cin>>vet[i];
	}
	
	cout<<"\n\n";
	
}	

//___________________________________________________

//MENU

void menu(int &scelta){ 

  cout<<"1] DF PUNTO 1 [SECONDO ELENCO]\n";
  cout<<"2] DF PUNTO 2 [ENTRAMBI GLI ELENCHI]\n";
  cout<<"2] DF PUNTO 3 [ELENCO A SCELTA]\n";
  
  cout<<">> ";
  cin>>scelta;
  
  cout<<"\n\n";
}

//___________________________________________________

//PUNTO1

void punto1(int num, int vet[]){
	int min_tot, somma_tot, max_7_ext, prod_7_ext;
	int inf, sup;
	
	min_tot = INT_MAX;
	somma_tot = 0;
	max_7_ext = INT_MIN;
	prod_7_ext = 1;
	
	cout<<"Inserisci gli estremi di un generico intervallo:\n";
	cin>>inf>>sup;
	
	for(int i=0; i<num; ++i){
		
		somma_tot += vet[i];
		
		if(vet[i]<min_tot)
			min_tot=vet[i];
		
		if(vet[i]%7!=0 && vet[i]<inf||vet[i]>sup){
			
			if(vet[i]>max_7_ext)
				max_7_ext = vet[i];
				
			prod_7_ext *= vet[i];
		}
	}
	
	cout<<"Media Totale: "<<somma_tot/num<<endl;
	cout<<"Minimo Totale: "<<min_tot<<endl;
	cout<<"Massimo esterni non multipli di 7: "<<max_7_ext<<endl;
	cout<<"Prodotto esterni non multipli di 7: "<<prod_7_ext<<endl;
}

//___________________________________________________

//PUNTO2

void punto2(int num1, int vet1[], int num2, int vet2[]){
	
	cout<<"PRIMO ELENCO\n";
	visita_p2(num1,vet1);
	cout<<"SECONDO ELENCO\n";
	visita_p2(num2,vet2);
	
}

//___________________________________________________

//VISITA_P2

void visita_p2(int num, int vet[]){
	
	int somma_neg_p_k, prod_neg_p_k, min_neg_p_k;
	int somma_nk, cont_nk, min_nk;
	int somma_k, cont_k;
	
	int k;
	
	somma_neg_p_k = somma_nk = cont_nk = somma_k = cont_k = 0;
	prod_neg_p_k = 1;
	min_neg_p_k = min_nk = INT_MAX;
	
	cout<<"Inserisci un generico valore k:\n";
	cin>>k;
	
	for(int i = 0; i<num; ++i){
		if (vet[i]%k==0){
			
			somma_k += vet[i];
			++cont_k;
			
			if(vet[i]<0 && vet[i]%2==0){
				somma_neg_p_k += vet[i];
				prod_neg_p_k *= vet[i];
				
				if(vet[i]<min_neg_p_k)
					min_neg_p_k = vet[i];
			}
		}
		else{
			somma_nk += vet[i];
			++cont_nk;
			
			if(vet[i]<min_nk)
				min_nk = vet[i];
		}
	}
	
	cout<<"Somma negativi pari e multipli di k: "<<somma_neg_p_k<<endl;
	cout<<"Prodotto negativi pari e multipli di k: "<<prod_neg_p_k<<endl;
	cout<<"Minimo negativipari e multipli di k: "<<min_neg_p_k<<endl;
	
	if(cont_nk>0)
		cout<<"Media non multipli di k: "<<somma_nk/cont_nk<<endl;
	cout<<"Minimo tra i non multipli di k: "<<min_nk<<endl;
	
	if(cont_k>0)
		cout<<"Media multipli di k: "<<somma_k/cont_k<<endl;
}

//___________________________________________________

//PUNTO3

void punto3(int num1, int vet1[], int num2, int vet2[]){
	
	int sc_el;
	menu_el(sc_el);
	
	do{
		switch(sc_el){
			case 1: visita_p3(num1, vet1);break;
			case 2: visita_p3(num2, vet2);
		}
	}while(sc_el<1||sc_el>2);
	
}

//___________________________________________________

//VISITA_P3

void visita_p3(int num, int vet[]){
	
	int min_tot, max_tot;
	int prod_pos;
	int min_neg_or0, max_neg_or0;
	
	min_tot = min_neg_or0 = INT_MAX;
	max_tot = max_neg_or0 = INT_MIN;
	
	for(int i=0; i<num; ++i){
		
		if(vet[i]<min_tot)
			min_tot = vet[i];
		if(vet[i]>max_tot)
			max_tot = vet[i];
			
		if(vet[i]<0 || vet[i]==0){
			
			if(vet[i]<min_neg_or0)
				min_neg_or0 = vet[i];
			if(vet[i]>max_neg_or0)
				max_neg_or0 = vet[i];			
		}
		else
			if(vet[i]>0)
				prod_pos *= vet[i];
	
	}
	
	cout<<"Minimo Totale: "<<min_tot<<endl;
	cout<<"Massimo Totale: "<<max_tot<<endl;
	cout<<"Prodotto Positivi: "<<prod_pos<<endl;
	cout<<"Minimo negativo o uguale a 0: "<<min_neg_or0<<endl;
	cout<<"Massimo negativo o uguale a 0: "<<max_neg_or0<<endl;
}
//___________________________________________________

