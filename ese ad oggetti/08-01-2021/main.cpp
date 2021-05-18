/*
1) verificare se un cantante del primo elenco è di genere rock o jazz e se ha la stessa posizione 
   in classifica di due cantanti del secondo elenco.

2) Calcolare il numero minimo di dischi di platino dei camtanti di un generico genere in entrambi gli
   elenchi e il massimo tra i due minimi
*/

//-----------------------------------------------------------------------------------------------------

using namespace std;

#include <iostream> 
#include <string.h> 
#include <float.h>

const int LUN=100;

#include "../../classi_diz/artisti.h" 
#include "../../../classi_diz/diz_stat.h"

typedef diz_stat<artista> diz;

//-----------------------------------------------------------------------------------------------------

void menu(int &scelta);
void punto_1(diz d1,diz d2);
void punto_2(diz d1,diz d2);
void visita_p2(diz d,int &platinum_min);

//-----------------------------------------------------------------------------------------------------

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
			case 2: punto_2(da1,da2);
		}
	} while(sc>=1 && sc<=2);
	return 0;
}

void menu(int & scelta)
{
	cout<<"P1 - P2\n";
	cout<<">> ";cin>>scelta;
}

//-----------------------------------------------------------------------------------------------------
// 1) verificare se un cantante del primo elenco è di genere rock o jazz e se ha la stessa posizione 
//    in classifica di due cantanti del secondo elenco.
void punto_1(diz d1,diz d2){
   int med1,med2,med3;
   if(d1.ric_bin(med1))
   {
      artista a1;
      a1 = d1.get_elem(med1);
      if(a1.get_genere()=='R' || a1.get_genere()=='J')
         if(d1.ric_bin(med2))
            if(d1.ric_bin(med3))
            {
               artista a2,a3;
               a2 = d2.get_elem(med2);
               a3 = d2.get_elem(med3);

               if(a2.get_posizione()==a1.get_posizione() && a3.get_posizione()==a1.get_posizione()) cout<<"Verificato";
               else "Assolutamente no!";

            }else cout<<"Terzo non trovato";
         else cout<<"Secondo non trovato";
      else cout<<"Non è ne Jazz ne Rock";
   }else cout<<"Primo non trovato";
}

//-----------------------------------------------------------------------------------------------------
// 2) Calcolare il numero minimo di dischi di platino dei camtanti di un generico genere in entrambi gli
//    elenchi e il massimo tra i due minimi
void punto_2(diz d1,diz d2){
    int pla1=0, pla2=0;

    cout<<"PRIMO ELENCO\n";
    visita_p2(d1,pla1);
    cout<<"SECONDO ELENCO\n";
    visita_p2(d2,pla2);

    if(pla1>pla2) cout<<"Il valore Massimo dei minimi in totale \212 di: "<<pla1<<endl;
    else cout<<"Il valore Massimo dei minimi in totale \212 di: "<<pla2<<endl;      

    cout<<endl;
}

//-----------------------------------------------------------------------------------------------------

void visita_p2(diz d,int &platinum_min){
    artista a;
    char gen_g;
    cin>>gen_g;

    for(int i=0;i<d.get_num();++i)                              
	{
		a=d.get_elem(i); 
      if(gen_g==a.get_genere())
         if(a.get_dischi_platino()<platinum_min) platinum_min=a.get_dischi_platino();  
   }

    cout<<"Il valore Minimo di dischi di platino ricevuti in questo elenco è di: "<<platinum_min<<endl;    
}

//-----------------------------------------------------------------------------------------------------