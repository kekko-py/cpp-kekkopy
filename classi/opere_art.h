//Francesco De Rosa
class opera{
    int codice,anno;
    float valore;
    char tipo,autore[30];

    public:
        //__________________COSTRUTTORI_____________________
        //Costruttore di Default
        opera(){codice=0;anno=0000;valore=0.0;tipo=' ';strcpy(autore,"");}
        //Costruttore di copia
        opera(opera &o){set_codice(o.codice);set_anno(o.anno);set_valore(o.valore);set_tipo(o.tipo);set_autore(o.autore);}
        //Costruttore Generico
        opera(int c, int a, float v, char t, char au[]){set_codice(c);set_anno(a);set_valore(v);set_tipo(t);set_autore(au);}
        
        //__________________GETTERS_____________________
        int get_codice(){return codice;}
        int get_anno(){return anno;}
        float get_valore(){return valore;}
        char get_tipo(){return tipo;}
        char* get_autore(){return autore;}

        //__________________SETTERS [Senza parametri formali]_____________________
        void set_codice(){do{cout<<"Inserieci il codice: ";cin>>codice;}while(codice<0);}
        void set_anno(){cout<<"Inserisci l'anno: ";cin>>anno;}
        void set_valore(){do{cout<<"Inserisci il valore: ";cin>>valore;}while(valore<0);}
        void set_tipo(){do{cout<<"Inserisci il tipo: ";cin>>tipo;}while(tipo!='S'&&tipo!='D'&&tipo!='A');}
        void set_autore(){cout<<"Inserisci l'autore: ";cin>>autore;}        
        //__________________SETTERS [con parametri formali]_____________________
        void set_codice(int c){if(c>0) codice=c;}
        void set_anno(int a){anno=a;}
        void set_valore(float v){if(v>0) valore=v;}
        void set_tipo(char t){if(tipo=='S'||tipo=='D'||tipo=='A') tipo=t;}
        void set_autore(char a[]){strcpy(autore,a);}

        //__________________INSER INF_____________________
        void inser_inf(){set_codice();set_anno();set_valore();set_tipo();set_autore();}
        void inser_inf(opera &o){set_codice(o.codice);set_anno(o.anno);set_valore(o.valore);set_tipo(o.tipo);set_autore(o.autore);}
        void inser_inf(int c, int a, float v, char t, char au[]){set_codice(c);set_anno(a);set_valore(v);set_tipo(t);set_autore(au);}     
};