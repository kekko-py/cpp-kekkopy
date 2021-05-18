/*
PRIMA TRACCIA: 
________
1. E’ dato un file di testo contenente una lista di telefonate effettuate da un utente.
Ciascuna riga contiene: la città di destinazione della telefonata, la durata in secondi e il
numero di scatti.
Un possibile esempio è il seguente:
ROMA 230 5
MILANO 30 3
ROMA 20 1
Si scriva un programma che, dato il nome di una città, restituisca il numero totale di scatti
effettuati in telefonate verso quella città e trasferisca le informazioni sulla durata e
sul numero di scatti delle telefonate verso tale città in un secondo file.
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

struct log_telefonata{
    string citta;
    int durata;
    int scatti;
};

bool inizializza(char *nomef);
bool visualizza(char *nomef);
void punto(char *nomef1, int l);
bool trasferisci(char *nomef1, char *nomef2);

int main(){
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
	if(!visualizza(nomef1)){cout<<"Si \212 verificato un errore."; return 0;};
	punto(nomef1,LUNS);
	return 0;
}

bool inizializza(char *nomef)
{
    cout<<"Inserisci il nome da assegnare al file: ";cin>>nomef;
	ofstream f(nomef);
	
	if(!f.is_open()){cout<<"Il file non \212 stato aperto con successo!"; return false;}
	
	int n;
	do
	{
		cout<<"inserisci il numero di prodotti ";
		cin>>n;
	} while(n<0);
	
	log_telefonata log;
	cout<<"Inserisci un prodotto formato: [NOME DURATA SCATTI]\n";
	for(int i=0;i<n;++i)
	{
		cout<<'n'<<i+1<<">> ";
		cin>>log.citta>>log.durata>>log.scatti;
		f<<log.citta<<' '<<log.durata<<' '<<log.scatti<<endl;
	}
	f.close();
	return true;
}

bool visualizza(char * nomef)
{
	ifstream f(nomef);
	if(!f.is_open()) return false;
	
	log_telefonata log;
	cout<<"\t________________________________\n"; 
	cout<<"\tNOME\tDURATA\tSCATTI\n";
	for(int i=1; f>>log.citta>>log.durata>>log.scatti; i++)
	{
		cout<<"  \t______|________|_______|________\n";
		cout<<'n'<<i<<"\t"<<log.citta<<"\t|"<<log.durata<<"\t|"<<log.scatti<<"\t|"<<endl;
	}
	cout<<"  \t________________________________\n";  
	f.close();
	
	return true;
}

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
    log_telefonata log;
	ifstream f1(nomef1); 
    ofstream f2(nomef2);
	if(!f1.is_open() || !f2.is_open()){cout<<"Il file non \212 stato aperto con successo!"; return false;}

    //Si scriva un programma che, dato il nome di una città, restituisca il numero totale di scatti
    //effettuati in telefonate verso quella città e trasferisca le informazioni sulla durata e
    //sul numero di scatti delle telefonate verso tale città in un secondo file.
    string gen_citta;
	cout<<"inserisci il nome di una generica citta': ";cin>>gen_citta;
	
	int scatti_tot=0;
	
	while(f1>>log.citta>>log.durata>>log.scatti)
		if(log.citta==gen_citta)
		{
			scatti_tot+=log.scatti;
			f2<<log.durata<<' '<<log.scatti<<endl;
		}
		
	f1.close();
	f2.close();
	
	cout<<"il numero totale di scatti delle telefonate verso la generica citta' sono: "<<scatti_tot<<endl;
	
	return true;
}