//--------- somma.h --------------
namespace somma{
    class somma{
        public:
            int somma_2val(int x,int y);
    };
}
int somma_2val(int x,int y){return x+y;}


//--------- main.cpp --------------
using namespace std;

//Per omettere somma:: prima del nome del modulo
using namespace somma;

#include <iostream>
#include "somma.h"

cout<<"---> "<<somma_2val(5, 10)<<endl;

//Se non avessi usato [using namespace somma;] :
//undefined reference to `somma::somma_2val(int, int)'