// Il numero di sculture realizzate da Bernini o da Donatello in un elenco a scelta
// De Rosa Francesco 02/12/2020
using namespace std; //Spazio tra i nomi std:: per cout e cin

//------------LIBRERIE-----------------
#include <iostream> //Libreria standard C++
#include <string.h> //Libreria per la gestione delle stringhe
#include <float.h> //Libreria per la gestione dei numeri a virgola mobile
#include "../../classi/opere_art.h" //Libreria contenente la classe rivista

//------------PROTOTIPI----------------
void inizializza(int l, int &num, opera vet[]); //Prototipo Funz. Inizializza
void punto1(int num1, opera vet1[], int num2, opera vet2[]); //Prototipo Funz. Punto1
void visita_p1(int num, opera vet[]); //Prototipo Funz. visita p1
void punto2(int num1, opera vet1[], int num2, opera vet2[]); //Prototipo Funz. Punto2
void visita_p2(int num, opera vet[], float &val_min); //Prototipo Funz. visita p2

//-----------FUNZ PICCOLE---------------
void menu(int &scelta){cout<<"Che punto vuoi che io svolga? "; cin>>scelta;} //Funzione menu
void menu_el(int &scelta_el){cout<<"Elenco 1 o 2? ";cin>>scelta_el;}

//----------FUNZ PRINCIPALE-------------
int main(){
    const int LUN=30; int n1,n2;
    opera v1[LUN], v2[LUN];
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
void inizializza(int l, int &num, opera vet[]){
    do{cout<<"Inserisci il numero di opere: ";cin>>num;}while(num>l||num<0);
    for (int i = 0; i < num; i++){vet[i].inser_inf();}
}

//----------FUNZ PUNTO1---------------
void punto1(int num1, opera vet1[], int num2, opera vet2[]){
    int sc;do{ switch (sc){
        case 1: visita_p1(num1,vet1);break;
        case 2: visita_p1(num2,vet2);
    }}while(sc!=1&&sc!=2);
}

//----------FUNZ VISITA P1---------------
void visita_p1(int num, opera vet[]){
    int cont=0;
    for (int i=0; i<num; i++){
        if(!strcmp(vet[i].get_autore(),"Bernini") || !strcmp(vet[i].get_autore(),"Donatello")) cont++;
    }
    cout<<"Il numero di sculture realizzate da Bernini o da Donatello in un elenco a scelta \212 di:"<<cont<<endl;
}

//----------FUNZ PUNTO2---------------
void punto2(int num1, opera vet1[], int num2, opera vet2[]){
    float min_val1,min_val2;
    cout<<"PRIMO ELENCO\n";
    visita_p2(num1,vet1,min_val1);
    cout<<"SECONDO ELENCO\n";
    visita_p2(num2,vet2,min_val2);

    if(min_val1<min_val2) cout<<"Il primo minimo \212 il piu' piccolo: "<<min_val1<<endl;
    else if(min_val2<min_val1) cout<<"Il secondo minimo \212 il piu' piccolo: "<<min_val2<<endl;
    else cout<<"I 2 valori minimi sono uguali: "<<min_val2<<" & "<<min_val1<<endl;
}

//----------FUNZ VISITA P2---------------
void visita_p2(int num, opera vet[], float &val_min){
    float val_max=FLT_MIN; val_min=FLT_MAX;
    char gen_tipo; int inf,sup;
    cout<<"Inserisci un generico tipo: ";cin>>gen_tipo;
    cout<<"Inserisci gli estremi di un generico intervallo: ";cin>>inf>>sup;
    
    for (int i=0; i<num; i++){
        if(vet[i].get_tipo()==gen_tipo && vet[i].get_anno()>=inf&&vet[i].get_anno()<=sup){
            if(vet[i].get_valore()<val_min) val_min=vet[i].get_valore();
            if(vet[i].get_valore()>val_max) val_max=vet[i].get_valore();
        }
    }
    
    cout<<"Il minimo tra i valori \212 di: "<<val_min<<endl;
    cout<<"Il massimo tra i valori \212 di: "<<val_max<<endl;
}
