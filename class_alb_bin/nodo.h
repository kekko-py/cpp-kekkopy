template <class te> class alb_bin;
template <class te>

class nodo
{ 
    friend class alb_bin<te>;

    private:
        te info;
        alb_bin<te> albsin,albdes;

    public:
        nodo () {info.inser_inf();}
        nodo (te elem) {info.inser_inf(elem);}
        te get_info(){return info;}
        void set_info(){info.inser_inf();}
        void set_info (te elem) {info=elem;}
        alb_bin<te> get_albsin(){return albsin;};
        void set_albsin(alb_bin<te> alb1){albsin=alb1;}
        alb_bin<te> get_albdes(){return albdes;};
        void set_albdes(alb_bin<te> alb1){albdes=alb1;}
};
