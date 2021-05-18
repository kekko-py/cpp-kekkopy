using namespace std;

#include <iostream>
#include <float.h>

// ----------------- Global V. ----------------
const int LUNS=30;
struct corpo_c{
    int codice;
    char nome[LUNS];
    char tipo;
    float massa;
    float distanza_sole;
};

// --------------- Funct p. ----------------

void inizializza_elenco(int l, int &num, corpo_c vet[]);
void menu(int &scelta);
bool ric_seq(int k, int num, corpo_c vet[], int &pos);
void punto1(int num, corpo_c vet[]);
void punto2(int num, corpo_c vet[]);

// -------------- Main ------------------
int main(){
    const int LUN=50;
    int n1,n2; corpo_c v1[LUN],v2[LUN];

    cout<<"Inserisci 2 Elenchi di Corpi Celesti!\n";

    cout<<"[PRIMO ELENCO]\n";
    inizializza_elenco(LUN,n1,v1);
    cout<<"[SECONDO ELENCO]\n";
    inizializza_elenco(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc){
            case 1:punto1(n2,v2);
        }
    }while (sc==1);
    return 0;
}
//------------------ FUNCT INIZIALIZZA ------------------
void inizializza_elenco(int l, int &num, corpo_c vet[]){
    do{
        cout<<"Quanti corpi celesti vorresti aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
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
        cout<<"MASSA: ";
		cin>>vet[i].massa;
		cout<<endl<<"____________________________ \n\n";
    }
}
// ----------- FUNCT MENU -----------
void menu(int &scelta){
    cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1\n";
  	cout<<"2] DF PUNTO 2\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";
}
// -------------------- Funct Sequential Search -------------
bool ric_seq(int k, int num, corpo_c vet[], int &pos){
    for(int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}
// ------------------- Funct P1 ------------------
void punto1(int num, corpo_c vet[]){
    int k1,k2;
    int pos1,pos2;
    cout<<"Inserisci 2 Codici di 2 elementi nel secondo elenco: "; cin>>k1>>k2; 

    if (ric_seq(k1,num,vet,pos1))
        if (ric_seq(k2,num,vet,pos2))
            if (vet[pos1].tipo == vet[pos2].tipo && vet[pos1].massa > vet[pos2].massa)
                cout<<"Condizione verificata\n";
            else
                cout<<"Condizione non verificata\n";  
        else
            cout<<"2' non trovato\n";
    else
        cout<<"1' non trovato\n";
}
// ------------------ Funct P2 -----------------
void punto2(int num, corpo_c vet[]){

    float max_dist = FLT_MIN;
    float min_dist = FLT_MAX;
    float sum_dist = 0;
    float count_dist = 0;

    for (int i=0; i<num; i++){

        if(vet[i].tipo == 'S' || vet[i].tipo == 's')
            if(vet[i].distanza_sole > max_dist) max_dist = vet[i].distanza_sole;
        
        else if(vet[i].tipo == 'P' || vet[i].tipo == 'p'){
            if(vet[i].distanza_sole < min_dist) min_dist = vet[i].distanza_sole;
            count_dist++;
            sum_dist += vet[i].distanza_sole;
        }
    }

    cout<<"La distanza Massima dal sole delle stelle: "<<max_dist<<endl;
    cout<<"La distanza Minima dal sole dei Pianeti: "<<min_dist<<endl;
    if(count_dist>0) cout<<"La Distanza media dal sole dei pianeti: "<<sum_dist/count_dist<<endl;
}