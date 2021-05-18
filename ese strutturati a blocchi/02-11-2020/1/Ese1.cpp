// De Rosa Francesco 02/11/2020.

using namespace std;

#include <iostream>

//_____________________________________________________________________
/*
* Dati 2 elenchi di Libri:
    - Codice
    - Autore
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
void punto2(int num1, libro vet1[], int num2, libro vet2[]);
void visita_p2(int num, libro vet[], int inf, int sup, int &cont_g);
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
            punto2(n1,v1,n2,v2);
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
    int k1, pos1;
    int inf,sup;
    char gen;
    cout<<"Inserisci l'ID di un generico libro [PRIMO ELENCO]: "; cin>>k1;
    cout<<"Inserisci Due Generici Anni: "; cin>>inf>>sup;
    cout<<"Inserisci un generico genere: "; cin>>gen;

    if (ric_seq(k1,num1,vet1,pos1)){
        int k2, pos2;
        cout<<"Inserisci l'ID di un generico libro [SECONDO ELENCO]: "; cin>>k2;
        if(ric_seq(k2,num2,vet2,pos2)){
            if ((vet1[pos1].anno>=inf && vet1[pos1].anno<=sup && vet1[pos1].genere == gen) || vet1[pos1].anno == vet2[pos2].anno)
                cout<<"Condizione Confermata!\n";
            else
                cout<<"Condizione non Confermata!\n";
        }
        else
            cout<<"Secondo Codice non trovato!\n";
    }
    else
        cout<<"Primo Codice non trovato!\n";
}
//______________________________________________________________________
// ------------ FUNCT PUNTO2 -------------
void punto2(int num1, libro vet1[], int num2, libro vet2[]){
    int inf,sup;
    int cont1,cont2;
    cout<<"Inserisci Due Generici Anni: "; cin>>inf>>sup;
    
    cout<<"\n[PRIMO ELENCO]";
    visita_p2(num1,vet1,inf,sup,cont1);
    cout<<"\n[SECONDO ELENCO]";
    visita_p2(num2,vet2,inf,sup,cont2);

    cout<<"\n[IN TOTALE]";
    cout<<"Il numero di libri di genere Giallo in totale \212 di: "<<cont1+cont2<<endl;
}
//______________________________________________________________________
// ------------ FUNCT VISITA P2 -------------
void visita_p2(int num, libro vet[], int inf, int sup, int &cont_g){
    for (int i=0; i<num; i++){
        if(vet[i].genere == 'G' && vet[i].anno>=inf&&vet[i].anno<=sup){
            cont_g++;
            cout<<"Il numero di libri di genere Giallo \212 di: "<<cont_g<<endl;
        }
    }  
}