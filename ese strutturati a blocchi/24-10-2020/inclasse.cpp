//Verificare se un giocatore del primo elenco e uno del secondo elenco hanno lo stesso ruolo
// e giocano nella stessa squadra stampando anche il loro ingaggio medio.

using namespace std;

#include <iostream>
#include <string.h>

const int LUNS=30;

struct calciatore{
	int goal;
    char nazionalita[LUNS];
    char ruolo[LUNS];
    float ingaggio;
}

void inizializza_elenco(int l, int &num, calciatore vet[]);
void menu(int &scelta);

void punto2(int num1, calciatore vet1[], int num2, calciatore vet2[]);
bool ric_seq(int k. int num, calciatore vet[], int &pos);


int main(){
    return 0;
}

bool ric_seq(int k int num, calciatore vet[], int &pos){
    for (int pos = 0; pos<num && k!= vet[pos].codice; pos++);
    return pos<num;
}

void punto2(int num1, calciatore vet1[], int num2, calciatore vet2[]){
    int k1, pos1;
    cout<<"...";
    cin>>k1;
    if(ric_seq(k1,num1,ve1,pos1))
    {
        int k2, pos2;
        cout<<"d";
        cin>>k2;
        if (ric_seq(k2,num2,pos2))
        {
            calciatore c1, c2;
            c1=vet1[pos1];
            c2=vet2[pos2];
            if(strcmp(c1.ruolo, c2.ruolo)==0 && strcmp(c1.squadra, c2.squadra)==0)
                cout<<"ok";
            else 
                cout<<"no";
            cout<<((c1.ingaggio+c2.ingaggio)/2)<<endl;
        }
        else
            cout<<"secondo non trovato";
    }
    else
        cout<<"primo non trovato";
}