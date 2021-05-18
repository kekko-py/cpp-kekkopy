class integer
{ int n;

  public:
  	integer(){n=0;}
  	integer(int n1){n=n1;}
  	integer(integer & num){*this=num;}
  	
  	int get_n(){return n;}
  	void set_n(){cout<<"Inserisci un numero intero: "; cin>>n;}
  	void set_n(int n1){n=n1;}
  	
  	void inser_inf(){cout<<"Inserisci un numero intero: "; cin>>n;}
  	void inser_inf(int n1){n=n1;}
  	void inser_inf(integer & num){*this=num;}
  	
  	void visualizza(){cout<<"\nIl numero e': "<<n;}
};
