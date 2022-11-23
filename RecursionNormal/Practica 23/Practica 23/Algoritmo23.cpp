// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>


 /*
 algoritmoIterativo
    while (num / 10 > 0)
    {
        num = num / 10;
        contador++;
    }
    */
// función que resuelve el problema
using lli = long long int;
lli resolverNoFinal(lli num ) {
   
    if (num / 10 == 0) return  1 ;
    else return resolverNoFinal(num/10) + 1;

}
lli resolverFinal(lli num, lli cont) {

    if (num < 10 ) return  cont+1;
    else return resolverFinal(num / 10,cont + 1);

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    std::cin >> num;
    if (!std::cin) return false;
    else {
        // escribir sol
        std::cout << resolverFinal(num, 0) <<" "<< resolverNoFinal(num)<< std::endl;


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