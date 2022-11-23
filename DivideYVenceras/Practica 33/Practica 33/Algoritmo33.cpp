//*****************
// ÁLVARO GARCÍA BARRAGÁN
// A31
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

/*
* n = tamaño del vector = v.size()= fin-ini
T(n) = c0 si n=1
T(n) = c1 si n=2
T(n) = c2 + T(n/2)= si n>2

desarollando queda que T(n)= k* c2 +T(n/(2^k))
T(2) = c1 , 2= n/(2^k) => k =log2(n)+1 

T(n) = (log2(n)+1)* c2 + c1 == log(n)
Por tanto el coste del logaritmo es O(logn)


El algoritmo solo llega al caso T(1) cuando n=1 por tanto es irrelevante.

*/

// Aqui la funcion recursiva que resuelve el problema

int resolver(std::vector<int> const& v, int ini, int fin) {

   
     if (ini + 1 == fin) {//que tenga un elemento
        return v[ini];
     }
     else if (ini + 2 == fin) {//que tenga dos
         return v[ini] > v[ini+1]?v[ini+1]:v[ini];
     }
     else {
        int m = (ini + fin) / 2;
        if (v[m]>v[m-1])return resolver(v, ini, m);
        else if (v[m] > v[m+1])  return  resolver(v, m, fin);
        else return v[m];
     }

}
bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) {
        return false;
    }
    else {

        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) std::cin >> v[i];

        std::cout << resolver(v, 0, n) << '\n';
        return true;
    }
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while(resuelveCaso());

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
