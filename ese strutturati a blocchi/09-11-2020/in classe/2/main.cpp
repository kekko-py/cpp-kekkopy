using namespace std;
#include <iostream>
#include <string.h>

const int LUNS=30;
struct volo{
    int codice;
    char nome_compagnia[LUNS];
    char tipo_aereo;
    int durata_volo; 
    int capienza;
};

void inizializza_elenco(int l, int &num, volo vet[]);
void menu(int &scelta);
bool ric_seq(int k, int num, volo vet[], int &pos);
void punto1(int num1, volo vet1[], int num2, volo vet2[]);

int main(){
    const int LUN=50;
    int n1,n2;
    volo v1[LUN],v2[LUN];

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
            punto1(n1,v1,n2,v2);
        }
    }while(sc==1);
    return 0;
}

void inizializza_elenco(int l, int &num, volo vet[]){
    do{
        cout<<"Quanti voli vorresti Aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"CODICE: ";cin>>vet[i].codice;
        cout<<"NOME COMPAGNIA: ";cin>>vet[i].nome_compagnia;
        cout<<"TIPO AEREO: ";cin>>vet[i].tipo_aereo;
        cout<<"DURATA VOLO: "; cin>>vet[i].durata_volo;
        cout<<"CAPIENZA: "; cin>>vet[i].capienza;
    }
}

void menu(int &scelta){
    cout<<"1 o 1? :)\n";
    cin>>scelta;
}

bool ric_seq(int k, int num, volo vet[], int &pos){
    for(pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}

void punto1(int num1, volo vet1[], int num2, volo vet2[]){
    int k1,pos1;
    cout<<"Inserisci un 1* codice: ";cin>>k1;
    if(ric_seq(k1,num1,vet1,pos1)){
        int k2,pos2;
        cout<<"Inserici un 2* codice: ";cin>>k2;
        if(ric_seq(k2,num1,vet1,pos2)){
            int k3,pos3;
            cout<<"Inserici un 3* codice: ";cin>>k3;
            if(ric_seq(k3,num2,vet2,pos3)){
                volo v1 = vet1[pos1];
                volo v2 = vet1[pos2];
                volo v3 = vet2[pos3];
                if(v1.durata_volo<v3.durata_volo&&v2.durata_volo<v3.durata_volo) cout<<"Condizione confermata\n";
                else cout<<"Condizione Non confermata\n";
            }
            else cout<<"Terzo non trovato\n";
        }
        else cout<<"Secondo non trovato\n";
    }
    else cout<<"Primo non trovato\n";
}