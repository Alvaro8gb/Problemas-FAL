// Álvaro García Barragán
//A31

#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

lli resolverNoFinal(lli num1, lli num2) {

    if (num1 < 10 && num2 < 10)  return (num1 + num2) % 10;
    else return resolverNoFinal(num1 / 10, num2 / 10) * 10 + (num1 % 10 + num2 % 10) % 10;

}
lli resolverFinal(lli num1, lli num2, lli act, lli pot) {

    if (num1 < 10 && num2 < 10)  return ((num1 + num2) % 10) * pot + act;
    else return resolverFinal(num1 / 10, num2 / 10, act + ((num1 % 10 + num2 % 10) % 10) * pot, pot * 10);
}
void resuelveCaso() {
    lli num1, num2;
    std::cin >> num1 >> num2;

    std::cout << resolverNoFinal(num1, num2) << " " << resolverFinal(num1, num2, 0, 1) << std::endl;
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