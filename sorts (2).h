#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>

template <class T>
class Sorts {
public:
    void ordenaSeleccion(std::vector<T> &v);
    void ordenaBurbuja(std::vector<T> &v);
    void ordenaMerge(std::vector<T> &v);
    T busqSecuencial(const std::vector<T> &, int valor);
    T busqBinaria(const std::vector<T> &, int valor);
};



template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) {

    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            //Voltea los valores
            std::swap(v[i], v[min]);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) {

      for (int j = 0; j < v.size() - 1; ++j)
      {
        for (int i = 0; i < v.size() - j - 1; ++i)
        {
          if (v[i] > v[i + 1])
          {
            std::swap(v[i], v[i+1]);
          }
        }
      }
}

template <class T>

void Sorts<T>::ordenaMerge(std::vector<T> &v) {
    /*
    Recuerdese que este algortimo utliza la logica de divbide y venceras
    En etse caso divideimos el algortimo en partes eseciales.

    1. Dividir el array original en 2
    2. Sorteqar los arrays chikitos y mezclarlos en uno nuevo

    */

   int n = v.size();

    // Caso base: si el vector tiene 0 o 1 elemento, ya está ordenado
    if (n <= 1) {
        return;
    }

    int mid = n / 2;

    // Creamos dos vectores auxiliares para dividir el vector original
    std::vector<T> left(v.begin(), v.begin() + mid);
    std::vector<T> right(v.begin() + mid, v.end());

    // Llamadas recursivas para ordenar las dos mitades
    ordenaMerge(left);
    ordenaMerge(right);

    int i = 0; // Índice para recorrer el vector 'left'
    int j = 0; // Índice para recorrer el vector 'right'
    int k = 0; // Índice para recorrer el vector original 'v'

    // Combinamos las dos mitades ordenadas en el vector original 'v'
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    // Copiamos los elementos restantes de 'left', si los hay
    while (i < left.size()) {
        v[k] = left[i];
        i++;
        k++;
    }

    // Copiamos los elementos restantes de 'right', si los hay
    while (j < right.size()) {
        v[k] = right[j];
        j++;
        k++;
    }
} // -- FIN DE LA FUNCION MERGE -- //


template <class T>

T Sorts<T>::busqSecuencial(const std::vector<T>&source, int valor){
    int mid;
    int low = 0;
    int high = source.size() - 1;

    while (low < high) {
        mid = (high + low) / 2;
        if(valor == source[mid]) {
            return mid;
        } else if(valor < source[mid]) {
            high = mid - 1;
        } else if(valor > source[mid]) {
            low = mid + 1;
        }
        }
    if(source[low]==valor){
      return low;
    }
    else{
        return -1;
    }

}

template <class T>

int bs_aux(std::vector<T> &v,int low, int high, int valor) {
    int mid;

	if (low <= high) {
		mid = (high + low) / 2;
		if (valor == v[mid]) {
			return mid;
		} else if (valor < v[mid]) {
			return bs_aux(v, low, mid - 1, valor);
		} else if (valor > v[mid]) {
			return bs_aux(v, mid + 1, high, valor);
		}
	}
	if(v[low]==valor){
        return low;
	}
	else{
        return -1;
	}

}

template <class T>
T Sorts<T>::busqBinaria(const  std::vector<T> &source,int valor) {
    std::vector<T> v(source);
    return bs_aux(v,0,v.size()-1, valor);
}

#endif // SORTS_H
