using namespace std;
#include <iostream>

// ------------- VAR. GLOBAL -----------------
const int LUNS=30;
struct prodotto{
    int codice;
    char tipo[LUNS];
    float prezzo;
    float peso;
};
//_____________________________________________________________________
// ----------- PROTOTIPI FUNCT ----------------

void inizializza_elenco(int l, int &num, prodotto vet[]);
void menu(int &scelta);

bool ric_seq(int k, int num, prodotto vet[], int &pos);

void punto1(int num1, prodotto vet1[], int num2, prodotto vet2[]);
void menu_el(int &scelta_el);
void verifica_p1(int num1, prodotto vet1[], int num2, prodotto vet2[]);

void punto2(int num, prodotto vet[], int num2, prodotto vet2[]);

void punto3(int num1, prodotto vet1[], int num2, prodotto vet2[]);
void visita_p3(int num, prodotto vet[], float media);

void punto4(int num1, prodotto vet1[], int num2, prodotto vet2[]);
void visita_p4(int num, prodotto vet[]);

void punto5(int l, int num1, prodotto vet1[], int num2, prodotto vet2[]);

//_____________________________________________________________________
// -------------- MAIN FUNCT -----------------
int main(){
    const int LUN=50;
    int n1,n2; prodotto v1[LUN],v2[LUN];

    cout<<"Inserisci 2 Elenchi di Prodotti Aziendali!\n";

    cout<<"[PRIMO ELENCO]\n";
    inizializza_elenco(LUN,n1,v1);
    cout<<"[SECONDO ELENCO]\n";
    inizializza_elenco(LUN,n2,v2);

    int sc;
    do{
        menu(sc);
        switch (sc)
        {
        case 1:
            punto1(n1,v1,n2,v2);
            break;
        case 2:
            punto2(n1,v1,n2,v2);
            break;
        case 3:
            punto3(n1,v1,n2,v2);
            break;
        case 4:
            punto4(n1,v1,n2,v2);
            break;
        case 5:
            punto5(LUN,n1,v1,n2,v2);    
        }
    }while (sc>=1||sc<=3);

    return 0;
}
//_____________________________________________________________________
//------------------ FUNCT INIZIALIZZA ------------------
void inizializza_elenco(int l, int &num, prodotto vet[]){
    do{
        cout<<"Quanti Prodotti Aziendali vorresti Aggiungere?\n";
        cin>>num;
        cout<<endl;
    }while (num<0||num>l);
    
    for (int i=0; i<num; i++){
        cout<<"\nRegistrazione prodotto N^"<<i+1<<"\n\n";	
        cout<<"CODICE: ";
		cin>>vet[i].codice;
        cout<<"TIPO: ";
		cin>>vet[i].tipo;
        cout<<"PREZZO: ";
		cin>>vet[i].prezzo;
        cout<<"PESO: ";
		cin>>vet[i].peso;
		cout<<endl<<"____________________________ \n\n";
    }
}
//______________________________________________________________________
// ----------- FUNCT MENU -----------
void menu(int &scelta){
    cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

  	cout<<"1] DF PUNTO 1\n";
  	cout<<"2] DF PUNTO 2\n";
    cout<<"3] DF PUNTO 3\n";
    cout<<"3] DF PUNTO 4\n";
    cout<<"3] DF PUNTO 5\n";
  
  	cout<<">> ";
  	cin>>scelta;
  
  	cout<<"\n\n";
}
//______________________________________________________________________
// -------------- SEQUENTIAL SEARCH FUNCT ---------
bool ric_seq(int k, int num, prodotto vet[], int &pos){
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}
//______________________________________________________________________
// ------------ FUNCT PUNTO1 -------------
void punto1(int num1, prodotto vet1[], int num2, prodotto vet2[]){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
        case 1:
            verifica_p1(num1,vet1,num2,vet2);
            break;
        case 2:
            verifica_p1(num2,vet2,num1,vet1);
        }
    }while (sc_el!=1&&sc_el!=2);
}
//______________________________________________________________________
// ------------ FUNCT MENU ELENCO -------------
void menu_el(int &scelta_el){
	cout<<"In quale elenco vuoli che lavori? \n\n";

  	cout<<"1] Primo\n";
  	cout<<"2] Secondo\n";

    cout<<">> ";
  	cin>>scelta_el;
  
  	cout<<"\n\n";
}
//______________________________________________________________________
// ------------ FUNCT VISITA_P1 -------------
void verifica_p1(int num1, prodotto vet1[], int num2, prodotto vet2[]){
    int k1,pos1;
    cout<<"Inserisci Il codice di un prodotto: "; cin>>k1;
    if(ric_seq(k1,num1,vet1,pos1)){
        int k2,pos2;
        cout<<"Inserisci Il codice di un prodotto: "; cin>>k1;
        if(ric_seq(k2,num2,vet2,pos2)){
            prodotto p1=vet1[pos1];
            prodotto p2=vet2[pos2];
            if(p1.peso>p2.peso) cout<<"Condizione Confermata\n";
            else cout<<"Condizione Non confermata\n";
        }
        else cout<<"Secondo Non trovato\n";
    }
    else cout<<"Primo non trovato\n";   
}
//______________________________________________________________________
// ------------ FUNCT PUNTO2 -------------
void punto2(int num1, prodotto vet1[], int num2, prodotto vet2[]){
    int k1,pos1;
    cout<<"Inserisci Il codice di un prodotto: "; cin>>k1;
    if(ric_seq(k1,num1,vet1,pos1)){
        int k2,pos2;
        cout<<"Inserisci Il codice di un prodotto: "; cin>>k2;
        if(ric_seq(k2,num1,vet1,pos2)){
            int k3,pos3;
            cout<<"Inserisci Il codice di un prodotto: "; cin>>k3;
            if(ric_seq(k3,num2,vet2,pos3)){
               prodotto p1 = vet1[pos1];
               prodotto p2 = vet1[pos2];
               prodotto p3 = vet2[pos3];

                float prezzo_med = (p1.prezzo+p2.prezzo)/2; 

                if(prezzo_med>p3.prezzo) cout<<"Condizione Confermata\n";
                else cout<<"Condizione non confermata\n";
            }
            else cout<<"Terzo non trovato\n";
        }
        else cout<<"Secondo non trovato\n";
    }
    else cout<<"Primo non trovato\n";
}
//______________________________________________________________________
// ------------ FUNCT PUNTO3 -------------
void punto3(int num1, prodotto vet1[], int num2, prodotto vet2[]){
    float media_pes1, media_pes2;
    
    cout<<"[PRIMO ELENCO]";
    visita_p3(num1,vet1,media_pes1);
    cout<<"[SECONDO ELENCO]";
    visita_p3(num2,vet2,media_pes2);

    if(media_pes1<media_pes2) cout<<"La media minore è la prima: "<<media_pes1<<endl;
    else if(media_pes2<media_pes1) cout<<"La media minore è la seconda: "<<media_pes2<<endl;
    else cout<<"La medie sono uguali: "<<media_pes2<<" e "<<media_pes1<<endl;
}
//______________________________________________________________________
// ------------ FUNCT VISITA_P3 -------------
void visita_p3(int num, prodotto vet[], float media){
    float sum_pes = 0;
    int i;
    for (i=0; i<num; i++){
        sum_pes += vet[i].peso;
    }
    media = sum_pes/i;
    cout<<"La media \212: "<<media<<endl;    
}
//______________________________________________________________________
// ------------ FUNCT PUNTO4 -------------
void punto4(int num1, prodotto vet1[], int num2, prodotto vet2[]){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
        case 1:
            visita_p4(num1,vet1);
            break;
        case 2:
            visita_p4(num2,vet2);
        }
    }while (sc_el!=1&&sc_el!=2);
}
//______________________________________________________________________
// ------------ FUNCT VISITA_P3 -------------
void visita_p4(int num, prodotto vet[]){
    int k,pos;
    cout<<"Inserisci un codice di un prodotto, dell'elenco scelto\n"; cin>>k;
    if(ric_seq(k,num,vet,pos)){
        cout<<"Modifica elemento "<<k<<endl;
        cout<<"CODICE: ";
		cin>>vet[pos].codice;
        cout<<"TIPO: ";
		cin>>vet[pos].tipo;
        cout<<"PREZZO: ";
		cin>>vet[pos].prezzo;
        cout<<"PESO: ";
		cin>>vet[pos].peso;
    }
    else cout<<"Elemento non trovato!!\n"; 
}
//______________________________________________________________________
// ------------ FUNCT PUNTO5 -------------
void punto5(int l, int num1, prodotto vet1[], int num2, prodotto vet2[]){
    int sc_el;
    do{
        menu_el(sc_el);
        switch (sc_el)
        {
        case 1:
            inizializza_elenco(l,num1,vet1);
            break;
        case 2:
            inizializza_elenco(l,num2,vet2);
        }
    }while (sc_el!=1&&sc_el!=2);
}