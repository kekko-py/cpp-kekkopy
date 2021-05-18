using namespace std;
#include <iostream>
#include <float.h>
#include "../../classi/corpo_c.h"
//-------------------------------------
void inizializza(int l, int &num, corpo_celeste vet[]);
void menu(int &scelta){cout<<"Che punto vuoi che io svolga? "; cin>>scelta;}
void menu_el(int &scelta_el){cout<<"Elenco 1 o 2? ";cin>>scelta_el;}
void visita_p1(int num, corpo_celeste vet[]);
void punto1(int num1, corpo_celeste vet1[], int num2, corpo_celeste vet2[]){int sc_el; do{if(sc_el==1) visita_p1(num1,vet1); else if(sc_el==2) visita_p1(num2,vet2);}while(sc_el!=1&&sc_el!=2);}
void punto2(int num, corpo_celeste vet[]);
//-------------------------------------
int main(){
    const int LUN=30;
    int n1,n2;
    corpo_celeste v1[LUN],v2[LUN];

    inizializza(LUN,n1,v1);
    inizializza(LUN,n2,v2);
    
    int sc; do{ menu(sc);
        switch (sc){
            case 1: punto1(n1,v1,n2,v2);break;
            case 2: punto2(n2,v2);
        }
    }while(sc==1||sc==2);
    return 0;
}
//-------------------------------------
void inizializza(int l, int &num, corpo_celeste vet[]){
    do{cout<<"Inserisci il numero di Corpi Celesti: ";cin>>num;}while(num>l||num<0);
    for (int i = 0; i < num; i++){vet[i].inser_inf();}
}
//-------------------------------------
void visita_p1(int num, corpo_celeste vet[]){
    float somma,inf,sup;int cont;
    cout<<"Inserisci gli estremi di un intervallo decimale: ";cin>>inf>>sup;
    cont=somma=0; 
    for (int i=0; i<num; i++){
        if(vet[i].get_massa()<inf||vet[i].get_massa()>sup){somma += vet[i].get_distanza_terra();cont++}
    }
    if(cont>0) cout<<"La distanza media dei pianeti la cui massa è esterna a un generico intervallo in un elenco a scelta \212 "<<somma/cont<<endl;    
}
//-------------------------------------
void punto2(int num, corpo_celeste vet[]){
    float massa_min, massa_max;
    massa_max = FLT_MIN;
    massa_min = FLT_MAX;
    char gen_t1, gen_t2;
    cout<<"Inserisci 2 Generici tipi: ";cin>>gen_t1>>gen_t2;

    for (int i=0; i<num; i++){
        if(vet[i].get_tipo() == gen_t1 || vet[i].get_tipo() == gen_t2)
    }
    

}