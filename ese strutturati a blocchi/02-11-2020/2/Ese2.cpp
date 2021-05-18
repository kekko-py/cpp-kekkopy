// De Rosa Francesco 02/11/2020.

using namespace std;

#include <iostream>
#include <string.h>

//_____________________________________________________________________
/*
* Dati 2 elenchi di Corpi Celesti:
    - Codice
    - Nome
    - Tipo
    - Distanza dal sole
    - Massa
*/
//_____________________________________________________________________
// ------------- VAR. GLOBAL -----------------
const int LUNS=30;
struct corpo_c{
    int codice;
    char nome[LUNS];
    char tipo;
    float distanza_sole;
    float massa;
};
//_____________________________________________________________________
// ----------- PROTOTIPI FUNCT ----------------

void inizializza_elenco(int l, int &num, corpo_c vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, corpo_c vet[], int &pos);

void punto1(int num1, corpo_c vet1[], int num2, corpo_c vet2[]);
void punto2(int num1, corpo_c vet1[], int num2, corpo_c vet2[]);
void menu_el(int &scelta_el);
void visita_p2(int num, corpo_c vet[]);
//_____________________________________________________________________
// -------------- MAIN FUNCT -----------------
int main(){
    const int LUN=50;
    int n1,n2; corpo_c v1[LUN],v2[LUN];

    cout<<"Inserisci 2 Elenchi di Corpi Celesti!\n";

    cout<<"[PRIMO ELENCO]\n";
    inizializza_elenco(LUN,n1,v1);
    cout<<"[SECONDO ELENCO]\n";
    inizializza_elenco(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1:
            punto1(n1,v1,n2,v2);
            break;
        case 2:
            punto2(n1,v1,n2,v2);
        }
    }while (sc==1||sc==2);

    return 0;
}
//_____________________________________________________________________
//------------------ FUNCT INIZIALIZZA ------------------
void inizializza_elenco(int l, int &num, corpo_c vet[]){
    do{
        cout<<"Quanti corpi celesti vorresti aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"\nRegistrazione Corpo Celeste N^"<<i+1<<"\n\n";	
        cout<<"CODICE: ";
		cin>>vet[i].codice;
        cout<<"NOME: ";
		cin>>vet[i].nome;
        cout<<"TIPO: ";
		cin>>vet[i].tipo;
        cout<<"ANNI LUCE DAL SOLE: ";
		cin>>vet[i].distanza_sole;
        cout<<"MASSA: ";
		cin>>vet[i].massa;
		cout<<endl<<"____________________________ \n\n";
    }
}
//______________________________________________________________________
// ----------- FUNCT MENU -----------
void menu(int &scelta){
    cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1\n";
  	cout<<"2] DF PUNTO 2\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";
}
//______________________________________________________________________
// -------------- SEQUENTIAL SEARCH FUNCT ---------
bool ric_seq(int k, int num, corpo_c vet[], int &pos){
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}
//______________________________________________________________________
// ------------ FUNCT PUNTO1 -------------
void punto1(int num1, corpo_c vet1[], int num2, corpo_c vet2[]){
    int k1, pos1;
    cout<<"Inserisci l'ID di un corpo celeste del primo elenco: "; cin>>k1;

    if (ric_seq(k1,num1,vet1,pos1)){
        int k2, pos2;
        cout<<"Inserisci l'ID di un corpo celeste del Secondo elenco: "; cin>>k2;
        if (ric_seq(k2,num2,vet2,pos2)){
            char gen_name[LUNS];
            cout<<"Inserisci un generico nome: "; cin>>gen_name;
            int gen_v;
            cout<<"Inserisci un generico valore: "; cin>>gen_v;
            if (strcmp(vet1[pos1].nome,gen_name)==0 && vet1[pos1].tipo == vet2[pos2].tipo || vet1[pos1].distanza_sole>gen_v&&vet1[pos1].massa==vet1[pos1].massa-vet1[pos1].massa*2/100) 
                cout<<"Condizione confermata!\n";
            else
                cout<<"Condizione negata!\n";  
        } 
        else 
            cout<<"Secondo Elemento non trovato!\n";  
    }
    else 
        cout<<"Primo Elemento non trovato!\n";
}
//______________________________________________________________________
// ------------ FUNCT PUNTO2 -------------
void punto2(int num1, corpo_c vet1[], int num2, corpo_c vet2[]){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
        case 1:
            visita_p2(num1,vet1);
            break;
        case 2:
            visita_p2(num2,vet2);
        }
    }while (sc_el!=1&&sc_el!=2);
}
//______________________________________________________________________
// ------------ FUNCT MENU ELENCO -------------
void menu_el(int &scelta_el){
	cout<<"In quale elenco vuoli che lavori? \n\n";

  	cout<<"1] Primo\n";
  	cout<<"2] Secondo\n";

    cout<<">> ";
  	cin>>scelta_el;
  
  	cout<<"\n\n";
}
//______________________________________________________________________
// ------------ FUNCT VISITA P2 -------------
void visita_p2(int num, corpo_c vet[]){
    int gen_v, gen_per;
    cout<<"Inserisci un generico valore di massa: "; cin>>gen_v;
    cout<<"Inserisci una generica percentuale: "; cin>>gen_per;
    for (int i=0; i<num; i++){
        if(vet[i].tipo == 'S' && vet[i].massa+vet[i].massa*gen_per/100>gen_v)
            cout<<"La distanza dal sole del corpo celeste "<<vet[i].codice<<" \212 di: "<<vet[i].distanza_sole<<endl;
    }
}