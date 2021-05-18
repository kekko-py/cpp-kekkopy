/*
Minimo -----> massimo tutti gli elementi di una matrice
Minimo e massimo -----> elementi pari, media elementi dispari
Per ogni riga -----> Somma e prodotto tutti gli elementi
Somma -----> elementi di ogni riga e l'indice della riga cui corrisponde la somma di valore massimo.
Per ogni riga -----> Media elementi pari prodotto elementi dispari
Per ogni riga -----> somma elementi maggiori di un generico k, prodotto elementi minori di k

Prodotto -----> elementi di ogni colonna e l'indice della colonna cui corrisponde il prodotto di valore minimo.

Per ogni colonna -----> Somma e prodotto elementi interni ad un generico intervallo, somma valori esterni allo stesso intervallo.

Scrivere un programma che, data una matrice quadrata di interi:
Restituisca un vettore contenente gli elementi della cornice più esterna secondo l’ordine orario

*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../funzioni/include.h"

const int LUN=100;

#include "../funzioni/funct_base.h"
#include "../funzioni/matrice.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//PROTOTIPI
void punto1(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto2(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto3(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto4(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto5(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto6(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto7(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto8(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto9(int vet[][LUN], unsigned int righe, unsigned int colonne);
void punto10(int vet[][LUN], unsigned int righe, unsigned int colonne);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FUNZIONE PRINCIPALE
int main()
{
    int matrice[LUN][LUN];
    unsigned int righe,colonne;
    inizializza_matrice(matrice,righe,colonne);
    visualizza_matrice(matrice,righe,colonne);
    int sc;
    do
    {
        menu(sc, 10);
        switch(sc)
        {
            case 1: punto1(matrice,righe,colonne);break;
            case 2: punto2(matrice,righe,colonne);break;
            case 3: punto3(matrice,righe,colonne);break;
            case 4: punto4(matrice,righe,colonne);break;
            case 5: punto5(matrice,righe,colonne);break;
            case 6: punto6(matrice,righe,colonne);break;
            case 7: punto7(matrice,righe,colonne);break;
            case 8: punto8(matrice,righe,colonne);break;
            case 9: punto9(matrice,righe,colonne);break;
            case 10: punto10(matrice,righe,colonne);
        } 
    } while (sc>=1&&sc<=10);
    
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Minimo -----> massimo tutti gli elementi di una matrice
void punto1(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int max_elem=INT_MIN;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        if(vet[i][i2]>max_elem) max_elem=vet[i][i2];
    
    cout<<"Massimo: "<<max_elem<<endl;   
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Minimo e massimo -----> elementi pari, media elementi dispari
void punto2(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int max_elem_p=INT_MIN, min_elem_p=INT_MAX, somma_elem_d=0, cont_d=0;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        if(vet[i][i2]%2==0)
        {
            if(vet[i][i2]>max_elem_p) max_elem_p=vet[i][i2];
            if(vet[i][i2]<min_elem_p) min_elem_p=vet[i][i2];
        }
        else{somma_elem_d+=vet[i][i2]; cont_d++;}
    
    if(cont_d>0) cout<<"Media dispari: "<<somma_elem_d/cont_d<<endl;
    cout<<"Minimo pari: "<<min_elem_p<<endl;
    cout<<"Massimo pari: "<<max_elem_p<<endl;    
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Per ogni riga -----> Somma e prodotto tutti gli elementi
void punto3(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int somma_tot=0, prod_tot = 1;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        {somma_tot+=vet[i][i2]; prod_tot*=vet[i][i2];}
    
    cout<<"Somma totale: "<<somma_tot<<endl;
    cout<<"Prodotto totale: "<<prod_tot<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Somma degli elementi di ogni riga e l'indice della riga cui corrisponde la somma di valore massimo.
void punto4(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int somma_tot=0,indice_r,val_max=INT_MIN;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        {
            somma_tot+=vet[i][i2];
            if(vet[i][i2]>val_max){val_max=vet[i][i2]; indice_r=i;}
        }
    cout<<"Somma totale: "<<somma_tot<<endl;
    cout<<"Indice della riga val max"<<indice_r<<endl;     
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Per ogni riga -----> Media elementi pari prodotto elementi dispari
void punto5(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int prod_d=1, somma_elem_p=0, cont_p=0;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        if(vet[i][i2]%2==0){cont_p++; somma_elem_p+=vet[i][i2];}
        else prod_d*=vet[i][i2];

    if(cont_p>0) cout<<"Media pari: "<<somma_elem_p/cont_p<<endl;
    cout<<"Prodotto dispari: "<<prod_d<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Per ogni riga -----> somma elementi maggiori di un generico k, prodotto elementi minori di k
void punto6(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int gen_k, somma_max=0, prod_min=1;
    cout<<"Inserisci un generico valore k: "; cin>>gen_k;

    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        if(vet[i][i2]>i) somma_max+=vet[i][i2];
        else if(vet[i][i2]<i) prod_min*=vet[i][i2];
        
    cout<<"Somma maggiore: "<<somma_max<<endl;
    cout<<"Prodotto minore: "<<prod_min<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Prodotto degli elementi di ogni colonna e l'indice della colonna cui corrisponde il prodotto di valore minimo.
void punto7(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int prod_col=1, indice_c, val_min=INT_MAX;
    for(int i2=0; i2<colonne; i2++)
    {
        prod_col=0;
        for(int i=0; i<righe; i++)
        {
            prod_col*=vet[i][i2];
            if(vet[i][i2]<val_min){val_min=vet[i][i2]; indice_c=i2;}
        }
        cout<<"COLONNA N"<<i2<<endl;
        cout<<"Prodotto totale: "<<prod_col<<endl;
        cout<<"Indice val min"<<indice_c<<endl<<endl;     
    }
        
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Per ogni colonna -----> Somma e prodotto elementi interni ad un generico intervallo, somma valori esterni allo stesso intervallo.
void punto8(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    int inf,sup, somma_ext=0, somma_int=0, prod_ext=1;
    cout<<"inf e sup: "; cin>>inf>>sup;
    for(int i=0; i<righe; i++) for(int i2=0; i2<colonne; i2++)
        if(vet[i][i2]>=inf&&vet[i][i2]<=sup) somma_int+=vet[i][i2];
        else {somma_ext+=vet[i][i2]; prod_ext*=vet[i][i2];}
    
    cout<<"Somma v interni: "<<somma_int<<endl<<endl;
    cout<<"Prodotto v esterni: "<<prod_ext<<endl;
    cout<<"Somma v esterni: "<<somma_int<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Scrivere un programma che, data una matrice quadrata di interi:
//Restituisca un vettore contenente gli elementi della cornice più esterna secondo l’ordine orario

void punto9(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    //CALCOLARE IL PERIMETRO
    int perimetro=(righe+colonne)*2;
    int vet_final[perimetro], j=0;

    //PRENDERE TUTTI GLI ELEMENTI DELLA PRIMA RIGA 
    for(int i2=1; i2<colonne; i2++, j++) vet_final[j]=vet[0][i2];
    //PRENDERE TUTTI GLI ELEMENTI DELL'ULTIMA COLONNA
    for(int i=1; i<righe; i++, j++) vet_final[j]=vet[i][colonne];
    //PRENDERE TUTTI I VALORI DELL'ULTIMA RIGA AL CONTRARIO
    for(int i2=colonne-1; i2!=-1; i2--, j++) vet_final[j]=vet[righe][i2];
    //PRENDERE TUTTI I VALORI DELLA PRIMA COLONNA AL CONTRARIO
    for(int i=righe-1; i!=-1; i--, j++) vet_final[j]=vet[i][0];
 
    visualizza_array(vet_final,perimetro);
}

/*
      A   B   C  --> COLONNE
    ____________
R1 | 1 | 2 | 3 |
R2 | 4 | 5 | 6 |
R3 | 7 | 8 | 9 |
 |
 |
RIGHE
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void punto10(int vet[][LUN], unsigned int righe, unsigned int colonne)
{
    for(int i=0; i<righe && i<colonne; i++)
    {
        cout<<vet[i][i]<<endl;
    }
}