// ALVARO GARCIA BARRAGAN
//A31


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

struct tSolucion {
    lli n1, n2;
};

//Calcula el termino introducido de la sucesióm de Fibonacci
//Recursion multipl MUY COMPLEJA 0(n^2)
lli fib(int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}
lli resolverFinal(int n, lli n1, lli n2){
    if (n == 0) return n1;
    else if (n == 1) return n2;
    else return resolverFinal(n - 1, n2 , n1 + n2);
}
tSolucion resolverNoFinal(int n){
    
    if (n == 0) return { 0,0 };
    else if (n == 1) return { 0,1 };
    else {
        tSolucion sol;
        sol = resolverNoFinal(n - 1);
        return {sol.n2  ,sol.n1 + sol.n2};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    std::cin >> num;
    if (!std::cin)  return false;
    else {
        tSolucion sol = resolverNoFinal(num);
        std::cout << resolverFinal(num, 0, 1) << " " << sol.n2 << std::endl;
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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}