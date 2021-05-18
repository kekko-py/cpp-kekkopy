#include "nodo.h"
template <class te>
class alb_bin
{ 
    private:
        nodo<te>* radice;

    public:
        alb_bin(){radice=0;}
        nodo<te>* get_radice(){return radice;}
        void set_radice (nodo <te> *rad) {radice=rad;}
        void crea();
        void preorder();
        void postorder();
        void inorder();
};

template <class te>
void alb_bin<te>::crea()
{ 
    char ris;
    do
    {
        cout<<"vuoi inserire un nuovo albero?";
        cin>>ris;
        ris= tolower(ris);
    }while(ris!='s' && ris!='n');

    if (ris=='s')
    { 
        radice=new nodo<te>; //creazione nodo radice
        radice->albsin.crea();
        radice->albdes.crea();
    }
}

template <class te>
void alb_bin<te>::preorder()
{ 
    if (radice!=0)
    { 
        radice->info.visualizza();
        radice->albsin.preorder();
        radice->albdes.preorder();
    }
}

template <class te>
void alb_bin<te>::postorder()
{ 
    if (radice!=0)
    { 
        radice->albsin.postorder();
        radice->albdes.postorder();
        radice->info.visualizza();
    }
}
/*
template <class te>
void alb_bin<te>::inorder()
{ 
    if (radice!=0)
    { 
    
    }
}
*/