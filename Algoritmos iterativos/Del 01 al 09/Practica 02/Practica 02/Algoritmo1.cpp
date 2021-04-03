//Álvaro García Barragán
// A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool resolver(std::vector <int> const  &v, int p) {
    bool dividido = true;
    int max, min;
  
    if(v.size() - 1 != p){
       
        max = v[0];
        for (int i = 1; i <= p; i++) {

            if (v[i] > max)max = v[i];

        }
        min = v[p + 1];
        for (int j = p + 1; j < v.size() ; j++) {

            if (v[j] < min) min = v[j];
        }

        if (max >= min)dividido = false;
    }
    return dividido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bool solucion;
    int longitud, p;

    std::cin >> longitud;
    std::cin >> p;
    std::vector < int > v(longitud);

    for (int i = 0; i < longitud; i++) //Lectura del vector
        std::cin >> v[i];

    solucion = resolver(v, p);

    if (solucion) std::cout << "SI\n";
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

