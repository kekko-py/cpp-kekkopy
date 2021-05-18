using namespace std;

#include <iostream>
#include <string.h>

const int LUNS=30;
struct libro{
    int codice;
    char autore[LUNS];
    char casa_ed[LUNS];
    int anno;
    float prezzo;
    char genere;
};

void inizializza_elenco(int l, int &num, libro vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, libro vet[], int &pos);

void punto1(int num1, libro vet1[], int num2, libro vet2[]);
void menu_el(int &scelta_el);
void verifica_p1(int num, libro vet[]);

int main(){
    const int LUN=50;
    int n1,n2; libro v1[LUN],v2[LUN];
    inizializza_elenco(LUN,n1,v1);
    inizializza_elenco(LUN,n2,v2);
    int sc;
    do{
        menu(sc);
        switch (sc){
        case 1: punto1(n1,v1,n2,v2);break;
        case 2: break;
        }
    }while (sc==1||sc==2);
    return 0;
}
void inizializza_elenco(int l, int &num, libro vet[]){
    do{
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"CODICE: ";cin>>vet[i].codice;
		cout<<"AUTORE': ";cin>>vet[i].autore;
        cout<<"CASA EDITRICE: ";cin>>vet[i].casa_ed;
        cout<<"ANNO: ";cin>>vet[i].anno;
        cout<<"PREZZO: ";cin>>vet[i].prezzo;
        cout<<"GENERE: ";cin>>vet[i].genere;
    }
}
void menu(int &scelta){
  	cout<<"....";
  	cin>>scelta;
}
void punto1(int num1, libro vet1[], int num2, libro vet2[]){
    int sc_el;
    menu_el(sc_el);
    switch (sc_el){
    case 1: verifica_p1(num1,vet1);break;
    case 2: verifica_p1(num2,vet2);
    }
}
void menu_el(int &scelta_el){
    do{
        cout<<"...";
  	    cin>>scelta_el;
    }while (sc_el!=1&&sc_el!=2);
}
void verifica_p1(int num, libro vet[]){
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