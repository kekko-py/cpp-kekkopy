using namespace std;
#include <iostream>

const int LUNS=30;
struct libro{
    int codice;
    char autore[LUNS];
    int anno;
    float prezzo;
    char genere;
};

void inizializza_elenco(int l, int &num, libro vet[]);
void menu(int &scelta);
bool ric_seq(int k, int num, libro vet[], int &pos);
void punto1(int num1, libro vet1[], int num2, libro vet2[]);

void punto2(int num1, libro vet1[], int num2, libro vet2[]);
void visita_p2(int num, libro vet[], int inf, int sup, int &cont_g);

int main(){
    const LUN=30;
    int n1,n2;
    libro v1[LUN],v2[LUN];

    cout<<".../n";
    inizializza_elenco(LUN,n1,v1);
    cout<<"...";
    inizializza_elenco(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc){
            case 1: punto1(n1,v1,n2,v2); break;
            case 2: break;
        }
        
    }while(sc==1||sc==2);

    return 0;
}

void inizializza_elenco(int l, int &num, libro vet[]){
    do{
        cout<<"...\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
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
    }
}

void menu(int &scelta){
  	cout<<"1] DF PUNTO 1\n";
  	cout<<"2] DF PUNTO 2\n";
  	cout<<">> ";
  	cin>>scelta;
}

bool ric_seq(int k, int num, libro vet[], int &pos){
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;

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