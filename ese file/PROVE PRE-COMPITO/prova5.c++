/*
Dato un file contenente su ogni riga le seguenti informazioni:
nome prodotto,
tipo prodotto (A per alimentari, D per detersivi) 
quantità acquistata, 
prezzo,

calcolare: 
    prezzo medio dei prodotti acquistati in quantità pari
    ad un generico valore e trasferire in un secondo file le informazioni 
    sui prodotti il cui quantitativo di acquisto è superiore ad un generico valore e
    in un terzo quelle sui prodotti acquistati in quantità inferiore allo stesso generico valore.
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
bool trasferisci(char *nomef1, char *nomef2, char *nomef3);

int main(){
    const int LUNS=30;
    char nomef1[LUNS];

    string ris;
    do{
      cout<<"......"; cin>>ris;  
    }while(ris!="no"||ris!="si");
    
    if(ris=="si")
    {
        if(!inizializza(nomef1)) return 0;
    }
    else
    {
        cout<<"......"; cin>>nomef1;
    }       

    visualizza(nomef1);
    punto(nomef1, LUNS);
    return 0;
}

bool inizializza(char *nomef){
    cin>>nomef;
    ofstream f(nomef);

    if(!f.is_open()) return false;

    int n;
    do{
        cout<<"......."; cin>>n;
    }while(n<0);
    
    prodotto p;
    for (int i=0; i<n; i++){
        cin>>p.nome>>p.tipo>>p.quantita>>p.prezzo;
        f<<p.nome<<' '<<p.tipo<<' '<<p.quantita<<' '<<p.prezzo;
    }
    f.close()
    return true;
}

bool visualizza(char *nomef){
    ifstream f(nomef);
    if(!f.is_open()) return false;

    prodotto p;
    for (int i=1; f>>p.nome>>p.tipo>>p.quantita>>p.prezzo; i++)
        cout<<i<<' '<<p.nome<<' '<<p.tipo<<' '<<p.quantita<<' '<<p.prezzo;

    f.close();
    return true;
}

void punto(char *nomef1, int l){
    char nomef2[l], nomef3[l];
    cin>>nomef2>>nomef3;
    if(trasferisci(nomef1,nomef2,nomef3))
    {
        visualizza(nomef2);
        visualizza(nomef3);
    }
    else
        cout<<"non valido";
}

bool trasferisci(char *nomef1, char *nomef2, char *nomef3){
    ifstream f1(nomef1);
    ofstream f2(nomef2), f3(nomef3);
    if(!f1.is_open()||!f2.is_open()||!f3.is_open()) return false;
    /*
    prezzo medio dei prodotti acquistati in quantità pari
    ad un generico valore
	*/
    prodotto p;
    int gen_val, cont_prez=0;
    float somma_prez=0;
    while(f1>>p.nome && f1>>p.tipo && f1>>p.quantita && f1>>p.prezzo)
    {
        // prezzo medio dei prodotti acquistati in quantità pari
        // ad un generico valore
        if(p.quantita==gen_val){cont_prez++; somma_prez+=p.prezzo}
        // trasferire in un secondo file le informazioni 
        // sui prodotti il cui quantitativo di acquisto è superiore ad un generico valore
        
        // in un terzo quelle sui prodotti acquistati in quantità
        // inferiore allo stesso generico valore.
        
    }
}