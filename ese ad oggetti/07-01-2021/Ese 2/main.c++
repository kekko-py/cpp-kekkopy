/*
2.1. Stampare la superficie media e il numero totale degli abitanti dei comuni di montagna, il minimo e
il massimo numero di abitanti tra i comuni di una tra due generiche regioni di un generico tipo in
ciascun elenco e il totale complessivo nei due elenchi e il massimo tra le due superfici medie

2.2. Verificare se due comuni del secondo elenco hanno superficie minima compresa in un generico
intervallo e appartengono ad una generica regione

2.3. Stampare la superficie minima e quella massima dei comuni che si trovano in pianura o hanno
superficie superiore ad un generico valore in entrambi gli elenchi e il minimo tra le due superfici
minime

2.4. Verificare se un comune del primo elenco si trova in pianura o ha superficie compresa nell'
intervallo che ha come estremi la superficie di due comuni del secondo elenco.

2.5. [Facoltativo] Verificare se due comuni di un elenco a scelta hanno superficie media superiore a
quella media dei comuni dell' altro elenco
*/

using namespace std;
#include <iostream>
#include <string>
#include <float.h>

const int LUN=100;
#include "../../../classi_diz/comune.h"
#include "../../../classi_diz/diz_stat.h"

typedef diz_stat<comune> diz; //Asseganzione di un alias (nome alternativo) al tipo diz_stat<comune>

void menu(int &scelta);
void punto_1(diz d1,diz d2);
void visita_p1(diz d,int &abitanti_max, int &abitanti_min);
void punto_2(diz d);
void punto_3(diz d1,diz d2);
void visita_p3(diz d,float &sup_min);
void punto_4(diz d1,diz d2);
//void punto_5(diz d1, diz d2);
//void menu_el(int &scelta);

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
			case 1: punto_1(dc1,dc2);break;
			case 2: punto_2(dc2);break;
            case 3: punto_3(dc1,dc2);break;
            case 4: punto_4(dc1,dc2);break;
            //case 5: punto_5(dc1,dc2);
		}
	} while(sc>=1 && sc<=5);
	return 0;
}

void menu(int & scelta)
{
	cout<<"P1 - P2 - P3 - P4 - P5\n";
	cout<<">> ";cin>>scelta;
}

// 2.1. Stampare la superficie media e il numero totale degli abitanti dei comuni di montagna,
// il minimo e il massimo numero di abitanti tra i comuni di una tra due generiche regioni di un generico tipo in
// ciascun elenco e il totale complessivo nei due elenchi e il massimo tra le due superfici medie
void punto_1(diz d1,diz d2){

    int ab_max1=INT_MIN,ab_max2=INT_MIN,ab_min1=INT_MAX,ab_min2=INT_MAX;
    visita_p1(d1,ab_max1, ab_min1);
    visita_p1(d2,ab_max2, ab_min2);

    if(ab_max1>ab_max2) cout<<"Il massimo numero di abitanti \212 di "<<ab_max1<<endl;
    else cout<<"Il massimo numero di abitanti \212 di "<<ab_max2<<endl;

    if(ab_min1>ab_min2) cout<<"Il minimo numero di abitanti \212 di "<<ab_min1<<endl;
    else cout<<"Il minimo numero di abitanti \212 di "<<ab_min2<<endl;

    cout<<endl;
}

void visita_p1(diz d,int &abitanti_max, int &abitanti_min){

    float sup_som=0;
    int sup_cont=0,ab_mont=0;

    string reg1,reg2,g_tip;

    cin>>reg1>>reg2>>g_tip;

    for (int i=0; i<d.get_num(); i++)
    {
        comune c;
        c = d.get_elem(i);

        if(c.get_posizione()=='M'){ab_mont+=c.get_abitanti(); sup_som+=c.get_superfice(); ++sup_cont;}

        if(c.get_tipo()==g_tip && (c.get_regione()==reg1 || c.get_regione()==reg2))
        {
            if(c.get_abitanti()>abitanti_max) abitanti_max=c.get_abitanti();
            if(c.get_abitanti()<abitanti_min) abitanti_min=c.get_abitanti();
        }
    }
    if(sup_cont>0) cout<<sup_som/sup_cont;
    cout<<abitanti_max;
    cout<<abitanti_min;
}


// 2.2. Verificare se due comuni del secondo elenco hanno superficie minima compresa in un generico
// intervallo e appartengono ad una generica regione
void punto_2(diz d){
    int com1,com2;
    if(d.ric_bin(com1))
        if(d.ric_bin(com2))
        {
            comune c1,c2,c;
            c1 = d.get_elem(com1);
            c2 = d.get_elem(com2);
            float inf,sup,min_super;
            string gen_r;
            cin>>inf>>sup;
            cin>>gen_r;
            
            if(c1.get_superfice()<c2.get_superfice()){min_super=c1.get_superfice(); c=c1;} 
            else {min_super=c2.get_superfice(); c=c2;}

            if(min_super>=inf&&min_super<=sup && c.get_regione()==gen_r) cout<<"OK";
            else cout<<"RIP bro";

        }else cout<<"Secondo non trovato";
    else cout<<"primo non trovato";
}


// 2.3. Stampare la superficie minima e quella massima dei comuni che si trovano in pianura o hanno
// superficie superiore ad un generico valore in entrambi gli elenchi e il minimo tra le due superfici
// minime
void punto_3(diz d1,diz d2){
    float sup_m1=FLT_MAX, sup_m2=FLT_MAX;
    visita_p3(d1, sup_m1);
    visita_p3(d2, sup_m2);

    if(sup_m1<sup_m2) cout<<sup_m1;
    else cout<<sup_m2;
}

void visita_p3(diz d,float &sup_min){
    float sup_max=FLT_MIN,gen_sup;
    comune c;
    cin>>gen_sup;
    for (int i=0; i<d.get_num(); i++)
    {
        c = d.get_elem(i);
        if(c.get_posizione()=='P' || c.get_superfice()>gen_sup)
        {
            if(c.get_superfice()>sup_max) sup_max=c.get_superfice();
            if(c.get_superfice()<sup_min) sup_min=c.get_superfice();
        }
    }

    cout<<sup_max;
    cout<<sup_min;
}


// 2.4. Verificare se un comune del primo elenco si trova in pianura o ha superficie compresa nell'
// intervallo che ha come estremi la superficie di due comuni del secondo elenco.
void punto_4(diz d1,diz d2){
    int com1,com2,com3;
    if(d1.ric_bin(com1))
        if(d2.ric_bin(com2))
            if(d2.ric_bin(com3))
            {
                comune c1,c2,c3;
                c1=d1.get_elem(com1);
                c2=d2.get_elem(com2);
                c3=d2.get_elem(com3);

                float c1_sup,inf,sup;
                c1_sup = c1.get_superfice();
                inf = c2.get_superfice();
                sup = c3.get_superfice();

                if(c1.get_posizione()=='P' || (c1_sup>=inf&&c1_sup<=sup))
                    cout<<"OK";
                else cout<<"Rip brp";

            }else cout<<"Terzo non trovato";
        else cout<<"Secondo non trovato";
    else cout<<"Primo non trovato";
}