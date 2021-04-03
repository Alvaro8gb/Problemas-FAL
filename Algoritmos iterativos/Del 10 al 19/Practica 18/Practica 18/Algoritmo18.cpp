
#include <iostream>
#include <fstream>
#include <vector>


//*******************************
// Aqui explicacion de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// El algoritmo tiene dos bucles , en el primero tine coste k siendo k la longitud del tramo
// y el segundo tiene coste n-k siendo n el numero de kilometros que estamos analizando.
//Como las instrucciones condicionales,asiganciones e incrementos son de coste constante el coste global es la suma de los costes de ambos 
//bucles por tanto es igual a n-k+k=n .
//En conclusión el algoritmo tienen  coste lineal O(N) siendo N el numero de kilometros.
// 
//*******************************


// Aqui la función implementada por el alumno para resolver el problema
int resolver(std::vector <int> const& v,int const & k,int& ini, int& fin) {
    int actDesnivel=0, maxDesnivel;

    for (int i = 0; i < k; i++) {

        actDesnivel += v[i];
    }

        maxDesnivel = actDesnivel;
        ini = fin = 0;
    
    for (int i = k; i < v.size(); i++) {

        
        actDesnivel = actDesnivel + v[i]- v[i - k];

        if (actDesnivel > maxDesnivel) {

            maxDesnivel = actDesnivel;
            ini  = fin = i-k+1;
        }
        else if (actDesnivel == maxDesnivel) {

            fin = i - k + 1;
        }


    }

    return maxDesnivel;
}


// Resuelve cada caso de la entrada
bool resuelveCaso() {
    // Lectura de los datos
    int numKilometros, longitudTramo,maxDesnivel, posIni, posFin;
    std::cin >> numKilometros >> longitudTramo;
    if (numKilometros == 0 && longitudTramo == 0) return false;
    std::vector<int> v(numKilometros); // nombre y altura
    for (int& n : v) {
        std::cin >> n;
    }
   
    // LLamada a la funcion que resuelve el problema
    maxDesnivel = resolver(v, longitudTramo,posIni, posFin);


    // Escribir el resultado

    std::cout << maxDesnivel << " " << posIni << " " << posFin << std::endl;

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}