/*
1) Verificare se due comuni del primo elenco hanno un numero medio di abitanti maggiore 
   di un generico k.

2) Stampare il minimo numero e il massimo numero di abitanti dei comuni medi o piccoli di un generico 
   tipo in un elenco a scelta.
*/

using namespace std;
#include <iostream>
#include <string>

const int LUN=100;
#include "../../../classi_diz/comune2.h"
#include "../../../classi_diz/diz_stat.h"

typedef diz_stat<comune> diz; //Asseganzione di un alias (nome alternativo) al tipo diz_stat<comune>

void menu(int &scelta);
void punto_1(diz d);
void punto_2(diz d1, diz d2);
void menu_el(int &scelta);
void visita_p2(diz d);

int main() 
{
	diz dc1,dc2; 
	dc1.iniz_ord(); 
	dc2.iniz_ord(); 
	
	int sc;
	do{
		menu(sc);
		switch(sc)
		{
			case 1: punto_1(dc1);break;
			case 2: punto_2(dc1,dc2);
		}
	} while(sc>=1 && sc<=2);
	return 0;
}

void menu(int & scelta)
{
	cout<<"P1 - P2\n";
	cout<<">> ";cin>>scelta;
}

/*
1) Verificare se due comuni del primo elenco hanno un numero medio di abitanti maggiore 
   di un generico k.
*/
void punto_1(diz d){
    int med1,med2;
    if(d.ric_bin(med1))
        if(d.ric_bin(med2))
        {
            comune c1,c2;
            int k,media;
            cin>>k;
            c1 = d.get_elem(med1);
            c2 = d.get_elem(med2);
            media = (c1.get_n_abitanti()+c2.get_n_abitanti())/2;
            
            if(media>k) cout<<"Si";
            else cout<<"Nope";

        }else cout<<"Secondo non trovato";
    else cout<<"Primo non trovato";
}


/*
2) Stampare il minimo numero e il massimo numero di abitanti dei comuni medi o piccoli di un generico 
   tipo in un elenco a scelta.
*/
void punto_2(diz d1, diz d2){
    int sc;
	do{
		menu_el(sc);
		switch(sc)
		{
			case 1: visita_p2(d2);break;
			case 2: visita_p2(d2);
		}
	} while(sc>=1 && sc<=2);
}

void menu_el(int &scelta){
    cout<<"el1 - el2\n";
	cout<<">> ";cin>>scelta;
}

void visita_p2(diz d){
    int ab_max=INT_MIN,ab_min=INT_MAX;
    comune c;
    for (int i=0; i<d.get_num(); i++)
    {
        c = d.get_elem(i);
        if(c.get_n_abitanti()<ab_min) ab_min = c.get_n_abitanti();
        if(c.get_n_abitanti()>ab_max) ab_max = c.get_n_abitanti();
    }
    cout<<ab_min<<ab_max;
}
