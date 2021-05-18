//Credits: Francesco De Rosa 24/11/2020

//Per omettere l'operatore di scoop
using namespace std;

//Libreria per i metodi cin e cout
#include <iostream>

//Libreria per i metodi relativi al rettangolo
#include "../../classi/rettangolo.h"

int main(){
    //dichiarazione di 2 rettangoli
    rettangolo r1,r2,r3;

    //Inizializzazione della base e dell'altezza dei 2 rettangoli
    
    r1.inser_inf();
    r2.inser_inf(r1);
    r3.inser_inf(5.5,10.1);

    //Output Misure, perimetro e area
    cout<<"Base Primo Rettangolo: "<<r1.get_base()<<endl;
    cout<<"Base Secondo Rettangolo: "<<r2.get_base()<<endl;
    cout<<"Base Terzo Rettangolo: "<<r3.get_base()<<endl;
    cout<<"Altezza Primo Rettangolo: "<<r1.get_altezza()<<endl;
    cout<<"Altezza Secondo Rettangolo: "<<r2.get_altezza()<<endl;
    cout<<"Altezza Terzo Rettangolo: "<<r2.get_altezza()<<endl;

    r1.visualizza();
    r2.visualizza();
    r3.visualizza();

    cout<<"Perimetro di r1: "<<r1.perimetro();
    cout<<"Perimetro di r2: "<<r2.perimetro();
    cout<<"Perimetro di r3: "<<r3.perimetro();

    cout<<"Area di r1: "<<r1.area();
    cout<<"Area di r2: "<<r2.area();
    cout<<"Area di r3: "<<r3.area();

    


    return 0;
}