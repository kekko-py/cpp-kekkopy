/*
Dato un file contenente su ogni riga le seguenti informazioni:
nome prodotto,
tipo prodotto (A per alimentari, D per detersivi),
quantità acquistata,
prezzo.

calcolare il quantitativo minimo e quello massimo dei detersivi trasferendo
in un nuovo file le informazioni sui prodotti il cui prezzo è superiore ad un generico valore.

*/

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

struct prodotto{
    string nome;
    char tipo;
    int quantita;
    float prezzo;
};

bool inizializza(char *nomef);
bool visualizza(char *nomef);
void punto(char *nomef1, int l);
bool trasferisci(char *nomef1, char *nome2);

int main(){
    const int LUNS=30;
    char nomef1[LUNS];

    string ris;
    do{
        cout<<"Vuoi inizializzare? "; cin>>ris;
    }while(ris!="no"&&ris!="si");

    if(ris=="si")
    {
        if(!inizializza(nomef1)){cout<<"Si e' verificato un problema!"; return false;}
    }
    else
    {
        cout<<"Inserisci il nome del file da leggere: "; cin>>nomef1;
    }
    
    if(!visualizza(nomef1)){cout<<"File non trovato."; return false;}
    punto(nomef1,LUNS);
    return 0;
}

bool inizializza(char *nomef){
    cout<<"Inserisci il nome del file: "; cin>>nomef;
    ofstream f(nomef);
    int n;
    
    do{
        cout<<"Quanti prodotti vuoi inserire? "; cin>>n;
    }while(n<0);

    prodotto p;
    cout<<"Insersci nel formato NOME TIPO QUANTITA PREZZO";
    for(int i=0; i<n; i++)
    {
        cout<<'n'<<i<<">> "; cin>>p.nome>>p.tipo>>p.quantita>>p.prezzo;
        f 
    }

    

}