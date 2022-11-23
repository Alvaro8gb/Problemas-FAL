// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
//Orden de complejidad
/*
* siendo n = fin-ini = v.size()


T(n) = c0, si n=0
T(n) = c1 + T(n/2)  , si n>0

T(n) = c0 + logn*c1 => tiene un orden de complejidad de O(n) = log(n)

*/

int resolver(std::vector<int> const& v, int x, int ini, int fin) {
       
    if (ini == fin) {//Ningun elemento
        return -1;
    }
    else {//mas o igual que un elemento
        int m = (ini + fin) / 2;
        if (m+x < v[m]) return resolver(v, x, ini, m);
        else if (m+x > v[m]) return resolver(v, x, m + 1, fin);
        else return v[m];
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n,x,sol;
    std::cin >> n >> x;

    std::vector <int> v(n);
    for (int i = 0; i < n; i++)  std::cin >> v[i];

    sol = resolver(v, x, 0, v.size());
    if (sol != -1) std::cout << sol << std::endl;
    else std::cout << "NO\n";
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