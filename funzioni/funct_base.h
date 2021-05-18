//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE MENU'
int menu(int punti){
    int sc;
     cout<<"\nOttimo, Adesso Procediamo! \n";
      cout<<"Quele operazioni vuoi che io esegua? \n\n";
       for (int i=0; i<punti; i++) cout<<i+1<<"] PUNTO "<<i+1<<endl; 
       do{
           cout<<">> ";
           cin>>sc;
       }while(sc<0||sc>punti);
         cout<<"\n\n";
         return sc;
         }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE VISUALIZZA ARRAY (overloading)
void visualizza_array(int vet[], int n) {for (int i=0; i<n; i++) cout<<"[ELEMENTO N"<<i+1<<"] --> "<<vet[i]<<endl; }
void visualizza_array(char vet[], int n) {for (int i=0; i<n; i++) cout<<"[ELEMENTO N"<<i+1<<"] --> "<<vet[i]<<endl; }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE INIZIALIZZA ARRAY (overloading)
void inizializza(int l, int vet[], int &n){do{cout<<"inserisci il numero di elementi del vettore ";cin>>n;} while(n<0 || n>l);for(int i=0;i<n;++i){cout<<"inserisci l'elemento successivo ";cin>>vet[i];}}
void inizializza(int l, char vet[], int &n){do{cout<<"inserisci il numero di elementi del vettore ";cin>>n;} while(n<0 || n>l);for(int i=0;i<n;++i){cout<<"inserisci l'elemento successivo ";cin>>vet[i];}}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//CALCOLO MAX ARRAY INT RICORSIVO 
int massimo_array(int vet[], int n, int &max, string type){if(n!=0){if(vet[n-1]>max){if(type=="pos"&&vet[n-1>=0]) max=vet[n-1];else if(type=="neg"&&vet[n-1<0]) max=vet[n-1];else if(type=="all") max=vet[n-1];} }massimo_array(vet,n-1,max,type);}
//CALCOLO MIN ARRAY INT RICORSIVO
int minimo_array(int vet[], int n, int &min, string type){if(n!=0){if(vet[n-1]<min){if(type=="pos"&&vet[n-1>=0]) min=vet[n-1];else if(type=="neg"&&vet[n-1<0]) min=vet[n-1];else if(type=="all") min=vet[n-1];} }minimo_array(vet,n-1,min,type);}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~