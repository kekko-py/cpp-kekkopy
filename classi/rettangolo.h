class rettangolo{
    float base, altezza;
    public:
        //COSTRUTTORI
        rettangolo(){base=1;altezza=1;}
        rettangolo(rettangolo &r){base = r.base; altezza = r.altezza;}
        rettangolo(float b, float a){set_base(b); set_altezza(a);}

        //METODI GETTERS E SETTERS
        float get_base(){return base;} 
        void set_base(){do{cout<<"Valore base: ";cin>>base;}while(base<=0);}
        void set_base(float b){if(b>0) base=b;}
        float get_altezza(){return altezza;}
        void set_altezza(){do{cout<<"Valore altezza: ";cin>>altezza;}while(altezza<=0);}
        void set_altezza(float a){if(a>0) altezza=a;}

        //METODI INSER_INF
        void inser_inf(){set_base(); set_altezza()}
        void inser_inf(rettangolo &r){base = r.base; altezza = r.altezza;}
        void inser_inf(float b, float a){set_base(b); set_altezza(a);}

        //ALTRI METODI
        float perimetro(){return (base+altezza)*2;}
        float area(){return base*altezza;}

        //METODO VISUALIZZA
        void visualizza(){cout<<base<<altezza<<endl;}
};
