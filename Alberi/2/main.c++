//------------------------------------------------------------

/*
Determinare il massimo degli elementi di un albero

Determinare il massimo degli elementi pari

Decrementare di uno tutti gli elementi maggiori di k
*/

//------------------------------------------------------------



//------------------------------------------------------------

typedef alb_bin<integer> alb;
typedef nodo<integer> nodo_a;

//------------------------------------------------------------

void punto1(alb a);
void visita_p1(alb a, int &max);
void punto2(alb a);
void visita_p2(alb a, int &max);
void punto3(alb a);
void visita_p3(alb a, int k);

//------------------------------------------------------------

int main()
{
    //const int LUNS=30;
    //char nomef[LUNS];

    alb a; a.crea(); a.preorder(); cout<<"\n\n";

    //cout<<"Inserisci il nome del file: \n";
	//cout<<"File 1: \n";cin>>nomef;

    switch(menu(3))
    {
        case 1: punto1(a);break;
        case 2: punto2(a);break;
        case 3: punto3(a);
    }
    return 0;
}

//------------------------------------------------------------

void punto1(alb a)
{
    int max=INT_MIN;
    visita_p1(a,max);
    cout<<"Il max elem \212: "<<max<<endl;
}

void visita_p1(alb a, int &max)
{
    nodo_a *rad = a.get_radice();

    if(rad!=0)
    {
        int n=rad->get_info().get_n();
        if(n>max) max=n;

        visita_p1(rad->get_albsin(),max);
        visita_p1(rad->get_albdes(),max);
    }
}

//------------------------------------------------------------

void punto2(alb a)
{
    int max=INT_MIN;
    visita_p2(a,max);
    cout<<"Il max dei pari \212: "<<max<<endl;
}

void visita_p2(alb a, int &max)
{
    nodo_a *rad = a.get_radice();

    if(rad!=0)
    {
        int n=rad->get_info().get_n();
        if(n>max && n%2==0) max=n;

        visita_p2(rad->get_albsin(),max);
        visita_p2(rad->get_albdes(),max);
    }
}
//------------------------------------------------------------
// Decrementare di uno tutti gli elementi maggiori di k
void punto3(alb a)
{
    int k;
    cout<<"Inserisci k: "; cin>>k;
    visita_p3(a,k);
    cout<<"\nFATTO!\n\n";
    a.preorder();
}

void visita_p3(alb a, int k)
{
    nodo_a *rad = a.get_radice();
    if(rad!=0)
    {
        int n=rad->get_info().get_n();
        if(n>k){integer num(n-1); rad->set_info(num);}

        visita_p3(rad->get_albsin(), k);
        visita_p3(rad->get_albdes(), k);
    }
}