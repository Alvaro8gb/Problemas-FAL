// Álvaro García  
//A31
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado



// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
    // Aqui codigo del estudiante

    std::vector <int> contador(maximoValores);

    int max = 0;

    for (int i = 0; i < v.size(); i++) {
        contador[v[i] - 1]++;

        if (contador[v[i] - 1] > max) max = contador[v[i] - 1];
    }

    std::vector <int> maxReps;

    for (int i = 0; i < maximoValores; i++) {

        if (contador[i] == max) maxReps.push_back( i + 1);

    }
        

    std::sort(maxReps.begin(), maxReps.end(), std::greater <int >());

   

    return maxReps;

}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v)
        std::cin >> i;


    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces
    int maxReps = 0;
    std::vector <int> reps = resolver(v, valorMax);


    for (int i = 0; i < reps.size();i++) 
        if(reps[i]!=0)std::cout << reps[i] << " ";
    // Escribir los valores del vector que ha calculado resolver



    std::cout << "\n";
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}