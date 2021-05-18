using namespace std;
#include <iostream>
#include <fstream>

bool inizializza_fint(char *nomef);
bool visualizza_fint(char *nomef);

int main(){ 
    const int LUNS=30;
    char nomef[LUNS], ris;
    cout<<"Inserire il nome del file: "; cin>>nomef;
    cout<<"Vuoi inizializzare il file?";cin>>ris;
    if(ris=='s')
        if ( !inizializza_fint(nomef)) return 0;

    visualizza_fint(nomef);
    return 0;
}

bool inizializza_fint(char *nomef){
    ofstream f(nomef);
    if(!f.is_open()) return false;

    int n;
    do{
        cout<<"Inserire il numero di valori: ";
        cin>>n;
    }while(n<0);

    int val;
    for(int i=0;i<n;++i){ 
        cout<<"Inserire il valore: "; cin>>val;
        f<<val<<endl;
    }
    f.close();
    return true;
}

bool visualizza_fint(char *nomef){
    ifstream f(nomef);
    if(!f.is_open()) return false;
    int val;
    while(f>>val)
        cout<<"il valore e' "<<val<<endl;
    f.close();
    return true;
}