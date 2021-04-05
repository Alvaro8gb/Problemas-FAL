// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//T(n) = T(n/2) +c1    por tanto O(logn)

char resolver(std::vector<char> const& v, int ini, int fin) {
    
    int m = (ini + fin) / 2;
    if (v[m] - v[ini] > m - ini) {
        if (v[m] - v[m - 1] > 1) return char(v[m] - 1);
        else return resolver(v, ini, m);
    }
    else if (v[fin - 1] - v[m] > fin - 1 - m) {
        if (v[m + 1] - v[m] > 1)return char(v[m] + 1);
        else return resolver(v, m + 1, fin);
    }
    else return v[m]; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    char ini, fin, fugado;

    std::cin >> ini;
    std::cin >> fin;

    std::vector <char> v(fin - ini);
    
    for (int i = 0; i < v.size(); i++)  std::cin >> v[i];

    if (!v.empty()) {
        if (v[0] != ini) fugado = ini;
        else if (v[v.size() - 1] != fin) fugado = fin;
        else fugado = resolver(v, 0, v.size());
        std::cout << fugado << std::endl;
    }      
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