using namespace std;
#include <iostream>
#include <iostream.h>

const int LUNS=30;
struct calciatore{
    int codice;
    int goal;
    float ingaggio;
    char cognome[LUN];
    char nome[LUN];
    char squadra[LUN];
    char ruolo[LUN];
};

void inizializza(int l, int &num, calciatore vet[]);
void menu(int &scelta);
void punto1(int num1, calciatore vet1[], int num1, calciatore vet1[]);
void visita_p1(int num, calciatore vet[], int &cont_pa);

int main(){
    const int LUN=100;
    int n1,n2,sc,sc_el;
    calciatore v1[LUN], v2[LUN];
}