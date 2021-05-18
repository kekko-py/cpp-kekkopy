/*
contare i nodi foglia

contare
i nodi foglia il cui contenuto � compreso in un generico
intervallo.

Stampare la somma del contenuto
dei nodi foglia e il prodotto del contenuto dei restanti nodi

stampare
la somma degli elementi di livello k
*/

#include "../../funzioni/include.h"
#include "../../funzioni/funct_base.h"
#include "../../class_alb_bin/wrapper.h"
#include "../../class_alb_bin/alb_bin.h"

typedef alb_bin<integer> alb;
typedef nodo<integer> nodo_a;

//prototipi

void menu(int & scelta);

void punto_1(alb a);
void visita_p1(alb a, int &cont);



int main()
{
	alb a1;
	
	a1.inizializza();
	a1.preorder();
	
	int sc;
	
	do
	{
		menu(sc);
		
		switch(sc)
		{
			case 1: punto_1(a1); break;

        }
	}while(sc>=1 && sc<=4);
}


void menu(int & scelta)
{
	cout<<"\ncalcolare i d.f. p1";
	cout<<"\ncalcolare i d.f. p2";
	cout<<"\ncalcolare i d.f. p3";
	cout<<"\ncalcolare i d.f. p4";
	cout<<"\ninserisci la scelta: ";
	cin>>scelta;
}


//contare i nodi foglia

void punto_1(alb a)
{
	int cont=0;
	
	visita_p1(a, cont);
	
	cout<<"\nil numero dei nodi foglia vale: "<<cont<<endl;
}


void visita_p1(alb a, int & cont)
{
	nodo_a *rad;
	rad=a.get_radice();
	
	if(rad!=0)
	{	
		if((*rad).get_albsin().get_radice()==0 && (*rad).get_albdes().get_radice()==0)
		   
		   ++cont;
		
		visita_p1((*rad).get_albsin(), cont);
		visita_p1((*rad).get_albdes(), cont);
	}
}



