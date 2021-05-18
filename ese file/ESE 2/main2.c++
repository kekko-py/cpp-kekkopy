/*
Dati due file di interi costruire un terzo file 
che contiene le somme degli elementi corrispondenti
dei primi due file
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

bool inizializza(char *nomef);
bool visualizza(char *nomef);

void punto(char *nomef1, char *nomef2, int l);
bool trasferisci_somma(char *nomef1, char *nomef2, char *nomef3);

int main() 
{
	const int LUNS=30;
	char nomef1[LUNS];
    char nomef2[LUNS];
	
	string ris;
	do
	{
		cout<<"Vuoi inizializzare i 2 file? ";
		cin>>ris;
	} while(ris!="SI" && ris!="NO");
	
	if(ris=="SI")
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
	visualizza(nomef1);
    cout<<"Visualizzo il file: "<<nomef2<<endl;
	visualizza(nomef2);
	
	punto(nomef1,nomef2,LUNS);

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
		cout<<"inserisci il numero di valori ";
		cin>>n;
	} while(n<0);
	
	int val;
	for(int i=0;i<n;++i)
	{
		cout<<"inserisci il valore ";
		cin>>val;
		f<<val<<endl;
	}
	
	f.close();
	
	return true;
}

bool visualizza(char * nomef)
{
	ifstream f(nomef);
	
	if(!f.is_open()) return false;
	
	int val;
	while(f>>val)
	  cout<<"il valore e' "<<val<<endl;
	  
	f.close();
	
	return true;
}

void punto(char *nomef1, char *nomef2, int l)
{
	char nomef3[l];
	cout<<"inserisci il nome del file in cui trasferire la somma degli elementi di "<<nomef1<<" & "<<nomef2<<": ";cin>>nomef3;
	
	if(trasferisci_somma(nomef1,nomef2,nomef3))
	  visualizza(nomef3);
	else
	  cout<<"trasferimento non avvenuto ";
}

bool trasferisci_somma(char *nomef1,char *nomef2, char *nomef3)
{
	ifstream f1(nomef1), f2(nomef2);
    ofstream f3(nomef3);
	
	if(!f1.is_open() || !f2.is_open() || !f3.is_open()) return false;
	
	int val1,val2;
	while(f1>>val1 && f2>>val2)
	    f3<<val1+val2<<endl;
	    
	f1.close();
	f2.close();
    f3.close();
	
	return true;	
}

