class automobile{
    int codice, cilindrata;
    float prezzo;
    char modello, marca[30];
    
    public:
        automobile(){codice=cilindrata=prezzo=0; modello=' '; strcpy(marca,"");}
        automobile(automobile &a){codice=a.codice; cilindrata=a.cilindrata; prezzo=a.prezzo; modello=a.modello; strcpy(marca, a.marca);}
        automobile(int co, int ci, float pr, char mo, char ma[]){}

        int get_codice(){return codice;}
        int get_cilindrata(){return cilindrata;}
        float get_prezzo(){return prezzo;}
        char get_modello(){return modello;}
        char* get_marca(){return marca;}

        void set_codice(int c){if(c>=0) codice=c;}
        void set_codice(){}
        void set_cilindrata(int c){if(c>0) cilindrata=c;}
        void set_cilindrata(){}
        void set_prezzo(float p){if(p>=0) prezzo=p;}
        void set_prezzo(){}
        void set_modello(char m){if(m=='S'||m=='F'||m=='U') modello=m;}
        void set_modello(){}
        void set_marca(char m[]){if(!strcmp(m,"Fiat") || !strcmp(m,"Ford") !strcmp(m,"Suzuki")) strcpy(marca,m);}
        void set_marca(){}
};