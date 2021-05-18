using namespace std;
const int LUNS=30;

//------------LIBRERIE-----------------
#include <iostream> //Libreria standard C++
#include <string.h> //Libreria per la gestione delle stringhe
#include <float.h> //Libreria per la gestione dei numeri a virgola mobile
#include "../../classi/comune.h" //Libreria contenente la classe rivista

//------------PROTOTIPI----------------
void inizializza(int l, int &num, comune vet[]); //Prototipo Funz. Inizializza
void punto1(int num1, comune vet1[], int num2, comune vet2[]); //Prototipo Funz. Punto1
void visita_p1(int num, comune vet[], float sup_media, int i); //Prototipo Funz. visita p1
void punto2(int num1, comune vet1[], int num2, comune vet2[]); //Prototipo Funz. Punto2

//-----------FUNZ PICCOLE---------------
void menu(int &scelta){cout<<"Che punto vuoi che io svolga? "; cin>>scelta;} //Funzione menu

//----------FUNZ PRINCIPALE-------------
int main(){
    const int LUN=50; int n1,n2;
    comune v1[LUN], v2[LUN];
    cout<<"PRIMO ELENCO\n";
    inizializza(LUN,n1,v1);
    cout<<"SECONDO ELENCO\n";
    inizializza(LUN,n2,v2);

    int sc; do{
        menu(sc); switch(sc){
            case 1: punto1(n1,v1,n2,v2);break;
            case 2: punto2(n1,v1,n2,v2); 
    }   }while(sc==1||sc==2);
}

//---------FUNZ INIZIALIZZA------------
void inizializza(int l, int &num, comune vet[]){
    do{cout<<"Inserisci il numero di comuni: ";cin>>num;}while(num>l||num<0);
    for (int i = 0; i < num; i++){vet[i].inser_inf();}
}

//----------FUNZ PUNTO1---------------
void punto1(int num1, comune vet1[], int num2, comune vet2[]){
    float sup_media1, sup_media2;
    int tot1,tot2;

    cout<<"PRIMO ELENCO\n";
    visita_p1(num1,vet1,sup_media1,tot1);
    cout<<"SECONDO ELENCO\n";
    visita_p1(num2,vet2,sup_media2,tot2);

    if(sup_media1>sup_media2) cout<<"La superficie media massima è la prima :"<<sup_media1<<endl;
    else if(sup_media2>sup_media1) cout<<"La superficie media massima è la seconda :"<<sup_media2<<endl;
    else cout<<"Le superfici medie sono uguali: "<<sup_media2<<" & "<<sup_media1<<endl;

    cout<<"Il totale complessivo \212 di: "<<tot1+tot2<<__EDG_CONSTEXPR_ENABLED__;
}

//----------FUNZ VISITA P1---------------
void visita_p1(int num, comune vet[], float sup_media, int i){
    int cont_ab_montagna=0; float somma_sup_montagna=0.0;
    int min_ab_genreg, max_ab_genreg; min_ab_genreg = INT_MAX; max_ab_genreg = INT_MIN;
    char genreg1[LUNS],genreg2[LUNS],gentipo[LUNS];

    cout<<"Inserisci 2 generiche regioni: ";cin>>genreg1>>genreg2;
    cout<<"Inserisci un generico tipo: ";cin>>gentipo;

    for(i=0; i<num; i++){
        if(vet[i].get_posizione()=='M') {cont_sup_montagna++; somma_ab_montagna;}
        if((!strcmp(vet[i].get_regione(), genreg1) || !strcmp(vet[i].get_regione(), genreg2)) && !strcmp(vet[i].get_tipo(),gentipo))
        {
            if(vet[i].get_numero_abitanti()<min_ab_genreg) min_ab_genreg=vet[i].get_numero_abitanti();
            else if(vet[i].get_numero_abitanti()>max_ab_genreg) max_ab_genreg=vet[i].get_numero_abitanti();
        }
    }
    if(cont_ab_montagna>0) {sup_media=somma_sup_montagna/cont_ab_montagna; cout<<sup_media;}
    cout<<min_ab_genreg<<max_ab_genreg;
}

//----------FUNZ PUNTO2---------------
void punto2(int num1, comune vet1[], int num2, comune vet2[]){
    int gen_per, gen_ab;
    cin>>gen_per;
    cin>>gen_ab
    for (int i=0; i<num1 && i<num2; i++){
        if(!strcmp(vet1[i].get_regione(),"Campania") && (vet1[i].get_numero_abitanti()>gen_ab || (vet1[i].get_numero_abitanti()>vet2[i].get_numero_abitanti() && strcmp(vet2[i].get_regione(),"Campania"))))
            vet1[i].set_superfice(vet1[i].get_superfice()+vet1[i].get_superfice()*gen_per/100);
    }
    
}
