class comune{
    int codice, numero_abitanti;
    float superfice;
    char nome[LUNS], regione[LUNS], tipo[LUNS], posizione;
    
    public:
        comune(){codice=0; numero_abitanti=0; superfice=0.0; strcpy(regione,""); posizione=' '; strcpy(tipo,"");}
        comune(comune &c){codice=c.codice; numero_abitanti=c.numero_abitanti; superfice=c.superfice; strcpy(nome,c.nome); strcpy(regione,c.regione); strcpy(tipo,c.tipo); posizione=c.posizione;}
        comune(int co, int n_a, float su, char no[], char re[], char ti[], char po){set_codice(co); set_numero_abitanti(n_a); set_superfice(su); set_nome(no); set_regione(re); set_tipo(ti); set_posizione(po);}

        //SETTERS
        void set_codice(int c){if(c>=0) codice=c;}
        void set_codice(){do{cout<<"Inserisci il codice: ";cin>>codice;}while(codice<0);}
        //----
        void set_nome(char n[]){if(strlen(n)<LUNS) strcpy(nome,n);}
        void set_nome(){do{cout<<"Inserisci il nome: ";cin>>nome;}while(strlen(nome)>=LUNS);}
        //----
        void set_numero_abitanti(int n){if(n>=0) numero_abitanti=n;}
        void set_numero_abitanti(){do{cout<<"Inserisci gli abitanti: ";cin>>numero_abitanti;}while(numero_abitanti<0);}
        //----
        void set_superfice(float s){if(s>0.0) superfice=s;}
        void set_superfice(){do{cout<<"Inserisci la superfice: ";cin>>superfice;}while(superfice<=0.0);}
        //----
        void set_regione(char r[]){if(strlen(r)<LUNS) strcpy(regione,r);}
        void set_regione(){do{cout<<"Inserisci la regione: ";cin>>regione;}while(strlen(regione)>=LUNS);}
        //----
        void set_posizione(char p){if(p=='M' || p=='C' || p=='P') posizione=p;}
        void set_posizione(){do{cout<<"Inserisci la posizione: ";cin>>posizione;}while(posizione!='M' && posizione!='C' && posizione!='P');}
        //----
        void set_tipo(char t[]){if(!strcmp(t,"grande")|| !strcmp(t,"medio") || !strcmp(t,"piccolo")) strcpy(tipo,t);}
        void set_tipo(){do{cout<<"Inserisci il Tipo: ";cin>>tipo;}while(strcmp(tipo,"grande") && strcmp(tipo,"medio") && strcmp(tipo,"piccolo"));}

        //GETTERS
        int get_codice(){return codice;}
        char* get_nome(){return nome;}
        int get_numero_abitanti(){return numero_abitanti;}
        float get_superfice(){return superfice;}
        char* get_regione(){return regione;}
        char get_posizione(){return posizione;}
        char* get_tipo(){return tipo;}

        //INSER_INF
        void inser_inf(){set_codice(); set_nome(); set_numero_abitanti(); set_superfice(); set_regione(); set_posizione(); set_tipo();}
        void inser_inf(comune &c){codice=c.codice; numero_abitanti=c.numero_abitanti; superfice=c.superfice; strcpy(nome,c.nome); strcpy(regione,c.regione); strcpy(tipo,c.tipo); posizione=c.posizione;}
        void inser_inf(int co, int n_a, float su, char no[], char re[], char ti[], char po){set_codice(co); set_numero_abitanti(n_a); set_superfice(su); set_nome(no); set_regione(re); set_tipo(ti); set_posizione(po);}

        //VISUALIZZA
        void visualizza(){
            cout<<codice<<endl;
            cout<<nome<<endl;
            cout<<numero_abitanti<<endl;
            cout<<superfice<<endl;
            cout<<regione<<endl;
            cout<<posizione<<endl;
            cout<<tipo<<endl;
        }
};
