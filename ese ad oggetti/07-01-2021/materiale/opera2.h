class opera 
{
	string codice,nome,tipo,autore;
	float valore;
	int anno;
	
	
	public:
		//DICHIARAZIONE METODI COSTRUTTORI
		opera(){codice=nome=tipo=autore=""; valore=anno=0;} //costruttore di default 
		opera(opera & o){inser_inf(o);} //costruttore di copia
		opera(string c,string n,string t,string au,float v,int a){inser_inf(c,n,t,au,v,a);} //costruttore generico 
		
		//DICHIARAZIONI METODI GETTERS E SETTERS 
		string get_codice(){return codice;}
		void set_codice(){do{cout<<"inserisci il codice dell'opera "; cin>>codice;} while(codice==" ");}
		void set_codice(string c){if(c!=" ") codice=c;}
		
		string get_nome(){return nome;}
		void set_nome(){do{cout<<"inserisci il nome dell'opera "; cin>>nome;} while(nome==" ");}
		void set_nome(string n){if(n!=" ") nome=n;}
		
		string get_tipo(){return tipo;}
		void set_tipo(){do{cout<<"inserisci il tipo dell'opera "; cin>>tipo;} while(tipo!="dipinto" && tipo!="scultura");}
		void set_tipo(string t){if(t=="dipinto" || t=="scultura") tipo=t;}
		
		string get_autore(){return autore;}
 		void set_autore(){do{cout<<"inserisci l'autore dell'opera "; cin>>autore;} while(autore==" ");}
		void set_autore(string au){if(au!=" ") autore=au;}
		
		float get_valore(){return valore;}
		void set_valore(){do{cout<<"inserisci il valore dell'opera "; cin>>valore;} while(valore<=0);}
		void set_valore(float v){if(v>0) valore=v;}
		
		int get_anno(){return anno;}
		void set_anno(){do{cout<<"inserisci l'anno di pubblicazione dell'opera "; cin>>anno;} while(anno<=0);}
		void set_anno(int a){if(a>0) anno=a;}
		
		//DICHIARAZIONI METODI INSER_INF
		void inser_inf(){set_codice(); set_nome(); set_tipo(); set_autore(); set_valore(); set_anno();}
		void inser_inf(string k){set_codice(k); set_nome(); set_tipo(); set_autore(); set_valore(); set_anno();}
		void inser_inf(opera & o){codice=o.codice; nome=o.nome; tipo=o.tipo; autore=o.autore; valore=o.valore; anno=o.anno;}
		void inser_inf(string c,string n,string t,string au,float v,int a){set_codice(c); set_nome(n); set_tipo(t); set_autore(au); set_valore(v); set_anno(a);}
		
		void visualizza(){cout<<"codice: "<<codice<<" nome: "<<nome<<" tipo: "<<tipo<<" autore: "<<autore<<" valore: "<<valore<<" anno: "<<anno;}
		
		
};
