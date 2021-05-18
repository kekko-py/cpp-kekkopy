using namespace std;
#include <iostream>
#include <float.h>
#include <string.h>

const int LUNS=30;
struct persona{
    int codice;
    float altezza, peso; 
    char lavoro[LUNS], livello;
};

void inizializza(int l, int &num, persona vet[]);
void menu(int &scelta);
bool ric_seq(int k, int num, persona vet[], int &pos);
void punto1(int num1, persona vet1[], int num2, persona vet2[]);
void punto2(int num1, persona vet1[], int num2, persona vet2[]);
void visita_p2(int num, persona vet[], float &peso_min)

int main(){
    const int LUN=50;
    int n1,n2;
    persona v1[LUN],v2[LUN];

    cout<<"...\n";
    inizializza(LUN,n1,v1);
    cout<<"...\n";
    inizializza(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1: punto1(n1,v1,n2,v2);
        case 2: punto2(n1,v1,n2,v2);
        }
    }while(sc==1);
    return 0;
}

void inizializza(int l, int &num, persona vet[]){
    do{
        cout<<"...";
        cin>>num;
    }while(num<0||num>l);
    
    for (int i=0; i<num; i++){
        cin>>vet[i].codice>>vet[i].altezza>>vet[i].lavoro>>vet[i].livello>>vet[i].peso;
    }
}

void menu(int &scelta){
    cin>>scelta;
}

bool ric_seq(int k, int num, persona vet[], int &pos){
    for(pos=0; pos<num && k != vet[pos].codice, pos++);
    return pos<num;
}


void punto1(int num1, persona vet1[], int num2, persona vet2[]){
    int k1,pos1;
    cout<<"Primo codice: "; cin>>k1;
    if(ric_seq(k1,num1,vet1,pos1)){
        int k2,pos2;
        cin>>k2;
        if(ric_seq(k2,num2,vet2,pos2)){
            int k3,pos3;
            cin>>k3;
            if(ric_seq(k3,num1,vet1,pos3)){
                persona p1=vet1[pos1];
                persona p2=vet2[pos2];
                persona p3=vet1[pos3];
                if(p1.altezza<p2.altezza || p1.livello!=p3.livello) cout<<"ok";
                else cout<<"no";
            }
            else cout<<"Terzo non trovato";
        }
        else cout<<"Secondo non trovato";
    }
    else cout<<"Primo non trovato";
}

void punto2(int num1, persona vet1[], int num2, persona vet2[]){
    float pm1,pm2;
    visita_p2(n1,v1,pm1);
    visita_p2(n2,v2,pm2);

    if(pm1>pm2) cout<<"Primo più grande "<<pm1;
    else if(pm2>pm1) cout<<"Secondo più grande "<<pm2;
    else cout<<"Uguali";
}

void visita_p2(int num, persona vet[], float &peso_min){
    peso_min = FLT_MAX;
    int somm_impiegati = 0; int cont_impiegati =0;
    char genl1[LUNS], genl2[LUNS];
    cin>>genl1>>genl2;

    for (int i = 0; i < num; i++){
       if(strcmp(vet[i].lavoro,"impiegato")==0 || strcmp(vet[i].lavoro,genl2) || strcmp(vet[i].lavoro,genl1)){
           if(vet[i].peso<peso_min) peso_min = vet[i].peso;
           ++cont_impiegati;
           somm_impiegati += vet[i].peso;
       }
    }
    cout<<peso_min;
    if(cont_impiegati>0) cout<<peso
    
}

