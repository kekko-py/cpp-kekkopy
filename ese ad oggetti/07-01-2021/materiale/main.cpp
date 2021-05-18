using namespace std;
#include <iostream>
#include <string>
#include <float.h>

const int LUN=100;
#include "opera2.h"
#include "diz_stat.h"

/*Sono dati due elenchi di opere d�arte descritte da:  codice, nome, tipo (dipinto, scultura), autore, valore e anno di realizzazione. Calcolare:
1. Verificare se due opere d'arte del primo elenco hanno stesso autore e prezzo medio superiore al prezzo di un' altra opera del secondo elenco.
2. Calcolare il valore minimo e quello massimo delle opere di un generico tipo realizzate in un generico intervallo di tempo, in entrambi gli elenchi 
e il minimo tra i due valori minimi */

typedef diz_stat<opera> diz; //Asseganzione di un alias (nome alternativo) al tipo diz_stat<opera>

void menu(int & scelta);

void punto_1(diz d1,diz d2);

void punto_2(diz d1,diz d2);
void visita_p2(diz d,float & val_min);




int main() 
{
	diz do1,do2; //Dichiarazione due oggetti istanze della classe diz_stat<opera>
	
	do1.iniz_ord(); //Chiamata al metodo iniz_ord per l'oggetto do1 istanza della classe diz_stat
	do2.iniz_ord(); ////Chiamata al metodo iniz_ord per l'oggetto do2  istanza della classe diz_stat
	
	
	int sc;
	do
	{
		menu(sc);
		switch(sc)
		{
			case 1: punto_1(do1,do2); break;
			case 2: punto_2(do1,do2);
		}
	} while(sc>=1 && sc<=2);
	return 0;
}




void menu(int & scelta)
{
	cout<<"1).........\n";
	cout<<"2).........\n";
	cout<<"fai la tua scelta \n";
	cin>>scelta;
}


/*1. Verificare se due opere d'arte del primo elenco hanno stesso autore e prezzo medio superiore al prezzo di un' altra opera del secondo elenco.*/
void punto_1(diz d1,diz d2)
{
	int med1,med2,med3;
	//Ricerca della prima opera nel primo dizionario
	if(d1.ric_bin(med1))        //chiamata al metodo ric_bin per l'oggetto d1 istanza della classe diz_stat
        //Ricerca della seconda opera nel primo dizionario
      if(d1.ric_bin(med2))    //chiamata al metodo ric_bin per l'oggetto d1 istanza della classe diz_stat
        //Ricerca della terza opera nel secondo dizionario
        if(d2.ric_bin(med3))  //chiamata al metodo ric_bin per l'oggetto d2 istanza della classe diz_stat
	    {
	    	opera o1,o2,o3;    //dichiarazione tre oggetti opera
	    	
	    	o1=d1.get_elem(med1);  //Assegnazione a o1 della prima opera trovata nel primo dizionario alla posizione med1 con la prima ricerca
	    	o2=d1.get_elem(med2);  //Assegnazione a o2 della seconda opera trovata nel secondo dizionario alla posizione med2 con la seconda ricerca
	    	o2=d2.get_elem(med3);  //Assegnazione a o3 della terza opera trovata nel secondo dizionario alla posizione med3 con la terza ricerca
	    	
	    	if(o1.get_autore()==o2.get_autore() && (o1.get_valore()+o2.get_valore())/2 >o3.get_valore())
	    	  cout<<"OK! \n";
	    	else
	    	  cout<<"NO! \n";
		}
		else
		    cout<<"terza opera non trovata \n";
	
	  else
	    cout<<"seconda opera non trovata \n";
	
	else
	  cout<<"prima opera non trovata";	
}

/* 2. Calcolare il valore minimo e quello massimo delle opere di un generico tipo realizzate in un generico intervallo di tempo, in entrambi gli elenchi 
e il minimo tra i due valori minimi */


void punto_2(diz d1,diz d2)
{
	float val_min1,val_min2;
	
	visita_p2(d1,val_min1);
	visita_p2(d2,val_min2);
	
	if(val_min1<val_min2)
	  cout<<"il minimo tra i due valori minimi e' "<<val_min1<<'n';
	else
	  if(val_min1>val_min2)
	    cout<<"il minimo tra i due valori minimi e' "<<val_min2<<'n';
}

/* 2. Calcolare il valore minimo e quello massimo delle opere di un generico tipo realizzate in un generico intervallo di tempo, in entrambi gli elenchi 
e il minimo tra i due valori minimi */

void visita_p2(diz d,float & val_min)
{
	float val_max;
	val_min=FLT_MAX;
	val_max=FLT_MIN;
	
	string g_tipo;
	cout<<"inserisci il generico tipo ";
	cin>>g_tipo;
	
	int inf,sup;
	cout<<"inserisci i due estremi dell'intervallo ";
	cin>>inf>>sup;
	
	opera o;
	
	for(int i=0;i<d.get_num();++i)  //Il numero degli elementi contenuti nel dizionario d � rappresentato dall'attributo privato n della classe diz_stat che si                               //ottiene tramite la chiamata al metodo pubblico get_num per l'oggetto d.
	{
		o=d.get_elem(i);            //L'elemento alla posizione i del dizionario d � l'elemento i-mo dell'attributo privato v della classe diz_stat che si                                 //ottiene tramite la chiamata al metodo pubblico get_elem per l'oggetto d.
		
		if(o.get_tipo()==g_tipo && o.get_anno()>=inf && o.get_anno()<=sup)
		{
			if(o.get_valore()<val_min)
			  val_min=o.get_valore();
			
			if(o.get_valore()>val_max)
			  val_max=o.get_valore();
		}
		
		cout<<"il valore minimo delle opere di un generico tipo "<<val_min<<'\n';
		cout<<"il valore massimo delle opere di un generico tipo "<<val_max<<'\n';
	}	
}


