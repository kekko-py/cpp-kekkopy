template <class te>
class diz_din;

template <class te>
class nodo
{
    friend class diz_din<te>;
    
    te info;
    nodo<te> *next;

    public:
        nodo(){info.inser_inf(); next=0;}
        nodo(string k){info.inser_inf(k); next=0;}
        nodo(te &elem){info.inser_inf(elem); next=0;}

        te get_info(){return info;}
        void set_info(){info.inser_inf();}
        void set_info(string k){info.inser_inf(k);}
        void set_info(te &elem){info.inser_inf(elem);}

        nodo<te> *get_next(){return next;}
        void set_next(nodo<te> *n){next=n};
}