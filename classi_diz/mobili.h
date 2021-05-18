/*
     Dati due elenchi di mobili, per ogni mobile sono dati:
      codice, 
      larghezza,
       altezza,
        profondità, 
        stile (S settecento, O ottocento, M moderno), 
        tipo (parete attrezzata, tavolo, divano, letto)
         e prezzo.


        1. Calcolare la profondità media e quella minima dei mobili del settecento di uno tra due generici tipi e la larghezza massima dei mobili di un generico stile in entrambi gli elenchi e il massimo tra le due profondità minime.
        2. Verificare che un mobile del primo elenco sia un tavolo e abbia una larghezza superiore a quella media di due mobili dle secondo elenco.
*/

class mobile{
    string codice,tipo;
    float larghezza,altezza,profondita,prezzo;
    char stile;

    public:
        mobile(){codice=tipo=""; larghezza=altezza=profondità=prezzo=0.0; stile=' ';}
        mobile(mobile &m){inser_inf(m);}
        mobile(string c, string t, float l, float a, float pro, float pre, char s){inser_inf(c,t,l,a,pro,pre,s);}

        //GETTERS
        string get_codice(){return codice;}
        string get_tipo(){return tipo;}
        float get_larghezza(){return larghezza;}
        
        //SETTERS
        //  tipo (parete attrezzata, tavolo, divano, letto)
        void set_tipo(string t){if(t=="parete attrezzata" || t=="tavolo" || t=="divano" || t=="letto") tipo=t}
        void set_tipo(){do{cout<<"Inserisci il tipo: "; cin>>tipo;}while(tipo!="parete attrezzata" && tipo!="tavolo" && tipo!="divano" && tipo!="letto");}

        //  stile (S settecento, O ottocento, M moderno), 
        void set_stile(char s){if(s=='S'||s=='O'||s=='M') stile=s;}


        void inser_inf(){set_codice(); set_tipo(); set_larghezza(); set_altezza(); set_profondita(); set_stile(); set_prezzo();}
        void inser_inf(string k){set_codice(k); set_tipo(); set_larghezza(); set_altezza(); set_profondita(); set_stile(); set_prezzo();}
        void inser_inf(mobile m){codice=m.comice; tipo=m.tipo; larghezza=m.larghezza; altezza=m.altezza; profondita=m.profondita; stile=m.stile; prezzo=m.prezzo; }
        void inser_inf(string c, string t, float l, float a, float pro, float pre, char s){set_codice(c); set_tipo(t); set_larghezza(l); set_altezza(a); set_profondita(pro); set_stile(s); set_prezzo(pre);}
};
