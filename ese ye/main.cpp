/* -Terracciano Carmine 4^A- 

Sono dati due elenchi relativi agli appartamenti in vendita in due quartieri di una
stessa citt�.
Le informazioni su ogni appartamento sono: codice, dimensione, via, numero civico,
nome palazzo, piano, dimensione garage. Il primo elenco � dinamico e il secondo �
statico. Gli elenchi sono ordinati rispetto al codice.

Si supponga di aver gi� realizzato una classe per rappresentare un generico edificio
avente come attributi codice, dimensioni, via,numero civico.
Si scriva un programma che, facendo un uso opportuno di sottoprogrammi,
consenta, a scelta, di:

1]
Stampare la dimensione media degli appartamenti di una specifica via il cui
garage ha una dimensione esterna ad un generico intervallo in ognuno dei due
quartieri e il massimo tra le due dimensioni medie cos� ottenute.

2]
Verificare se un appartamento del primo elenco si trova in un
palazzo diverso da quello di un appartamento del secondo elenco o il
suo garage ha una dimensione diversa da quella del garage del secondo
appartamento stampando le informazioni su entrambi gli appartamenti.

3]
Aumentare di una generica percentuale il prezzo degli appartamenti
di una tra due generiche vie in un elenco a scelta.
-----------------------------------------------------------------------------------------------------------*/
using namespace std;
#include <iostream>
#include <string>
#include <float.h>
const int LUN=100;
#include "../classi_diz/diz_stat.h"
#include "../class_diz_din/diz_din.h"
#include "appartamento.h"

typedef diz_din<appartamento> diz_d;
typedef nodo<appartamento> nodo_d;
typedef diz_stat<appartamento> diz_s;

/*---PROTOTIPI FUNZIONI---*/
void menu(int & scelta);

//Punto1.
void punto1(diz_d dd1,diz_s ds2);
void visita_p1_dd1(diz_d dd1,float & dim_media);
void visita_p1_ds2(diz_s ds2,float & dim_media);

//Punto2.
void punto2(diz_d dd1,diz_s ds2);

//Punto3.
void menu_el(int & scelta_el);
void punto3(diz_d dd1,diz_s ds2);
void visita_p3_dd1(diz_d dd1);
void visita_p3_ds2(diz_s ds2);


//Inizio main____________________________________
int main(int argc, char** argv) 
{ diz_d dd1;
  diz_s ds2;
  
  cout<<"<<1^ELENCO>> \n";
  dd1.iniz_ord();
  cout<<"\n\n<<2^ELENCO>> \n";
  ds2.iniz_ord();
  
  int sc;
  do
  { menu(sc);
    switch(sc)
    { case 1: punto1(dd1,ds2); break;
      case 2: punto2(dd1,ds2); break;
      case 3: punto3(dd1,ds2);
	}
  } while(sc>=1 && sc<=3);
  
	return 0;
}
//Fine main______________________________________


/*---DICHIARAZIONE FUNZIONI---*/
void menu(int & scelta)
{ cout<<"\n\n<<MENU>> \n"
      <<"1] Risolvi Punto1. \n"
      <<"2] Risolvi Punto2. \n"
      <<"3] Risolvi Punto3. \n"
      <<"--> "; cin>>scelta;
}


/*---PUNTO1---*/
//Funzione <punto1>
void punto1(diz_d dd1,diz_s ds2)
{ float dim_media1,dim_media2;
  
  visita_p1_dd1(dd1,dim_media1);
  visita_p1_ds2(ds2,dim_media2);
  
  cout<<"\nIl massimo tra le due dimensioni medie vale: ";
  if(dim_media1>dim_media2)
    cout<<dim_media1;
  else
    cout<<dim_media2;
}

//Funzione <visita_p1_dd1>
void visita_p1_dd1(diz_d dd1,float & dim_media)
{ float somma_dim=0.0;
  int cont_dim=0;

  string gen_via;
  cout<<"\nInserisci una generica via: ";
  cin>>gen_via;
  
  float inf,sup;
  cout<<"\n<Inserisci gli estremi di un genrico intervallo> \nEstremo inferiore: ";
  cin>>inf;
  cout<<"Estremo superiore: ";
  cin>>sup;
  
  appartamento a;
  nodo_d *q;
  
  for(q=dd1.get_primo(); q!=0; q=(*q).get_next())
  { a=(*q).get_info();
  
    if(a.get_via()==gen_via && (a.get_dim_gar()<inf || a.get_dim_gar()>sup))
    { somma_dim+=a.get_dimensioni();
      ++cont_dim;
	}
  }
  
  dim_media=somma_dim/cont_dim;
  cout<<"\nDimensioni medie nel primo elenco: "<<dim_media;
}

//Funzione <visita_p1_ds2>
void visita_p1_ds2(diz_s ds2,float & dim_media)
{ float somma_dim=0.0;
  int cont_dim=0;

  string gen_via;
  cout<<"\nInserisci una generica via: ";
  cin>>gen_via;
  
  float inf,sup;
  cout<<"\n<Inserisci gli estremi di un genrico intervallo> \nEstremo inferiore: ";
  cin>>inf;
  cout<<"Estremo superiore: ";
  cin>>sup;
  
  appartamento a;
  for(int i=0; i<ds2.get_num(); ++i)
  { a=ds2.get_elem(i);
  
    if(a.get_via()==gen_via && (a.get_dim_gar()<inf || a.get_dim_gar()>sup))
    { somma_dim+=a.get_dimensioni();
      ++cont_dim;
	}
  }
  
  dim_media=somma_dim/cont_dim;
  cout<<"\nDimensioni medie nel secondo elenco: "<<dim_media;
}


/*---PUNTO2---*/
//Funzione <punto2>
void punto2(diz_d dd1,diz_s ds2)
{ nodo_d *q1;
  int med2;
  
  if(dd1.ric_seq_ord(q1))
    if(ds2.ric_bin(med2))
    { appartamento a1,a2;
      a1=(*q1).get_info();
      a2=ds2.get_elem(med2);
      
      cout<<"\n<1^APPARTAMENTO> ";
      a1.visualizza();
      cout<<"\n<2^APPARTAMENTO> ";
      a2.visualizza();
      
      if(a1.get_nome_pal()!=a2.get_nome_pal() && a1.get_dim_gar()!=a2.get_dim_gar())
        cout<<"\nOK. ";
      else
        cout<<"\nNO. ";
	}
	else
	  cout<<"\nSecondo appartamento non trovato. ";
  else
    cout<<"\nPrimo appartamento non trovato. ";
}


/*---PUNTO3---*/
//Funzione <menu_el>
void menu_el(int & scelta_el)
{ cout<<"\nIn quale elenco vuoi operare? \n";
  do
  { cout<<"Elenco no. ";
    cin>>scelta_el;
  } while(scelta_el<1 || scelta_el>2);
}


//Funzione <punto3>
void punto3(diz_d dd1,diz_s ds2)
{ int sc_el;
  menu_el(sc_el);
  
  switch(sc_el)
  { case 1: visita_p3_dd1(dd1); break;
    case 2: visita_p3_ds2(ds2);
  }
}

//Funzione <visita_p3_dd1>
void visita_p3_dd1(diz_d dd1)
{ string gen_via1,gen_via2;
  cout<<"\nInserisci due generiche vie: \n";
  cin>>gen_via1>>gen_via2;

  int gen_perc;
  cout<<"\nInserici generica percentuale: ";
  cin>>gen_perc;
  
  appartamento a;
  nodo_d *q;
  
  for(q=dd1.get_primo(); q!=0; q=(*q).get_next())
  { a=(*q).get_info();
    
    a.set_prezzo(a.get_prezzo()+a.get_prezzo()/100*gen_perc);
    (*q).set_info(a);
  }
}

//Funzione <visita_p3_ds2>
void visita_p3_ds2(diz_s ds2)
{ string gen_via1,gen_via2;
  cout<<"\nInserisci due generiche vie: \n";
  cin>>gen_via1>>gen_via2;

  int gen_perc;
  cout<<"\nInserici generica percentuale: ";
  cin>>gen_perc;
  
  appartamento a;
  for(int i=0; i<ds2.get_num(); ++i)
  { a=ds2.get_elem(i);
  
    a.set_prezzo(a.get_prezzo()+a.get_prezzo()/100*gen_perc);
    ds2.set_elem(i,a);
  }
}










