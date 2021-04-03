
// Álvaro García Barragán
//A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/**
#include <algorithm>
#include <string>
#include <utility>
*/

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n;
    std::cin >> n;

    short int contador = 0;
    int puntuacionMax = n;


    while (n != 0) {

        if (puntuacionMax == n)contador++;
        else if(n > puntuacionMax) {
            puntuacionMax = n;
            contador = 1;
        }
      

        std::cin >> n;
    }

    // Escribir el resultado
    std::cout << puntuacionMax << " " << contador<<std::endl;
   
}
int main(){
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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