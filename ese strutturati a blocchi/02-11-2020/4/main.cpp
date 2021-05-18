using namespace std;
#include <iostream>

const int LUNS = 30; 
struct corpo_c{
    int codice;
    char nome[LUNS];
    char tipo;
    float distanza_sole;
};

void inizializza(int l, int &num, corpo_c vet[]);
void menu(int &scelta);
bool ric_seq(int k, int num, corpo_c vet[], int &pos);
void punto1(int num, corpo_c vet[]);

int main(){
    const int LUN=50;
    int n1,n2;
    corpo_c v1[], v2[];

    cout<<"Primo Elenco!\n";
    inizializza(LUN,n1,v1);
    cout<<"Secondo Elenco!\n";
    inizializza(LUN,n2,v2);
    
    int sc;
    do{
        menu(sc);
        switch(sc){
        case 1: punto1(n1,v1);break;
        }
    }while(sc==1);

    return 0;    
}

void inizializza(int l, int &num, corpo_c vet[]){
    do{
        cout<<"...";
        cin>>num;
    } while (num<0||num>l);

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
		cout<<endl<<"____________________________ \n\n";
    }   
}

void menu(int &scelta){
    cout<<"1 o 2\n";
    cin>>scelta;
}

bool ric_seq(int k, int num, corpo_c vet[], int &pos){
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}

void punto1(int num, corpo_c vet[]){
    int k1,pos1;
    cout<<"Inserisci un primo codice [Primo elenco]\n";
    cin>>k1;
    if(ric_seq(k1,num,vet,pos1)){
        int k2,pos2;
        cout<<"Inserisci un Secondo codice [Primo elenco]\n";
        cin>>k2;
        if(ric_seq(k2,num,vet,pos2)){
            c1 = vet[pos1];
            c2 = vet[pos2];
            int gen_v;
            cout<<"Inserisci un generico valore:\n"; cin>>gen_v;
            if (c1.tipo!=c2.tipo && (c1.distanza+c2.distanza)/2<gen_v)
                cout<<"Condizione Verificata\n";
            else cout<<"Condizione non verificata\n"
        }
        else cout<<"Secondo Non trovato\n";
    }
    else cout<<"Primo non trovato\n";
}

