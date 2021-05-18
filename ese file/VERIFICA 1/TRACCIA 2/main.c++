/*
SECONDA TRACCIA:
______
2. E’ dato un file di testo contenente una lista di telefonate effettuate da un utente.
Ciascuna riga contiene la città di destinazione della telefonata, la durata in secondi e il
numero di scatti.
Un possibile esempio è il seguente:
ROMA 230 5
MILANO 30 3
ROMA 20 1

Si scriva un programma che, dato il nome di una città, restituisca il numero minimo e quello massimo
 di secondi delle telefonate verso quella città e trasferisca le informazioni circa il
numero di scatti delle telefonate verso quella città in un secondo file e in un terzo file tutte
 le informazioni sulle telefonate verso altre città presenti nel primo file
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
bool trasferisci(char *nomef1, char *nomef2, char *nomef3);

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
	char nomef2[l], nomef3[l];
	cout<<"inserisci il nome del file in cui trasferire: ";cin>>nomef2;
	if(trasferisci(nomef1,nomef2,nomef3))
    {
	  visualizza(nomef2); visualizza(nomef3);
    }
    else
	  cout<<"trasferimento non avvenuto ";
}

bool trasferisci(char *nomef1,char *nomef2, char *nomef3)
{
	ifstream f1(nomef1); 
    ofstream f2(nomef2), f3(nomef3);
	if(!f1.is_open() || !f2.is_open() || !f3.is_open()){cout<<"Il file non \212 stato aperto con successo!"; return false;}

//Si scriva un programma che, dato il nome di una città, restituisca il numero minimo e quello massimo
//di secondi delle telefonate verso quella città e trasferisca le informazioni circa il
//numero di scatti delle telefonate verso quella città in un secondo file e in un terzo file tutte
//le informazioni sulle telefonate verso altre città presenti nel primo file
    int min_durata=INT_MAX, max_durata=INT_MIN;
    log_telefonata log;
    while(f1>>log.citta>>log.durata>>log.scatti)
    { 
    if(log.citta==log.citta){ 
        if(log.durata<min_durata)
            min_durata=log.durata;

        if(log.durata>max_durata)
            max_durata=log.durata;
        
        f2<<log.scatti<<endl;
	}
	else
	  f3<<log.citta<<'\t'<<log.durata<<'\t'<<log.scatti<<endl;
  }
  
  cout<<"\nDurata minima: "<<min_durata;
  cout<<"\nDurata massima: "<<max_durata;
  
  f1.close(); f2.close(); f3.close();
  
  return true;
}