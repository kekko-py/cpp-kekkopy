//prototipo classe diz_din
template <class te>
class diz_din;

template <class te>
class nodo
{ 
    friend class diz_din <te>; //dichiaro la classe nodo amica della classe diz_din al fine di permettere ad essa di
	                           //accedere ai suoi elementi privati.

    te info; //nella zona info viene memorizzato un elemento dell' insieme di elementi
    nodo<te> *next; //dichiaro next [tipo: puntatore ad oggetti della classe nodo]
    
    public:
        // dichiarazione costruttori
        nodo() {info.inser_inf(); next=0;} //costruttore di deafult
        nodo(string k) {info.inser_inf(k); next=0;} //costruttore generico
        nodo(te &elem) {info.inser_inf(elem); next=0;} //costruttore di copia
         
         
        //dichiarazione di metodi getters e setters
        te get_info(){return info;}
        void set_info(){info.inser_inf();}
        void set_info(string k){info.inser_inf(k);}
        void set_info(te &elem){info.inser_inf(elem);}
        
        
        nodo<te> *get_next(){return next;}
        void set_next(nodo<te> *next1){next=next1;}
};