/*
Dato un file contenente su ogni riga le seguenti informazioni:
nome prodotto,
tipo prodotto (A per alimentari, D per detersivi),
quantità acquistata,
prezzo.

calcolare il quantitativo minimo e quello massimo dei detersivi trasferendo
in un nuovo file le informazioni sui prodotti il cui prezzo è superiore ad un generico valore.

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
bool trasferisci(char *nomef1, char *nomef2);

int main() 
{
	const int LUNS=30;
	char nomef1[LUNS];
	
	string ris;
	do{
		cout<<"Vuoi inizializzare il file? ";cin>>ris;
	}while(ris!="SI" && ris!="NO" && ris!="si" && ris!="no");
	
	if(ris=="SI"||ris=="si"){if(!inizializza(nomef1)) return 0;}
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
	cout<<"Inserisci un prodotto formato: [NOME TIPO QUANTITA' PREZZO]\n";
	for(int i=0;i<n;++i)
	{
		cout<<'n'<<i+1<<">> ";
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

/*
calcolare il quantitativo minimo e quello massimo dei detersivi trasferendo
in un nuovo file le informazioni sui prodotti il cui prezzo è superiore ad un generico valore.
*/
void punto(char *nomef1, int l)
{
	char nomef2[l];
	cout<<"inserisci il nome del file in cui trasferire: ";cin>>nomef2;
	if(trasferisci(nomef1,nomef2))
	  visualizza(nomef2);
	else
	  cout<<"trasferimento non avvenuto ";
}

bool trasferisci(char *nomef1,char *nomef2)
{
    prodotto p;
	ifstream f1(nomef1); 
    ofstream f2(nomef2);
	if(!f1.is_open() || !f2.is_open()) return false;
	
    float gen_val;
    cout<<"Inserisci un generico valore decimale: ";cin>>gen_val;
    int quant_min_d = INT_MAX, quant_max_d=INT_MIN;
    while(f1>>p.nome && f1>>p.tipo && f1>>p.quantita && f1>>p.prezzo)
    {
        if(p.tipo == 'D')
        {
            if(p.quantita>quant_max_d) quant_max_d=p.quantita;
            if(p.quantita<quant_min_d) quant_min_d=p.quantita;
        }
        if(p.prezzo>gen_val) f2<<p.nome<<' '<<p.prezzo<<' '<<p.quantita<<' '<<p.tipo<<endl;
    }

	cout<<"Quantitativo Massimo [Detersivi]: "<<quant_max_d<<"pz."<<endl;
	cout<<"Quantitativo Minimo [Detersivi]:  "<<quant_min_d<<"pz."<<endl;

	f1.close();
	f2.close();
	return true;	
}