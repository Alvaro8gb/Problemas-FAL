//Álvaro García
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector <int> const& v, int& casosSeleccionados) {
    int suma=0 , min, rep = 1;
   
    min = v[0];
    
    for (int i = 1; i < v.size(); i++) {
        
            if (min > v[i]) {
                suma += min * rep;
                min = v[i];
                casosSeleccionados += rep;
                rep = 1;

            }
            else if (min < v[i]) {

                casosSeleccionados++;
                suma += v[i];

            }
            else {//min=v[i]
                rep++;
            }

    }
   
    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int longitud, casosSeleccionados = 0;

    std::cin >> longitud;
    std::vector <int>v(longitud);


    for (int i = 0; i < longitud; i++) std::cin >> v[i];

    // escribir sol
    std::cout << resolver(v, casosSeleccionados) << " ";
    std::cout<< casosSeleccionados << std::endl;

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