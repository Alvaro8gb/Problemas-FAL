//*****************
// ÁLVARO GARCÍA BARRAGÁN
// A31
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>



// Aqui la funcion recursiva que resuelve el problema

int resolver(std::vector<int> const& v, int ini, int fin) {

    if (ini + 1 == fin) //un elemento
        return v[ini];
    else {
        int m = (ini + fin) / 2;
        if (v[m] > v[ini]) return resolver(v, ini, m);
        else return  resolver(v, m, fin);  
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

    while (resuelveCaso());

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
