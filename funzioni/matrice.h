//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE PER VISUALIZZARE UNA MATRICE (overloading)
//const int LUN=100;
void inizializza_matrice(int vet[][LUN], unsigned int &righe, unsigned int &colonne)
{
	do{
		cout<<"inserisci il numero delle righe e delle colonne: ";
		cin>>righe>>colonne;
	} while(righe<0 || colonne<0);

	for(int i=0; i<righe; i++)
	{
		cout<<endl; 
		for(int i2=0; i2<colonne; i2++)
		{
			cout<<"[RIGA "<<i+1<<"] - "<<"[COLONNA "<<i2+1<<"]\t>> "; cin>>vet[i][i2];
		}
	}
}

void inizializza_matrice(char vet[][LUN], unsigned int &righe, unsigned int &colonne)
{
	do{
		cout<<"inserisci il numero delle righe e delle colonne: ";
		cin>>righe>>colonne;
	} while(righe<0 || colonne<0);

	for(int i=0; i<righe; i++)
	{
		cout<<endl; 
		for(int i2=0; i2<colonne; i2++)
		{
			cout<<"[RIGA "<<i+1<<"] - "<<"[COLONNA "<<i2+1<<"]\t>> "; cin>>vet[i][i2];
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//VISUALIZZA MATRICE (overloading)
void visualizza_matrice(int vet[][LUN], int righe, int colonne)
{
	for(int i=0; i<righe; i++) 
	{
		cout<<endl; 
		for(int i2=0; i2<colonne; i2++)
		{
			cout<<"[RIGA "<<i+1<<"] - "<<"[COLONNA "<<i2+1<<"]\t-->\t"<<vet[i][i2]<<endl;
		}
	}
}
void visualizza_matrice(char vet[][LUN], int righe, int colonne)
{
	for(int i=0; i<righe; i++) 
	{
		cout<<endl; 
		for(int i2=0; i2<colonne; i2++)
		{
			cout<<"[RIGA "<<i+1<<"] - "<<"[COLONNA "<<i2+1<<"]\t-->\t"<<vet[i][i2]<<endl;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
