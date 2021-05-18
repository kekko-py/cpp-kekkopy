template <class te>
class diz_stat{
    te v[LUN];
    int num;
    
    public:
        //COSTRUTTORE
        diz_stat(){num=0;}
        
        //GETTERS
        te get_elem(int pos_elem){return v[pos_elem];}
        //----
        int get_num(){return num;}

        //SETTERS
        void set_elem(int pos_elem){v[pos_elem].inser_inf();}
        void set_elem(int pos_elem, te elem){v[pos_elem].inser_inf(elem);}
        void set_elem(int pos_elem, string k){v[pos_elem].inser_inf(k);}
        //----
        void set_num(){do{cout<<"Dammi il numero di Elementi: ";cin>>num;}while(num<0||num>LUN);}
        void set_num(int n){if(n>=0 && n<=LUN) num=n; else cout<<"Non Valido."<<endl;}

        //RICERCA BINARIA
        bool ric_bin(string k, int &med);
        bool ric_bin(int & med);

        //INSERISCI DIZ. ORDINATO
        bool inser_ord(string k);
        bool inser_ord();

        //INIZ_ORD
        void iniz_ord();

        //CANC ORD
        bool canc_ord(string k);
        bool canc_ord();
};


//METODO RIC_BIN
// Per effettuare una ricerca in un dizionario ordinato, tramite la ricerca binaria!
template <class te>
bool diz_stat<te>::ric_bin(string k, int &med)
{
    int inf=0, sup=num-1;
    string kmed;

    do{
        med=(inf+sup)/2;
        kmed=v[med].get_codice();

        if(k<kmed) sup=med-1;
        else if(k>kmed) inf=med+1;

    }while(inf<=sup && k!=kmed);

    return inf<=sup;
}

template <class te>
bool diz_stat<te>::ric_bin(int & med)
{ string k; 
  cout<<"Inserisci valore di chiave primaria da ricercare: "; 
  cin>>k;
  
  return ric_bin(k,med);
}

//METODO INSER_ORD
// Per effettuare un inserimento in un dizionario ordinato!
template <class te>
bool diz_stat<te>::inser_ord(string k)
{
    if(num==LUN) return false;
    if(num==0){v[num++].inser_inf(k); return true;}
    int med;
    if(ric_bin(k,med))return false;

    if(k>v[med].get_codice()) ++med;
    for(int i=num-1; i>=med; --i) v[i+1]=v[i];
    v[med].inser_inf(k);
    ++num;
    return true;
}

template <class te>
bool diz_stat<te>::inser_ord()
{ string k; 
  cout<<"Inserisci valore di chiave primaria dell'elemento da inserire: "; 
  cin>>k;
  
  return inser_ord(k);
}

//METODO INIZ_ORD
// Per effettuare una inizializzazione in un dizionario ordinato!
template <class te>
void diz_stat<te>::iniz_ord()
{ 
    int n;   
    do{
        cout<<"Numero di elementi del dizionario: "; cin>>n;
    }while(n<=0 || n>LUN);

    for(num=0; num<n;) 
        inser_ord();
}


template <class te>
bool diz_stat<te>::canc_ord(string k)
{
    if(num==0) return false;
    int med;
    if(!ric_bin(k,med)) return false;

    for(int i=med+1; i<=num-1; i++) v[i-1]=v[i];
    --num;
    return true;
}

template <class te>
bool diz_stat<te>::canc_ord()
{ 
    string k; 
    cout<<"Inserisci valore di chiave primaria dell'elemento da inserire: "; 
    cin>>k;
  
    return canc_ord(k,elem);
}
