class edificio
{ string codice,via;
  float dimensioni;
  int n_civico;
  
  public:
  	//DICHIARAZIONE COSTRUTTORI.
  	edificio(){codice=via=""; dimensioni=n_civico=0;}
  	edificio(edificio & e){inser_inf(e);}
  	edificio(string k,string v,float d,int nc){inser_inf(k,v,d,nc);}
  	
  	//DICHIARAZIONE METODI GETTERS E SETTERS.
  	string get_codice(){return codice;}
  	void set_codice(){do{cout<<"Inserisci codice: "; cin>>codice;} while(codice=="");}
  	void set_codice(string k){if(k!="") codice=k; else cout<<"\nCodice inserito non valido. ";}
  	
  	string get_via(){return via;}
  	void set_via(){do{cout<<"Inserisci nome della via: "; cin>>via;} while(via=="");}
  	void set_via(string v){if(v!="") via=v; else cout<<"\nVia inserita non valida. ";}
  	
  	float get_dimensioni(){return dimensioni;}
  	void set_dimensioni(){do{cout<<"Inserisci dimensioni: "; cin>>dimensioni;} while(dimensioni<0);}
  	void set_dimensioni(float d){if(d>=0) dimensioni=d; else cout<<"\nDimensioni inserite non valide. ";}
  	
  	int get_n_civico(){return n_civico;}
  	void set_n_civico(){do{cout<<"Inserisci n. civico: "; cin>>n_civico;} while(n_civico<1);}
  	void set_n_civico(int nc){if(nc>=1) n_civico=nc; else cout<<"\nN. civico inserito non valido. ";}
  	
  	//DICHIARAZIONE METODI INSER_INF.
  	void inser_inf(){set_codice(); set_via(); set_dimensioni(); set_n_civico();}
  	void inser_inf(string k){set_codice(k); set_via(); set_dimensioni(); set_n_civico();}
  	void inser_inf(edificio & e){codice=e.codice; via=e.via; dimensioni=e.dimensioni; n_civico=e.n_civico;}
  	void inser_inf(string k,string v,float d,int nc){set_codice(k); set_via(v); set_dimensioni(d); set_n_civico(nc);}
  	
  	////METODO VISUALIZZA.
  	void visualizza(){cout<<"\nCodice: "<<codice<<"\nVia: "<<via<<"\nDimensioni: "<<dimensioni<<"\nN. civico: "<<n_civico<<endl;}
};