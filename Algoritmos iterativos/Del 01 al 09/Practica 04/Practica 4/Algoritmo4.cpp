//Álvaro García
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
 
    int i = 0,j=0; // i=indice v1 y j =  indice de v2
    std::vector <int> sol;
   
    while (i < v1.size() && j < v2.size()) {

            if (v1[i] < v2[j]) {

                sol.push_back(v1[i]);
                i++;

            }
            else if (v2[j] < v1[i]) {

                sol.push_back(v2[j]);
                j++;

            }
            else {//v1[i] == v2[i]

                sol.push_back(v1[i]);
                i++;
                j++;

            }


    }
    while (i < v1.size()) {
       
        sol.push_back(v1[i]);
        i++;


    }
    while (j < v2.size()) {
        sol.push_back(v2[j]);
        j++;


    }
    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int& j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
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