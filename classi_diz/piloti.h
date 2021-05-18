/*  
    codice, 
    nazionalità, (inglese, francese)
    scuderia, (M, F)
    numero campionati vinti, 
    numero di pole position,
    ingaggio
*/

//-----------------------------------------------------------------------------------------------

class pilota
{
    string codice,nome,nazionalita;
    char scuderia;
	int vittorie,posizione;
    float ingaggio;

    public:
		pilota(){codice=nome=nazionalita=""; scuderia=' '; vittorie=n_classifica=ingaggio=0;} //costruttore di default 
		pilota(pilota & p){inser_inf(p);} //costruttore di copia
		pilota(string c, string n, string na, char s, int v, int n_c, float i){inser_inf(c,n,na,s,v,n_c,i);} //costruttore generico 

        //---------------------------------------------------------

        //Getters
		string get_codice(){return codice;}
        string get_nome(){return nome;}
        string get_nazionalita(){return nazionalita;}
        char get_scuderia(){return scuderia;}
        int get_vittorie(){return vittorie;}
        int get_posizione(){return posizione;}
        float get_ingaggio(){return ingaggio;}

        //---------------------------------------------------------

        //Setters
		void set_codice(){do{cout<<"inserisci il codice del pilota "; cin>>codice;} while(codice==" ");}
		void set_codice(string c){if(c!=" ") codice=c;}
		//---
		void set_nome(){do{cout<<"inserisci il nome del pilota "; cin>>nome;} while(nome==" ");}
		void set_nome(string n){if(n!=" ") nome=n;}
		//---
		void set_nazionalita(){do{cout<<"inserisci la nazionalita' "; cin>>nazionalita;} while(nazionalita!="Francese" && nazionalita!="Italiana" && nazionalita!="Inglese");}
		void set_nazionalita(string c_d){if(c_d=="Francese" || c_d=="Italiana" || c_d=="Inglese") nazionalita=c_d;}
		//---
		void set_scuderia(){do{cout<<"inserisci la scuderia del pilota "; cin>>scuderia;} while(scuderia!='F' && scuderia!='M');}
		void set_scuderia(char v){if(scuderia=='F'|| scuderia=='M') scuderia=v;}
		//---
		void set_vittorie(){do{cout<<"inserisci il numero di vittorie del pilota "; cin>>vittorie;} while(vittorie<0);}
		void set_vittorie(int a){if(a>=0) vittorie=a;}
        //---
		void set_posizione(){do{cout<<"inserisci la posizione in classifica del pilota "; cin>>posizione;} while(posizione<=0);}
		void set_posizione(int a){if(a>0) posizione=a;}
        //---
		void set_ingaggio(){do{cout<<"inserisci l'ingaggio del pilota "; cin>>ingaggio;} while(ingaggio<0);}
		void set_ingaggio(float a){if(a>=0) ingaggio=a;}

        //---------------------------------------------------------

        //INSER INF
		void inser_inf(){set_codice(); set_nome(); set_nazionalita();set_scuderia(); set_vittorie(); set_posizione();set_ingaggio();}
		void inser_inf(string k){set_codice(k); set_nome(); set_nazionalita();set_scuderia(); set_vittorie(); set_posizione();set_ingaggio();}
		void inser_inf(pilota & o){codice=o.codice; nome=o.nome; nazionalita=o.nazionalita; scuderia=o.scuderia; vittorie=o.vittorie; posizione=o.posizione; ingaggio=o.ingaggio;}
		void inser_inf(string c, string n, string na, char s, int v, int n_c, float i){set_codice(c); set_nome(n); set_nazionalita(na);set_scuderia(s); set_vittorie(v); set_posizione(n_c);set_ingaggio(i);}

};
