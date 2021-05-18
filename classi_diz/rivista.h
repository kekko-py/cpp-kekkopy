class rivista{
    string codice, casa_ed, periodicita;
    char settore;
    float prezzo;
    public:
        //COSTRUTTORI 
        rivista(){prezzo=0; casa_ed=periodicita=codice=""; settore=' ';}
        rivista(rivista &r){set_codice(r.codice);set_settore(r.settore);set_casa_ed(r.casa_ed);set_periodicita(r.periodicita);set_prezzo(r.prezzo);}
        rivista(string cod, string c_e, string per, char set, float pre){set_codice(cod);set_settore(set);set_casa_ed(c_e);set_periodicita(per);set_prezzo(pre);}

        //METODI SETTERS
        void set_codice(){cout<<"Codice: ";cin>>codice;}
        void set_settore(){do{cout<<"Settore: ";cin>>settore;}while(settore!='S' && settore!='M' && settore!='A');}
        void set_casa_ed(){cout<<"Casa ed: ";cin>>casa_ed;}
        void set_periodicita(){do{cout<<"Periodicita': ";cin>>periodicita;}while(periodicita!="settiminale" && periodicita!="mensile" && periodicita!="bimestrale");}
        void set_prezzo(){do{cout<<"Prezzo: ";cin>>prezzo;}while(prezzo<0);}
        //-------
        void set_codice(string c){codice=c;}
        void set_settore(char s){if(s=='S'||s=='M'||s=='A') settore=s;}
        void set_casa_ed(string c_e){casa_ed = c_e;}
        void set_periodicita(string p){if(p=="mensile" || p=="settimanale" || p=="bimestrale") periodicita=p;}
        void set_prezzo(float pr){if(pr>0) prezzo=pr;}

        //METODI GETTERS
        string get_codice(){return codice;}
        string get_casa_ed(){return casa_ed;}
        string get_periodicita(){return periodicita;}
        char get_settore(){return settore;}
        float get_prezzo(){return prezzo;}

        //METODI INSER_INF
        void inser_inf(){set_codice();set_settore();set_casa_ed();set_periodicita();set_prezzo();}
        void inser_inf(string k){set_codice(k),set_settore();set_casa_ed();set_periodicita();set_prezzo();}
        void inser_inf(rivista &r){set_codice(r.codice);set_settore(r.settore);set_casa_ed(r.casa_ed);set_periodicita(r.periodicita);set_prezzo(r.prezzo);}
        void inser_inf(rivista &r, string k){set_codice(k);set_settore(r.settore);set_casa_ed(r.casa_ed);set_periodicita(r.periodicita);set_prezzo(r.prezzo);}
        void inser_inf(string cod, string c_e, string per, char set, float pre){set_codice(cod);set_settore(set);set_casa_ed(c_e);set_periodicita(per);set_prezzo(pre);}

        //METODO VISUALIZZA
        void visualizza(){get_codice();get_settore();get_casa_ed();get_periodicita();get_prezzo();}
};