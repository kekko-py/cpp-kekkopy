using namespace std;
#include <iostream>
#include <string.h>

const int LUNS=30;
struct immobile{
    int codice;
    char zona;
    char categoria[LUNS];
    int metri_q;
};

void inizializza_elenco(int l, int &num, immobile vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, immobile vet[], int &pos);

void punto1(int num, immobile vet[]);

int main(){
    const int LUN=50;
    int n1,n2;
    immobile v1[LUN],v2[LUN];

    cout<<"...";
    inizializza_elenco(LUN,n1,v1);
    cout<<"...";
    inizializza_elenco(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1:
            punto1(n1,v1);
        }
    }while(sc==1);
    return 0;
}

void inizializza_elenco(int l, int &num, immobile vet[]){
    do{
        cout<<"Quanti Immobili vorresti Aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"CODICE: ";cin>>vet[i].codice;
        cout<<"ZONA: ";cin>>vet[i].zona;
        cout<<"CATEGORIA: ";cin>>vet[i].categoria;
        cout<<"METRI QUADRI: "; cin>>vet[i].metri_q;
    }
}

void menu(int &scelta){
    cout<<"1 o 1? :)\n";
    cin>>scelta;
}

bool ric_seq(int k, int num, immobile vet[], int &pos){
    for(pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}

void punto1(int num, immobile vet[]){
    int k1,pos1;
    cout<<"Inserire un primo codice: "; cin>>k1;
    if(ric_seq(k1,num,vet,pos1)){
        int k2,pos2;
        cout<<"Inserire un secondo codice: "; cin>>k2;
        if(ric_seq(k2,num,vet,pos2)){
            immobile i1 = vet[pos1];
            immobile i2 = vet[pos2];
            if((i1.zona == i2.zona || i1.metri_q>i2.metri_q) && strcmp(i1.categoria,"lusso")) cout<<"Condizione Confermata!";
            else cout<<"Condizione non confermata\n";
        }
        else cout<<"Secondo non trovato\n";
    }
    else cout<<"Primo Non trovato\n";
}