/*
  -codice, 
  -nome, 
  -numero abitanti, 
  -superficie,
  -regione, 
  -posizione (M per montano C per collina P per pianura), 
  -tipo (grande, medio o piccolo).
*/
class comune
{
	string codice,nome,regione,tipo;
    char posizione;
	int abitanti;
    float superfice;
	
	
	public:
		//DICHIARAZIONE METODI COSTRUTTORI
		comune(){codice=nome=regione=tipo=""; posizione=' '; abitanti=superfice=0;} //costruttore di default 
		comune(comune & c){inser_inf(c);} //costruttore di copia
		comune(string c, string n, string r, string t, char p, int a, float s){inser_inf(c,n,r,t,p,a,s);} //costruttore generico 
		
		//DICHIARAZIONI METODI GETTERS E SETTERS 
		string get_codice(){return codice;}
		void set_codice(){do{cout<<"inserisci il codice del comune "; cin>>codice;} while(codice=="");}
		void set_codice(string c){if(c!="") codice=c;}
		
		string get_nome(){return nome;}
		void set_nome(){do{cout<<"inserisci il nome del comune "; cin>>nome;} while(nome=="");}
		void set_nome(string n){if(n!="") nome=n;}
		
		string get_regione(){return regione;}
		void set_regione(){do{cout<<"inserisci la regione "; cin>>regione;} while(regione=="");}
		void set_regione(string r){if(r!="") regione=r;}
		
		string get_tipo(){return tipo;}
 		void set_tipo(){do{cout<<"inserisci il tipo "; cin>>tipo;} while(tipo!="grande" && tipo!="medio" && tipo!="piccolo");}
		void set_tipo(string t){if(t=="grande" || t=="medio" || t=="piccolo") tipo=t;}
		
		char get_posizione(){return posizione;}
		void set_posizione(){do{cout<<"inserisci la posizione del comune "; cin>>posizione;} while(posizione!='M' && posizione!='C' && posizione!='P');}
		void set_posizione(char p){if(p=='M'|| p=='C' || p=='P') posizione=p;}
		
		int get_abitanti(){return abitanti;}
		void set_abitanti(){do{cout<<"inserisci il numero di abitanti del comune "; cin>>abitanti;} while(abitanti<0);}
		void set_abitanti(int a){if(a>=0) abitanti=a;}

        float get_superfice(){return superfice;}
		void set_superfice(){do{cout<<"inserisci la superfice del comune "; cin>>superfice;} while(superfice<=0.0);}
		void set_superfice(float s){if(s>0.0) superfice=s;}

		//DICHIARAZIONI METODI INSER_INF
		void inser_inf(){set_codice(); set_nome(); set_regione(); set_tipo(); set_posizione(); set_abitanti(); set_superfice();}
		void inser_inf(string k){set_codice(k); set_nome(); set_regione(); set_tipo(); set_posizione(); set_abitanti(); set_superfice();}
		void inser_inf(comune & o){codice=o.codice; nome=o.nome; regione=o.regione; tipo=o.tipo; posizione=o.posizione; abitanti=o.abitanti; superfice=o.superfice;}
		void inser_inf(string c, string n, string r, string t, char p, int a, float s){set_codice(c); set_nome(n); set_regione(r); set_tipo(t); set_posizione(p); set_abitanti(a); set_superfice(s);}
};
