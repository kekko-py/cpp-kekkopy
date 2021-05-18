/*
  -codice, 
  -nome, 
  -numero abitanti, 
  -superficie,
  -regione, 
  -posizione (M per montano C per collina P per pianura), 
  -tipo (grande, medio o piccolo).
*/
class comune{
    string codice, nome, regione, tipo;
    char posizione;
    int numero_abitanti;
    float superfice;

    public:
        // COSTRUTTORI
        comune(){codice=nome=regione=tipo=""; posizione=' '; numero_abitanti=superfice=0;}
        comune(comune &c){inser_inf(c);}
        comune(string c, string n, string r, string t, char p, int n_a, float s){inser_inf(c, n, r, t, p, n_a, s);}

        // MODULI GETTERS
        string get_codice(){return codice;}
        string get_nome(){return nome;}
        string get_regione(){return regione;}
        string get_tipo(){return tipo;}
        char get_posizione(){return posizione;}
        int get_n_abitanti(){return numero_abitanti;}
        float get_superfice(){return superfice;}

        //MODULI SETTERS
        // * codice
        void set_codice(string c){if(c!="") codice=c;}
        void set_codice(){do{cout<<"Inserisci il codice: "; cin>>codice;}while(codice=="");}
        // * nome
        void set_nome(string n){if(n!="") nome=n;}
        void set_nome(){do{cout<<"Inserisci il nome: "; cin>>nome;}while(nome=="");}
        // * regione
        void set_regione(string r){if(r!="") regione=r;}
        void set_regione(){do{cout<<"Inserisci la regione: "; cin>>regione;}while(regione=="");}
        // * tipo
        void set_tipo(string t){if(t=="grande"||t=="medio"||t=="piccolo") tipo=t;}
        void set_tipo(){do{cout<<"Inserisci il tipo: "; cin>>tipo;}while(tipo!="grande"&&tipo!="medio"&&tipo!="piccolo");}
        // * posizione
        void set_posizione(char p){if(p=='M'||p=='C'||p=='P') posizione=p;}
        void set_posizione(){do{cout<<"Inserisci il posizione: "; cin>>posizione;}while(posizione!='M'&&posizione!='C'&&posizione!='P');}
        // * n_abitanti
        void set_n_abitanti(int n_a){if(n_a>=0) numero_abitanti=n_a;}
        void set_n_abitanti(){do{cout<<"Inserisci il numero degli abitanti: "; cin>>numero_abitanti;}while(numero_abitanti<0);}
        // * superfice
        void set_superfice(float s){if(s>0) superfice=s;}
        void set_superfice(){do{cout<<"Inserisci la superfice: "; cin>>superfice;}while(superfice<=0);}


        // MODULI INSER_INF
        void inser_inf(){set_codice(); set_nome(); set_regione(); set_tipo(); set_posizione(); set_n_abitanti(); set_superfice();}
		void inser_inf(string k){set_codice(k); set_nome(); set_regione(); set_tipo(); set_posizione(); set_n_abitanti(); set_superfice();}
		void inser_inf(comune & o){codice=o.codice; nome=o.nome; regione=o.regione; tipo=o.tipo; posizione=o.posizione; numero_abitanti=o.numero_abitanti; superfice=o.superfice;}
		void inser_inf(string c, string n, string r, string t, char p, int n_a, float s){set_codice(c); set_nome(n); set_regione(r); set_tipo(t); set_posizione(p); set_n_abitanti(n_a); set_superfice(s);}

};
