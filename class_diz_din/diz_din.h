#include "nodo.h"

/*la classe diz_din implementa un dizionario dinamico, cioè un dizionario nel quale sono frequenti inserimenti e
cancellazioni, mediante il tipo di dato lista a puntatori*/

template<class te>
class diz_din
{
   nodo<te> *primo;//dichiarazione del puntatore al primo nodo della lista
   
   public:

        //dichiarazione costruttore di default
        //inizialmente il dizionario è vuoto e questo è rappresentato dal fatto che il puntatore al primo nodo è 0
        diz_din() {primo=0;}

        //dichiarazione metodi getters e setters
        nodo<te> *get_primo() {return primo;}
        void set_primo(nodo<te> *primo1) {primo=primo1;}
        
        
        bool ric_seq_ord(string k,nodo<te> * &q,nodo<te> * &qprec);
        bool ric_seq_ord(nodo<te> * &q,nodo<te> * &qprec);
        bool ric_seq_ord(nodo<te> *&q);
        
        
        bool inser_ord();
        bool inser_ord(string k);
        
        bool canc_ord(te &elem);
        bool canc_ord(string k,te &elem);
        
        void iniz_ord();
};

template <class te>
bool diz_din<te>::ric_seq_ord(string k,nodo<te> *&q, nodo<te> * &qprec)
{ 
    q=primo;
    while ( q!=0 && k>(*q).info.get_codice())
    { 
        qprec=q ;
        q=(*q).next;
    }
    return q!=0 && k==(*q).info.get_codice();
}

template <class te>
bool diz_din<te>::ric_seq_ord(nodo<te> *&q,nodo<te> *&qprec)
{ 
    string k; 
    cout<<"Inserire il codice dell'elemento da ricercare: "; cin>>k;
    return ric_seq_ord(k,q,qprec); 
}

template <class te>
bool diz_din<te>::ric_seq_ord(nodo<te> *&q) 
{ 
    nodo<te>*qprec;
    return ric_seq_ord(q,qprec);
}

template <class te>
bool diz_din<te>::inser_ord(string k)
{ 
    nodo<te> *q,*qprec;
    if(ric_seq_ord(k,q,qprec)) return false;
    nodo<te> *app=new nodo<te>(k);
    if(q == primo)
    { 
        (*app).next=primo;
        primo=app;
    }else
    { 
        (*qprec).next=app;
        (*app).next=q;
    }

    return true;
}

template <class te>
bool diz_din<te>::canc_ord(string k,te &elem)
{
    nodo<te> *q,*qprec;
    if(!ric_seq_ord(k,q,qprec)) return false;

    elem=(*q).info;
    if(q==primo) primo=(*primo).next;
    else (*qprec).next=(*q).next;

    delete q;
    return true;
}

template<class te>
bool diz_din<te>::canc_ord(te &elem)
{ 
    string k; 
    cout<<"\nInserire il codice dell'elemento da cancellare: "; cin>>k;
    return canc_ord(k,elem);
}

template <class te>
void diz_din<te>::iniz_ord()
{   
    int num;
    do{
        cout<<"\nInserire il numero di elementi del dizionario: ";
        cin>>num;
    }while(num<0);
    
while(num>0) num-=inser_ord();
}