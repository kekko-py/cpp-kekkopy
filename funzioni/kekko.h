

//-----------------------------------------------------------
//FUNZIONE MENU'
void menu(int &sc, int punti)
{
    cout<<"\nOttimo, Adesso Procediamo! \n";
	cout<<"Quele operazioni vuoi che io esegua? \n\n";

	for (int i=0; i<punti; i++) cout<<i+1<<"] PUNTO "<<i+1<<endl;

  	cout<<">> "; cin>>sc;
  	cout<<"\n\n";
}
//-----------------------------------------------------------

//CALCOLO NUMERO FATTORIALE RICORSIVA
int fattoriale(int n) {if(n==0) return 1; return fattoriale(n-1)*n ;}

//-----------------------------------------------------------

//CALCOLO MIN ARRAY INT RICORSIVO
int minimo_array(int vet[], int n, int &min, string type){if(n!=0){if(vet[n-1]<min){if(type=="pos"&&vet[n-1>=0]) min=vet[n-1];else if(type=="neg"&&vet[n-1<0]) min=vet[n-1];else if(type=="all") min=vet[n-1];} }minimo_array(vet,n-1,min,type);}

//-----------------------------------------------------------



//-----------------------------------------------------------

//FUNZIONI INIZIALIZZA ARRAY (Overloading)
void inizializza(int l, int vet[], int &n)
{
    do{
		cout<<"inserisci il numero di elementi del vettore ";
		cin>>n;
	} while(n<0 || n>l);
	for(int i=0;i<n;++i)
	{
		cout<<"inserisci l'elemento successivo ";
		cin>>vet[i];
	}
}

void inizializza(int l, char vet[], int &n)
{
    do{
		cout<<"inserisci il numero di elementi del vettore ";
		cin>>n;
	} while(n<0 || n>l);
	for(int i=0;i<n;++i)
	{
		cout<<"inserisci l'elemento successivo ";
		cin>>vet[i];
	}
}

void visualizza_array(int vet[], int n) {for (int i=0; i<n; i++) cout<<"[ELEMENTO N"<<i+1<<"] --> "<<vet[i]; }

//-----------------------------------------------------------

//FUNZIONE RIC_SEQ RICORSIVA
bool ric_seq(int k, int num, record vet[], int &pos)
{
	pos=num-1;
	if(pos<num && k!=vet[pos].codice) 
		return ric_seq(k, num, vet, pos-1);
	return pos<num;
		
    for (int pos=0; pos<num && k != vet[pos].codice; pos++);
    return pos<num;
}

*/

//FUNZIONE PER VISUALIZZARE UNA MATRICE
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


//VISUALIZZA MATRICE
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