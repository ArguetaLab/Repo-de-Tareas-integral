#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

class Funciones{
    public:
        unsigned int sumaIterativa(int n){

        int cont = 0;
        for(int i=1; i<=n; i++){
        cont += i;
        }
        return cont;
        }


        unsigned int sumaRecursiva(int n){
            if(n<=0){
                return 0;
            }

        else{
            n = n + sumaRecursiva(n-1);
            return n;
        }
        }

        unsigned int sumaDirecta(int n){
            int suma = (n*(n+1))/2;
            return suma;
        }

};
#endif // FUNCIONES_H_INCLUDED
