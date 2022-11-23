// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
//Orden de complejidad
/*
* siendo n = fin-ini = v1.size()


T(n) = c0, si n=1
T(n) = c1 + T(n/2)  , si n>1

T(n) = c0 + logn*c1 => tiene un orden de complejidad de O(n) = logn

*/

int resolver(std::vector<int> const& v1, std::vector<int> const& v2, int ini, int fin) {

    
    if(ini + 1 == fin) return v1[ini]; //un elemento
    else {
        int m = (ini + fin-1)/2;
        if (v1[m] == v2[m]) return resolver(v1, v2, m+1 , fin);
        else return  resolver(v1, v2, ini, m+1);

    }
   /*
    if (ini == fin) return v1[ini]; //ningun elemento
    else {
        int m = (ini + fin ) / 2;
        if (v1[m] == v2[m]) return resolver(v1, v2, m, fin);
        else return  resolver(v1, v2, ini, m );

    }

    */
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n;
    std::cin >> n;

    std::vector <int> v1(n);
    for (int i = 0; i < n; i++)  std::cin >> v1[i];
    
    std::vector <int> v2(n-1);

    for (int j = 0; j <n-1; j++)  std::cin >> v2[j];
   

     std::cout << resolver(v1, v2, 0, v1.size()) << "\n";
    
   

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}