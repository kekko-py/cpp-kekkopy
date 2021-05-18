/*
1.1. Stampare il numero massimo di dischi di platino venduti in entrambi gli elenchi e il massimo
numero dei dischi di platino in totale.

1.2. Verificare se due cantanti nei due elenchi, uno nel primo e un altro nel secondo, sono entrambi
cantanti pop e se l'ingaggio del primo è maggiore, minore o uguale a quello del secondo.

1.3. Calcolare l'ingaggio minimo e massimo delle cantanti pop del primo elenco che appartengono a
una tra due generiche case discografiche e che appartengono alla stessa casa discografica del
cantante corrispondente nel secondo elenco.
*/

using namespace std;
#include <iostream>
#include <string>
#include <float.h>

const int LUN=100;
#include "../../../classi_diz/autori_discografici.h"
#include "../../../classi_diz/diz_stat.h"

typedef diz_stat<autore> diz; //Asseganzione di un alias (nome alternativo) al tipo diz_stat<autore>

void menu(int & scelta);
void punto_1(diz d1,diz d2);
void visita_p1(diz d,int &platinum_max);
void punto_2(diz d1,diz d2);
void punto_3(diz d1,diz d2);

int main() 
{
	diz da1,da2; 
	da1.iniz_ord(); 
	da2.iniz_ord(); 
	
	int sc;
	do{
		menu(sc);
		switch(sc)
		{
			case 1: punto_1(da1,da2);break;
			case 2: punto_2(da1,da2);break;
            case 3: punto_3(da1,da2);
		}
	} while(sc>=1 && sc<=3);
	return 0;
}

void menu(int & scelta)
{
	cout<<"P1 - P2 - P3\n";
	cout<<">> ";cin>>scelta;
}

// Stampare il numero massimo di dischi di platino venduti in entrambi gli elenchi e il massimo
// numero dei dischi di platino in totale.
void punto_1(diz d1,diz d2){
    int pla1=0, pla2=0;

    cout<<"PRIMO ELENCO\n";
    visita_p1(d1,pla1);
    cout<<"SECONDO ELENCO\n";
    visita_p1(d2,pla2);

    if(pla1>pla2) cout<<"Il valore Massimo di dischi di platino ricevuti in totale è di: "<<pla1<<endl;
    else cout<<"Il valore Massimo di dischi di platino ricevuti in totale è di: "<<pla2<<endl;      

    cout<<endl;
}

void visita_p1(diz d,int &platinum_max){
    autore a;
    for(int i=0;i<d.get_num();++i)                               //ottiene tramite la chiamata al metodo pubblico get_n per l'oggetto d.
	{
		a=d.get_elem(i); 
        if(a.get_dischi_platino()>platinum_max) platinum_max=a.get_dischi_platino();  
    }

    cout<<"Il valore Massimo di dischi di platino ricevuti in questo elenco è di: "<<platinum_max<<endl;    
}


// Verificare se due cantanti nei due elenchi, uno nel primo e un altro nel secondo, sono entrambi
// cantanti pop e se l'ingaggio del primo è maggiore, minore o uguale a quello del secondo.
void punto_2(diz d1,diz d2){
    int cant1,cant2;
    
    if(d1.ric_bin(cant1))   

        if(d2.ric_bin(cant2))  
	    {
	    	autore a1,a2; 
	    	
	    	a1=d1.get_elem(cant1);
            a1=d2.get_elem(cant2);  
	    	
            if(a1.get_genere()=='P' && a2.get_genere()=='P') cout<<"I cantanti sono entrambi cantanti POP!\n";
            else cout<<"I cantanti non sono entrambi cantanti POP!\n";

            if(a1.get_ingaggio()>a2.get_ingaggio()) cout<<"Il primo cantante ha un ingaggio maggiore del secondo!\n";
            else if(a2.get_ingaggio()>a1.get_ingaggio()) cout<<"Il secondo cantante ha un ingaggio maggiore del primo!\n";
            else cout<<"I due cantanti hanno lo stesso ingaggio!\n";
            
		}
		else
		    cout<<"Secondo Autore non trovato\n";
	
	else
	    cout<<"Primo Autore non trovato\n";
}


// Calcolare l'ingaggio minimo e massimo delle cantanti pop del primo elenco che appartengono a
// una tra due generiche case discografiche e che appartengono alla stessa casa discografica del
// cantante corrispondente nel secondo elenco.
void punto_3(diz d1,diz d2){
	string disc1, disc2;
	cout<<"Inserici la prima generica casa discografica: ";cin>>disc1;
	cout<<"Inserici la seconda generica casa discografica: ";cin>>disc2;
	cout<<endl;
	
	autore a1,a2;
	float ing_min=FLT_MAX,ing_max=FLT_MIN;
	for (int i=0; i<d1.get_num() && i<d2.get_num(); i++)
	{
		a1 = d1.get_elem(i);
		a2 = d2.get_elem(i);
		if ((a1.get_casa_disco()==disc1 || a1.get_casa_disco()==disc2) && a1.get_casa_disco()==a2.get_casa_disco())
		{
			if(a1.get_ingaggio()<ing_min) ing_min= a1.get_ingaggio();
			if(a1.get_ingaggio()>ing_max) ing_max= a1.get_ingaggio();
		}
	}

	cout<<"L'ingaggio massimo \212"<<ing_max<<endl;
	cout<<"L'ingaggio minimo \212"<<ing_min<<endl<<endl;
}

