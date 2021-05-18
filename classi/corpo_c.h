class corpo_celeste{
    char tipo, nome[30];
    float massa, distanza_terra;

    public:
        //COSTRUTTORI
        corpo_celeste(){tipo=' '; strcpy(nome,""); massa=distanza_terra=0.0;}
        corpo_celeste(corpo_celeste &c_c){tipo=c_c.tipo; strcpy(nome,c_c.nome); massa=c_c.massa; distanza_terra=c_c.distanza_terra;}
        corpo_celeste(char t, char n[], float m, float d_t){set_tipo(t); set_nome(n); set_massa(m); set_distanza_terra(d_t);}
        //GETTERS
        char get_tipo(){return tipo;}
        char* get_nome(){return nome;}
        float get_massa(){return massa;}
        float get_distanza_terra(){return distanza_terra;}
        //SETTERS
        void set_tipo(){do{cout<<"Inserisci Tipo: ";cin>>tipo;}while(tipo!='S'&&tipo!='M'&&tipo!='P');}
        void set_tipo(char t){if(t=='S'&&t=='M'&&t=='P') tipo=t;}
        void set_nome(){cout<<"Inserisci Nome: ";cin>>nome;}
        void set_nome(char n[]){strcpy(nome,n);}
        void set_massa(){do{cout<<"Inserisci massa: ";cin>>massa;}while(massa>0);}
        void set_massa(float m){if(m>0) massa=m;};
        void set_distanza_terra(){do{cout<<"Distanza dalla terra: ";cin>>distanza_terra;}while(distanza_terra>0);}
        void set_distanza_terra(float d){if(d>0) distanza_terra=d;}
        //METDOTI INSER INF
        void inser_inf(){set_tipo(); set_nome(); set_massa(); set_distanza_terra();}
        void inser_inf(corpo_celeste &c){set_tipo(c.tipo); set_nome(c.nome); set_massa(c.massa); set_distanza_terra(c.distanza_terra);}
        void inser_inf(char t, char n[], float m, float d_t){set_tipo(t); set_nome(n); set_massa(m); set_distanza_terra(d_t);}
};