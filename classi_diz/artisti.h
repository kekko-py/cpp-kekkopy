class artista 
{
	string codice,nome,casa_disco,sesso;
    char genere;
	int dischi_platino,eta,posizione;
    float ingaggio;

    public:
		artista(){codice=nome=casa_disco=sesso=""; genere=' '; dischi_platino=eta=posizione=0;} //costruttore di default 
		artista(artista & o){inser_inf(o);} //costruttore di copia
		artista(string c, string n, string c_d, string s, char g, int d_p, int e, int p, float i){inser_inf(c,n,c_d,s,g,d_p,e,p,i);} //costruttore generico 

        //---------------------------------------------------------

        //Getters
		string get_codice(){return codice;}
        string get_nome(){return nome;}
        string get_casa_disco(){return casa_disco;}
        string get_sesso(){return sesso;}
        char get_genere(){return genere;}
        int get_dischi_platino(){return dischi_platino;}
        int get_eta(){return eta;}
        int get_posizione(){return posizione;}
        float get_ingaggio(){return ingaggio;}

        //---------------------------------------------------------

        //Setters
		void set_codice(){do{cout<<"inserisci il codice dell'artista "; cin>>codice;} while(codice==" ");}
		void set_codice(string c){if(c!=" ") codice=c;}
		//---
		void set_nome(){do{cout<<"inserisci il nome dell'artista "; cin>>nome;} while(nome==" ");}
		void set_nome(string n){if(n!=" ") nome=n;}
		//---
		void set_casa_disco(){do{cout<<"inserisci la casa discografica "; cin>>casa_disco;} while(casa_disco!="Universal" && casa_disco!="Warner" && casa_disco!="Sony");}
		void set_casa_disco(string c_d){if(c_d=="Warner" || c_d=="Universal" || c_d=="Sony") casa_disco=c_d;}
		//---
 		void set_sesso(){do{cout<<"inserisci il Sesso "; cin>>sesso;} while(sesso!="Uomo" && sesso!="Donna" && sesso!="Altro");}
		void set_sesso(string s){if(s=="Uomo" || s=="Donna" || s=="Altro") sesso=s;}
		//---
		void set_genere(){do{cout<<"inserisci il genere dell'artista "; cin>>genere;} while(genere!='R' && genere!='P' && genere!='J');}
		void set_genere(char v){if(genere=='R'|| genere=='P' || genere=='J') genere=v;}
		//---
		void set_dischi_platino(){do{cout<<"inserisci il numero di dischi di platino dell'artista "; cin>>dischi_platino;} while(dischi_platino<0);}
		void set_dischi_platino(int a){if(a>=0) dischi_platino=a;}
        //---
		void set_eta(){do{cout<<"inserisci l'eta' dell'artista "; cin>>eta;} while(eta<=0);}
		void set_eta(int a){if(a>0) eta=a;}
		//---
		void set_posizione(){do{cout<<"inserisci la posizione in classifica dell'artista "; cin>>posizione;} while(posizione<=0);}
		void set_posizione(int a){if(a>0) posizione=a;}
        //---
		void set_ingaggio(){do{cout<<"inserisci l'ingaggio dell'artista "; cin>>ingaggio;} while(ingaggio<0);}
		void set_ingaggio(float a){if(a>=0) ingaggio=a;}

        //---------------------------------------------------------

        //INSER INF
		void inser_inf(){set_codice(); set_nome(); set_casa_disco(); set_sesso(); set_dischi_platino(); set_genere();set_eta();set_posizione();set_ingaggio();}
		void inser_inf(string k){set_codice(k); set_nome(); set_casa_disco(); set_sesso(); set_dischi_platino(); set_genere();set_eta();set_posizione();set_ingaggio();}
		void inser_inf(artista & o){codice=o.codice; nome=o.nome; casa_disco=o.casa_disco; sesso=o.sesso; dischi_platino=o.dischi_platino; genere=o.genere; eta=o.eta; posizione=o.posizione; ingaggio=o.ingaggio;}
		void inser_inf(string c, string n, string c_d, string s, char g, int d_p, int e, int p, float i){set_codice(c); set_nome(n); set_casa_disco(c_d); set_sesso(s); set_dischi_platino(d_p); set_genere(g);set_eta(e);set_posizione(p);set_ingaggio(i);}

};