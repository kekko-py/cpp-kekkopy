class rivista{
    int codice;
    char settore, casa_ed[30], periodicita[30];
    float prezzo;
    public:
        //COSTRUTTORE
        rivista(){prezzo=0;strcpy(casa_ed,"");strcpy(periodicita,"");}
        //METODI GETTERS E SETTERS
        void set_settore(){do{cout<<"Settore: ";cin>>settore;}while(settore!='S' && settore!='M' && settore!='A');}
        void set_casa_ed(){do{cout<<"Casa ed: ";cin>>casa_ed;}while(strcmp(casa_ed,"Mondatori")!=0 && strcmp(casa_ed,"Feltrinelli")!=0 && strcmp(casa_ed,"Apogeo")!=0);}
        void set_periodicita(){do{cout<<"Periodicita': ";cin>>periodicita;}while(strcmp(periodicita, "mensile")!=0 && strcmp(periodicita, "settimanale")!=0 && strcmp(periodicita, "bimestrale")!=0);}
        void set_prezzo(){do{cout<<"Prezzo: ";cin>>prezzo;}while(prezzo<0);}
        char get_settore(){return settore;}
        char * get_casa_ed(){return casa_ed;}
        char * get_periodicita(){return periodicita;}
        float get_prezzo(){return prezzo;}
        //METODO INSER_INF
        void inser_inf(){set_settore();set_casa_ed();set_periodicita();set_prezzo();}
};