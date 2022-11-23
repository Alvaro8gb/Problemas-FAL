// Álvaro García Barragán
//A31

#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

lli resolverNoFinal(lli num , short int digitoMax) {

    if (num < 10) {
        if (num >= digitoMax) return num;
        else return 0;
    }
    else {
        if (digitoMax <= num % 10) return resolverNoFinal(num / 10, num % 10) * 10 + num % 10;
        else return resolverNoFinal(num / 10, digitoMax);
    }

}
lli resolverFinal(lli num, short int digitoMax, lli act, lli pot) {
    if (num < 10) {
        if (num >= digitoMax) return num * pot + act;
        else return act;
    }
    else {
        if (digitoMax <= num % 10) return resolverFinal(num / 10, num % 10,act + (num % 10)*pot,pot*10);
        else return resolverFinal(num / 10, digitoMax,act,pot);
    }
}
void resuelveCaso() {
    lli num;
    std::cin >> num ;

    std::cout << resolverNoFinal(num,0) << " "  << resolverFinal(num,0,0,1) << std::endl;
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