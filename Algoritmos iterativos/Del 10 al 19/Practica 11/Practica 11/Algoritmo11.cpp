//Álvaro García Barragán
// A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

/* Recorre el vector buscando el segmento maximo que cumple que todos sus elementos son mayores o iguales que la alturaNave
cuando lo encuentra calcula la pos donde empieza y la pos donde acaba ese segmento.En el caso de que todos los elementos fueran mayores o
iguales que la altura de la nave da la pos inicial y final del vector.*/

// Coste del algoritmo utilizado

/* Dos creaciones de variables y cuatro asignaciones de valores ,de coste constante antes del bucle.

El bucle tiene coste lineal O(v.size) ya que los condicilonales,incrementos y asignaciones que se realizan en el interior 
son de coste constante.
Por tanto el coste del algoritmo es de O(n) siendo n el tamaño del vector de entrada*/



// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin){

    int segActual=0,segMax=0;
    posFin = posIni = 0;
    for (int i = 0; i < v.size(); i++) {

        if (v[i] > alturaNave) {
            

            segActual++;

            if (segActual > segMax) {
                segMax = segActual;
                posFin = i;
            }

        }
        else segActual = 0;
        
       
    }

    /*if (segActual - 1 == (v.size() - 1)) {
        posFin = v.size() - 1;
        segMax = segActual;
    }*/

    if(posFin !=0)posIni =  posFin - segMax+1;


}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
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
 
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
