// ÁLVARO GARCÍA BARRAGÁN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste del algoritmo

/*

Como las asignaciones ,comparaciones y inserciones son de coste constante solo hace falta analizar el bucle for

El bucle for da n-1 vueltas siendo n el numero de datos tomados de la imagen aerea .

Por tanto el coste del algoritmo  es lineal (O(n))

*/

std::vector <int> resolver(std::vector <int>const & v,int l,int &numSuper) {
    std::vector <int> sol;
    int pos,cont=1;

    for (int i = 0; i < v.size()-1; i++) {

        if (cont == 1) {
            pos = i;
        }

        if (abs(v[i] - v[i + 1]) <= 1) {
            
            cont++;
            if (cont == l) {
                numSuper++;
                sol.push_back(pos);
            }
        }
        else cont = 1;

    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,l;
    std::cin >> n >>l;
    if (n==0)return false;
    else {
       std::vector <int> v(n);
       for (int i = 0; i < n; i++) std::cin >> v[i];

       int numSuperficies = 0;
       std::vector <int> sol = resolver(v,l, numSuperficies);

       std::cout << numSuperficies;

       for (int i = 0; i < sol.size(); i++) std::cout << " " <<sol[i];

       std::cout << std::endl;
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}