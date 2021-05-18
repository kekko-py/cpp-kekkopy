// De Rosa Francesco 05/11/2020.

using namespace std;

#include <iostream>
#include <string.h>

//_____________________________________________________________________
/*
* Dati 2 elenchi di Libri:
    - Codice
    - Autore
    - Casa Editrice
    - Anno
    - Prezzo
    - Genere
*/
//_____________________________________________________________________
// ------------- VAR. GLOBAL -----------------
const int LUNS=30;
struct libro{
    int codice;
    char autore[LUNS];
    char casa_ed[LUNS];
    int anno;
    float prezzo;
    char genere;
};
//_____________________________________________________________________
// ----------- PROTOTIPI FUNCT ----------------

void inizializza_elenco(int l, int &num, libro vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, libro vet[], int &pos);

void punto1(int num1, libro vet1[], int num2, libro vet2[]);
void menu_el(int &scelta_el);
void visita_p1(int num, libro vet[]);

void punto2(int num, libro vet[]);

//_____________________________________________________________________
// -------------- MAIN FUNCT -----------------
int main(){
    const int LUN=50;
    int n1,n2; libro v1[LUN],v2[LUN];

    cout<<"Inserisci 2 Elenchi di Libri!\n";

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
            punto2(n2,v2);
        }
    }while (sc==1||sc==2);

    return 0;
}
//_____________________________________________________________________
//------------------ FUNCT INIZIALIZZA ------------------
void inizializza_elenco(int l, int &num, libro vet[]){
    do{
        cout<<"Quanti libri vorresti Aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"\nRegistrazione Libro N^"<<i+1<<"\n\n";	
        cout<<"CODICE: ";
		cin>>vet[i].codice;
		cout<<"AUTORE': ";
		cin>>vet[i].autore;
        cout<<"CASA EDITRICE: ";
        cin>>vet[i].casa_ed;
        cout<<"ANNO: ";
        cin>>vet[i].anno;
        cout<<"PREZZO: ";
        cin>>vet[i].prezzo;
        cout<<"GENERE: ";
        cin>>vet[i].genere;
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
bool ric_seq(int k, int num, libro vet[], int &pos){
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}
//______________________________________________________________________
// ------------ FUNCT PUNTO1 -------------
void punto1(int num1, libro vet1[], int num2, libro vet2[]){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
        case 1:
            visita_p1(num1,vet1);
            break;
        case 2:
            visita_p1(num2,vet2);
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
// ------------ FUNCT VISIT P1 -------------
void visita_p1(int num, libro vet[]){
    int k,pos;
    cout<<"Inserisci un generico codice: "; cin>>k;
    if(ric_seq(k,num,vet,pos)){
        char g_autore[LUNS], g_genere;
        cout<<"Inserisci un generico autore: "; cin>>g_autore;
        cout<<"Inserisci un generico genere: "; cin>>g_genere;
        if ((strcmp(g_autore,vet[pos].autore)==0 && strcmp("Mondatori",vet[pos].casa_ed)==0) || g_genere == vet[pos].genere)
            cout<<"Condizione Verificata\n";
        else cout<<"Condizione non verificata!\n";
    }
    else cout<<"Elemento non trovato\n";
}
//______________________________________________________________________
// ------------ FUNCT PUNTO2 -------------
void punto2(int num, libro vet[]){
    float somma_p_lorenzi = 0;
    int inf, sup, cont_lorenzi;

    cont_lorenzi = 0;
    cout<<"Inserisci 2 estremi [anni]: \n"; cin>>inf>>sup;

    for (int i=0; i<num; i++){
        if(strcmp("Lorenzi", vet[i].autore)==0 && (vet[i].anno<inf||vet[i].anno>sup)){
            somma_p_lorenzi += vet[i].prezzo; cont_lorenzi++;
        }   
    }
    if(cont_lorenzi>0) cout<<"La media \212: "<<somma_p_lorenzi/cont_lorenzi<<endl;
}