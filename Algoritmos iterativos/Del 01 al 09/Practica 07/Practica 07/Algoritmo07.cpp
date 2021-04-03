//Álvaro García
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using lli = long long int;

// función que resuelve el problema
std::vector<lli> resolver(std::vector<lli>const& v1, std::vector<lli>const& v2) {

    long int i = 0, j = 0; // i=indice v1 y j =  indice de v2
    std::vector <lli> sol;


    while (i < v1.size() && j < v2.size()) {

        if (v1[i] < v2[j]) {

            i++;

        }
        else if (v2[j] < v1[i]) {

        
            j++;

        }
        else {//v1[i] == v2[i]

            sol.push_back(v1[i]);
            i++;
            j++;

        }


    }
 
    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos de entrada

    lli dato;
        
    std::vector<lli> v1; 
    std::vector<lli> v2;
   

    std::cin >> dato;
    while (dato != 0) {
        v1.push_back(dato);
        std::cin >> dato;
    }

    std::cin >> dato;
    while (dato != 0) {
        v2.push_back(dato);
        std::cin >> dato;
    }
  

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
        
   


    // LLamada a la función que resuelve el problema
    std::vector<lli> sol = resolver(v1, v2);

    if (!sol.empty()) {
        std::cout << sol[0];
        for (long int i = 1; i < sol.size(); ++i)
            std::cout << ' ' << sol[i];
    }

 
    std::cout << '\n';
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