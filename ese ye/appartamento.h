#include "edificio.h"
class appartamento: public edificio
{ string nome_pal;
  int piano;
  float dim_gar,prezzo;
  
  public:
  	//DICHIARAZIONE COSTRUTTORI.
  	appartamento(){nome_pal=""; piano=0; dim_gar=prezzo=0.0;}
  	appartamento(appartamento & a) : edificio(a){nome_pal=a.nome_pal; piano=a.piano; dim_gar=a.dim_gar; prezzo=a.prezzo;}
  	appartamento(string k,string v,float d,int nc,string np,int pi,float dg,float pr) : edificio(k,v,d,nc){set_nome_pal(np); set_piano(pi); set_dim_gar(dg); set_prezzo(pr);}
  	
  	//DICHIARAZIONE METODI GETTERS E SETTERS.
  	string get_nome_pal(){return nome_pal;}
  	void set_nome_pal(){do{cout<<"Inserisci il nome del palazzo: "; cin>>nome_pal;} while(nome_pal=="");}
  	void set_nome_pal(string np){if(np!="") nome_pal=np; else cout<<"\nNome palazzo inserito non valido. ";}
  	
  	int get_piano(){return piano;}
  	void set_piano(){do{cout<<"Inserisci piano: "; cin>>piano;} while(piano<0);}
  	void set_piano(int p){if(p>=0) piano=p; else cout<<"\nPiano inserito non valido. ";}
  	
  	float get_dim_gar(){return dim_gar;}
  	void set_dim_gar(){do{cout<<"Inserisci dimensioni garage: "; cin>>dim_gar;} while(dim_gar<0);}
  	void set_dim_gar(float dg){if(dg>=0) dim_gar=dg; else cout<<"\nDimensioni garage inserite non valide. ";}
  	
  	float get_prezzo(){return prezzo;}
  	void set_prezzo(){do{cout<<"Inserisci prezzo: "; cin>>prezzo;} while(prezzo<0);}
  	void set_prezzo(float pr){if(pr>=0) prezzo=pr; else cout<<"\nPrezzo inserito non valido. ";}
  	
  	//DICHIARAZIONE METODI INSER_INF.
  	void inser_inf(){edificio::inser_inf(); set_nome_pal(); set_piano(); set_dim_gar(); set_prezzo();}
  	void inser_inf(string k){edificio::inser_inf(k); set_nome_pal(); set_piano(); set_dim_gar(); set_prezzo();}
  	void inser_inf(appartamento & a){edificio::inser_inf(a); nome_pal=a.nome_pal; piano=a.piano; dim_gar=a.dim_gar; prezzo=a.prezzo;}
  	void inser_inf(string k,string v,float d,int nc,string np,int pi,float dg,float pr){edificio::inser_inf(k,v,d,nc); set_nome_pal(np); set_piano(pi); set_dim_gar(dg); set_prezzo(pr);}
  	
  	//DICHIARAZIONE METODO VISUALIZZA.
  	void visualizza(){edificio::visualizza(); cout<<"Nome palazzo: "<<nome_pal<<"\nPiano: "<<piano<<"\nDimensioni garage: "<<dim_gar<<"\nPrezzo: "<<prezzo<<endl;}
};