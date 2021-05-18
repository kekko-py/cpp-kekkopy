/*
3. Sono dati due file di testo contenenti due liste di telefonate effettuate da un utente.
Ciascuna riga contiene la città di destinazione della telefonata, la durata in secondi e il
numero di scatti.
Un possibile esempio è il seguente:
ROMA 230 5
MILANO 30 3
ROMA 20 1

Si trasferiscano in un terzo file tutte le informazioni sulle telefonate del primo elenco che
hanno la stessa destinazione della telefonata corrispondente del secondo elenco e in un
quarto elenco quelle che hanno destinazione diversa.
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
void punto(char *nomef1, char *nomef2, int l);
bool trasferisci(char *nomef1, char *nomef2, char *nomef3, char *nomef4);

int main(){
    const int LUNS=30;
	char nomef1[LUNS],nomef2[LUNS];
	
	string ris;
	do{
		cout<<"Vuoi inizializzare i file? ";cin>>ris;
	}while(ris!="SI" && ris!="NO" && ris!="si" && ris!="no");
	
	if(ris=="SI"||ris=="si")
    {
        if(!inizializza(nomef1) || !inizializza(nomef2)) return 0;
    }
	else
	{
		cout<<"Inserisci il nome dei file: \n";
		cout<<"File 1: \n";cin>>nomef1;
        cout<<"File 2: \n";cin>>nomef2;
	}
	cout<<"Visualizzo il file: "<<nomef1<<endl;
    cout<<"File 1\n";
	if(!visualizza(nomef1)){cout<<"Si \212 verificato un errore."; return 0;};
    cout<<"File 2\n";
    if(!visualizza(nomef1)){cout<<"Si \212 verificato un errore."; return 0;};
	punto(nomef1,nomef2,LUNS);
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

void punto(char *nomef1, char *nomef2, int l)
{
	char nomef3[l],nomef4[l];
	cout<<"inserisci il nome del file in cui trasferire: ";cin>>nomef2;
    cout<<"inserisci il nome del file in cui trasferire: ";cin>>nomef3;
    cout<<"inserisci il nome del file in cui trasferire: ";cin>>nomef4;
	if(trasferisci(nomef1,nomef2,nomef3,nomef4))
    {
      cout<<"File 1\n";
	  visualizza(nomef2);
      cout<<"File 2\n";
      visualizza(nomef3);
      cout<<"File 3\n";
      visualizza(nomef4);
    }
    else
	  cout<<"trasferimento non avvenuto ";
}

bool trasferisci(char *nomef1, char *nomef2, char *nomef3, char *nomef4)
{
    log_telefonata log1,log2;
	ifstream f1(nomef1), f2(nomef2); 
    ofstream f3(nomef3), f4(nomef4);
	if(!f1.is_open() || !f2.is_open() || !f3.is_open()){cout<<"Il file non \212 stato aperto con successo!"; return false;}
    
    //Si trasferiscano in un terzo file tutte le informazioni sulle telefonate del primo elenco che
    //hanno la stessa destinazione della telefonata corrispondente del secondo elenco e in un
    //quarto elenco quelle che hanno destinazione diversa.
    while(f1>>log1.citta>>log1.durata>>log1.scatti && f2>>log2.citta>>log2.durata>>log2.scatti)
    { 
        if(log1.citta==log2.citta)
            f3<<log1.citta<<' '<<log1.durata<<' '<<log1.scatti;
        else
            f4<<log1.citta<<' '<<log1.durata<<' '<<log1.scatti;
    }
	f1.close(); f2.close(); f3.close(); f4.close();
	return true;
}