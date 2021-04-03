// Alvaro Garcia Barragán
// A31

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

/* El algoritmo lleva tres indices que van llevando la posicion de los elementos de ese color que ya estan ordenados.Con el paso de
los ciclos se van quedando dos partes bien ordenadas la del principio y final .Cuando k=q+1 el algoritmo termina quedando
la parte central bien ordenada tambien*/

// Coste del algoritmo utilizado 
/* El algoritmo tiene coste lineal n, siendo n el numero de cintas , ya que tiene que dar n vueltas + un valor x
*  constante de swaps, asiganciones.En el peor caso daria un valor x mas grande , que es si estuviera ordenado de forma invertida. Al ser X constante no influye.
Por tanto el coste del algoritmo es O(numero de cintas)
*/


using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion(std::vector<psi>& v, int& p, int& q) {
    // Aqui codigo del estudiante
   
    int k = 0; //q+1 //primera de las rojas
    p = 0; //primera  pos cinta verdes(siguente ala ultima de las azules)
    q = (int)v.size() - 1; //ultima pos verdes
 
    while (k<=q) {

        if (v[k].first == 'v') k++;
        else if (v[k].first == 'a') {     
            swap(v[p], v[k]);
            k++;
            p++;
        }
        else {//v[k] == r
            swap(v[k], v[q]);
            q--;

        }
    }

       
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi& n : v) {
        std::cin >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin() + p);
    std::sort(v.begin() + p, v.begin() + (q + 1));
    std::sort(v.begin() + (q + 1), v.end());
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q + 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
        return 0;
}
