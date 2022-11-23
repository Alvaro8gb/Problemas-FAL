// ÁLVARO GARCÍA BARRAGÁN 
//A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//Coste de recursión

/*
* n=fin-ini= longitud de la fila
T(n) = c0  si n=1
T(n) =2T(n/2) + 2n + c1

Esto aplicando mates sale que T(n) pertenece al orden de O(nlogn)
 

 el coste del bucle while:
  - en el peor caso (en que el vector esta ordenado de forma decreciente ) es lineal ya que da n vueltas
  - en el mejor caso da m vueltas.

  la mezcla ordenada tiene coste lineal.
*/


// función que resuelve el problema
int resolver(std::vector <int>& v, int ini, int fin) {
    if (ini + 1 == fin) return 0; //un elemento
    else {//2 elementos o mas
        int m = (ini + fin) / 2;

        int iz = resolver(v, ini, m);
        int dr = resolver(v, m, fin);

        
        int i = ini,j=m,inversiones = iz+dr;
     
        while (i < m && j< fin) {
        
            if (v[i] < v[j])  i++;
            else{
                inversiones += m - i ;
                j++;
            }
        }
        std::inplace_merge(v.begin() + ini, v.begin() + m, v.begin() + fin);
        return inversiones;
       
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    std::cin >> n;

    if (!std::cin) return false;
    else {
        std::vector <int> v(n);
       
        for (int i = 0; i < n; i++)   std::cin >> v[i];
   
        int sol = resolver(v, 0, n);
        std::cout << sol<<"\n";

        return true;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}