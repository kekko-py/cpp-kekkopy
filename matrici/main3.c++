using namespace std;
#include <iostream>

const int LUN=100;
#include "../funzioni/matrice.h"

int main()
{
    int matrice[LUN][LUN];
    unsigned int righe,colonne;

    inizializza_matrice(matrice, righe, colonne);
    visualizza_matrice(matrice, righe, colonne);

    return 0;
}