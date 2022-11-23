// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <utility>

// Explicación del algoritmo utilizado

/* Recorre el vector buscando elementos que cumplen la propiedad que nos interesa que en este caso es ser par
cuando lo encuentra lo intercambia con el elemento que tiene el indice ultimo de los elementos interesados
quedando todos los elementos no interesados ala izquierda del vector,finalmente cuando termine para borrar los elementos
no interesados cambia el tamaño del vector al ultimo indice de los elementos interesados
*/



// Coste del algoritmo utilizado
/* Una asigancion de conteste contante al rpincipi + el bucle principal con un coste de O(v.size) siempre y dentro de el
una condicional ,un swap,y un incremento ambas de coste constante

Por tanto coste del algoritmo : O(n),siendo n el numero de elementos del vector*/


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    // Codigo del alumno
    int VB=0;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] % 2 == 0) {
           std:: swap(v[i], v[VB]);
           VB++;

        }
      

    }
    v.resize(VB);

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
