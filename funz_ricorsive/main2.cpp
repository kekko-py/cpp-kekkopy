using namespace std;
#include <iostream>

void inizializza(int l,int vet[],int & n);

void punto(int vet[],int n);

void somma_prod(int vet[],int n,int & somma,int & prod);



int main() 
{
	const int LUN=100;
	int vet[LUN];
	int n;
	
	inizializza(LUN,vet,n);
	
	punto(vet,n);
	
	return 0;
}

void inizializza(int l,int vet[],int & n)
{
	do
	{
		cout<<"inserisci il numero di elementi del vettore ";
		cin>>n;
	} while(n<0 || n>l);
	

	for(int i=0;i<n;++i)
	{
		cout<<"inserisci l'elemento successivo ";
		cin>>vet[i];
	}	
}

void punto(int vet[],int n)
{
	int s_p=0,p_d=1;
	
	somma_prod(vet,n,s_p,p_d);
	
	cout<<"...."<<s_p<<"\n..."<<p_d;
	
		
}


void somma_prod(int vet[],int n,int & somma,int & prod)
{
	if(n!=0)
	{
		if(vet[n-1]%2==0)
	      somma+=vet[n-1];
	    else
	      prod*=vet[n-1];
	      
	    somma_prod(vet,n-1,somma,prod);
	}  	
}






