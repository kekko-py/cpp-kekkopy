/*
Dato un file contenente su ogni riga le seguenti informazioni:
nome prodotto,
tipo prodotto (A per alimentari, D per detersivi) 
quantità acquistata, 
prezzo,

calcolare: 
    prezzo medio dei prodotti acquistati in quantità pari
    ad un generico valore e trasferire in un secondo file le informazioni 
    sui prodotti il cui quantitativo di acquisto è superiore ad un generico valore e
    in un terzo quelle sui prodotti acquistati in quantità inferiore allo stesso generico valore.
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

struct prodotto{
    string nome;
    char tipo; //(A per alimentari, D per detersivi),
    int quantita;
    float prezzo;
};

bool inizializza(char *nomef);
bool visualizza(char *nomef);

void punto(char *nomef1, int l);
bool trasferisci_a(char *nomef1,char *nomef2,char *nomef3);

int main() 
{
	const int LUNS=30;
	char nomef1[LUNS];
	
	string ris;
	do{
		cout<<"Vuoi inizializzare il file? ";cin>>ris;
	}while(ris!="SI" && ris!="NO" && ris!="si" && ris!="no");
	
	if(ris=="SI"||ris=="si")
    {
		if(!inizializza(nomef1)) return 0;
    }
	else
	{
		cout<<"Inserisci il nome del file: \n";
		cout<<"File 1: \n";cin>>nomef1;
	}
	cout<<"Visualizzo il file: "<<nomef1<<endl;
	visualizza(nomef1);
	
	punto(nomef1,LUNS);

	return 0;
}

bool inizializza(char *nomef)
{
    cout<<"Inserisci il nome da assegnare al file: ";cin>>nomef;
	ofstream f(nomef);
	
	if(!f.is_open()) return false;
	
	int n;
	do
	{
		cout<<"inserisci il numero di prodotti ";
		cin>>n;
	} while(n<0);
	
	prodotto p;
	for(int i=0;i<n;++i)
	{
		cout<<"Inserisci un prodotto formato: [NOME TIPO QUANTITA' PREZZO]\nn"<<i+1<<">> ";
		cin>>p.nome>>p.tipo>>p.quantita>>p.prezzo;
		f<<p.nome<<' '<<p.tipo<<' '<<p.quantita<<' '<<p.prezzo<<endl;
	}
	
	f.close();
	
	return true;
}

bool visualizza(char * nomef)
{
	ifstream f(nomef);
	
	if(!f.is_open()) return false;
	
	prodotto p;
	cout<<"\t________________________________\n"; 
	cout<<"\tNOME\tTIPO\tQUANTITA   PREZZO \n";
	for(int i=1; f>>p.nome && f>>p.tipo && f>>p.quantita && f>>p.prezzo; i++)
	{
		cout<<"  \t______|________|_______|________\n";
		cout<<'n'<<i<<"\t"<<p.nome<<"\t|"<<p.tipo<<"\t|"<<p.quantita<<"\t|"<<p.prezzo<<endl;
	}
	cout<<"  \t________________________________\n";  
	f.close();
	
	return true;
}

void punto(char *nomef1, int l)
{
    char nomef2[l],nomef3[l];
	cout<<"inserisci il nome del file in cui trasferire: [1' file]";cin>>nomef2;
    cout<<"inserisci il nome del file in cui trasferire: [2' file]";cin>>nomef3;
	if(trasferisci_a(nomef1,nomef2,nomef3))
    {
        cout<<"\nPrimo file:\n";
	    visualizza(nomef2);
        cout<<"\nSecondo file:\n";
        visualizza(nomef3);
    }
    else
	  cout<<"trasferimento non avvenuto ";
}

bool trasferisci_a(char *nomef1,char *nomef2,char *nomef3)
{
    prodotto p;
	ifstream f1(nomef1); 
    ofstream f2(nomef2), f3(nomef3);
	
	if(!f1.is_open() || !f2.is_open()) return false;
	/*
    prezzo medio dei prodotti acquistati in quantità pari
    ad un generico valore
	*/
    int gen_val;
    cout<<"Inserisci un generico valore intero: ";cin>>gen_val;
    float prez_som=0; int cont_prez=0;
    while(f1>>p.nome && f1>>p.tipo && f1>>p.quantita && f1>>p.prezzo)
    {
        
        // prezzo medio dei prodotti acquistati in quantità pari
        // ad un generico valore
        if(p.quantita==gen_val){ prez_som+=p.prezzo; ++cont_prez;}
        // trasferire in un secondo file le informazioni 
        // sui prodotti il cui quantitativo di acquisto è superiore ad un generico valore
        if(p.quantita>gen_val) f2<<p.nome<<' '<<p.prezzo<<' '<<p.quantita<<' '<<p.tipo<<endl;
        // in un terzo quelle sui prodotti acquistati in quantità
        // inferiore allo stesso generico valore.
        if(p.quantita<gen_val) f3<<p.nome<<' '<<p.prezzo<<' '<<p.quantita<<' '<<p.tipo<<endl;
    }

    cout<<"Prezzo medio: "<<prez_som/cont_prez<<endl;

	f1.close();
	f2.close();
	
	return true;	
}

