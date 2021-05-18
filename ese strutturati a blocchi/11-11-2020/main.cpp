using namespace std;
#include <iostream>
#include <float.h>

/*
int codice;
char zona;
char categoria[LUNS];
float metri_q;
*/

const int LUNS=30;
struct immobile{
    int codice;
    char zona, categoria[LUNS];
    float metri_q, prezzo;  
};

void inizializza(int l, int &num, immobile vet[]);
void menu(int &scelta);
void punto1(int num1, immobile vet1[], int num2, immobile vet2[]);
void visita_p1(int num, immobile vet[]);

int main(){
    int n1,n2;
    const int LUN=30;
    immobile v1[LUN],v2[LUN];

    inizializza(LUN,n1,v1);
    inizializza(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1: punto1(n1,v1,n2,v2);
        }
    }while(sc==1);
}

void inizializza(int l, int &num, immobile vet[]){
    do{
        cout<<"Inserisci num: "; cin>>num;
    }while(num<0||num>l);
    for (int i = 0; i < num; i++){
        cout<<"Codice: ";cin>>vet[i].codice;
        cout<<"Zona: ";cin>>vet[i].zona;
        cout<<"Categoria: ";cin>>vet[i].categoria;
        cout<<"Metri quadrati: ";cin>>vet[i].metri_q;
    }
}

void menu(int &scelta){
    cout<<"Quale punto vuoi che io svolga?\n>> ";
    cin>>scelta;
}

void punto1(int num1, immobile vet1[], int num2, immobile vet2[]){
    visita_p1(num1,vet1);
    visita_p1(num2,vet2);
}

void visita_p1(int num, immobile vet[]){
    float max_adh, min_adh, max_bfg, min_bfg, max_rest, min_rest;
    max_adh = max_bfg = max_rest = FLT_MIN;
    min_adh = min_bfg = min_rest = FLT_MAX;

    for (int i = 0; i < num; i++){
        if(vet[i].zona == 'A' || vet[i].zona == 'D' || vet[i].zona == 'H'){
            if(vet[i].prezzo>max_adh) max_adh=vet[i].prezzo;
            if(vet[i].prezzo<min_adh) min_adh=vet[i].prezzo;
        }
        else if(vet[i].zona == 'B' || vet[i].zona == 'F' || vet[i].zona == 'G'){
            if(vet[i].prezzo>max_bfg) max_bfg=vet[i].prezzo;
            if(vet[i].prezzo<min_bfg) min_bfg=vet[i].prezzo;
        }
        else{
            if(vet[i].prezzo>max_rest) max_rest=vet[i].prezzo;
            if(vet[i].prezzo<min_rest) min_rest=vet[i].prezzo;
        }
    }
    cout<<max_adh<<endl;
    cout<<min_adh<<endl;
    cout<<max_bfg<<endl; 
    cout<<min_bfg<<endl;
    cout<<max_rest<<endl; 
    cout<<min_rest<<endl;
}