// ALVARO GARCIA BARRAGAN
//A31


#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Aqui especificación de la función que resuelve el problema. 
/*
* {v.size() > 0}
* resolver (vector <int> v , int medidaMax, int longIntervalo) dev int numMaxNinos
* {numMaxNinos == max z
*/
// Aqui la justificación del coste de la función que resuelve el problem
/*
* n = numero de elementos del vector de entrada( numMedidas) 
* mediaMax en el caso peor es 150
* 1<=longIntervalo <=150
* coste = n +  medidaMax - longIntervalo
* por tanto pertenece al orden de O(n) , coste lineal.
*/


// Aqui la función implementada por el alumno
int resolver(std::vector <int> const & v, int medidaMax, int longIntervalo) {

    std::vector <int> numReps(medidaMax, 0);  //1<=v[i] <=150

    for (int i = 0; i < v.size(); i++) numReps[v[i] - 1]++; // Calculo del vector auxiliar de repeticiones de medidas

    int numNinos = 0, numMaxNinos;

    for (int i = 0; i < longIntervalo; i++)  numNinos += numReps[i]; // Se inicializa el intervalo
    
    numMaxNinos = numNinos;

    for (int i = longIntervalo; i < medidaMax; i++) { //Se va probando con todos los posibles intervalos

        numNinos -= numReps[i - longIntervalo]; 
        numNinos += numReps[i];
        if (numNinos > numMaxNinos) numMaxNinos = numNinos;

    }
    return numMaxNinos;
}

bool resuelveCaso() {
    int numMedidas, medidaMax, longIntervalo;
    std::cin >> numMedidas >> medidaMax >> longIntervalo;
    if (numMedidas == -1) return false;
    std::vector<int> v(numMedidas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion que resuelve el problema

    std::cout << resolver(v, medidaMax, longIntervalo) << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

