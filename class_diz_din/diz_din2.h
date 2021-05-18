#include <nodo.h>

template <class te>
class diz_din
{
    nodo<te> *primo;

    public:
        nodo(){primo=0;}

        bool ric_seq_ord(string k, nodo<te> *&q, nodo<te> *&qprec);
        bool inser_ord(string k);
        bool canc_ord(string k);
        void iniz_ord();        
};

template <class te>
bool diz_din<te>::ric_seq_ord(string k, nodo<te> *&q, nodo<te> *&qprec)
{
    q=primo;
    while(q!=0 && k>q->info.get_codice())
    {
        qprec=q;
        q=q->next;
    }
    return q!=0 && k==q->info.get_codice();
}

template <class te>
bool diz_din<te>::inser_ord(string k)
{
    nodo<te> *q,*qprec;
    if(ric_seq_ord(k,q,qprec)) return false;
    nodo<te> *app = new nodo<te>(k);

    if (q==primo)
    {
        app->next=primo;
        primo=app;
    }
    else
    {
        qprec->next=app;
        app->next=q;
    }
    
    return true;    
}

template <class te>
bool diz_din<te>::canc_ord(string k)
{
    nodo<te> *q,*qprec;
    if(!ric_seq_ord(k,q,qprec)) return false;

    if(q==primo) primo=q->next;
    else qprec->next=q->next;

    delete q;
    return true;
}

template <class te>
bool diz_din<te>::iniz_ord()
{
    int num;
    do
    {
        cin>>num
    }while (num<0);
    
    while(num>o) num-=inser_ord();
}