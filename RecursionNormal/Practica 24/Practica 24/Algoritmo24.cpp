// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

  // función que resuelve el problema
/* caso base : que el numero solo tenga un digito
caso recursivo: que el numero tenga mas digitos 
entonces se selleciona solo los impares para concatenarlos se pasan a string*/

using lli = long long int;
std::string  resolverNoFinal(lli num) {

    
    if (num / 10 ==0) { // == n<10
        if (num % 2 != 0) return std::to_string(num);
        else return "";
        }
    else {

        if ((num % 10) % 2 != 0) return resolverNoFinal(num / 10) + std::to_string(num%10);
        else return resolverNoFinal(num / 10);

    }

}
std::string  resolverFinal(lli num,std::string act) {


    if (num < 10) {
        if (num % 2 != 0) return std::to_string(num) + act;
        else return "" + act;
    }
    else {
    
        if ((num % 10) % 2 != 0) return resolverFinal(num / 10, std::to_string(num % 10) + act) ;
        else return resolverFinal(num / 10,act);

    }

}
/*
Ecuaciones:
    f(n) = n  si n<10 y n%2 != 0
    f(n)= 0  si n<10 y n%2 =0
    f(n) = f(n/10)+ n%10 si n > 10  n%2 != 0
    f(n) = f(n/10) si n > 10  n%2 = 0
*/
lli borrarDigitosParesNoFinal(lli num){

    if (num < 10) {
        if (num % 2 != 0) return num;
        else return 0;
    }
    else {
        lli x = num % 10;
        if (x % 2 != 0) return borrarDigitosParesNoFinal(num / 10)*10 + x;
        else return borrarDigitosParesNoFinal(num / 10);
    }


}

lli borrarDigitosParesFinal(lli num,lli act,lli pot) {

    if (num < 10) {
        if (num % 2 != 0) return num*pot+ act;
        else return 0+act;
    }
    else {
        lli x = num % 10;
        if (x % 2 != 0) return borrarDigitosParesFinal(num / 10, act + x*pot,pot*10);
        else return borrarDigitosParesFinal(num / 10,act,pot);
    }


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
       std::cout << resolverFinal(num, "") <<" " << resolverNoFinal(num) << std::endl;
        
        std::cout << borrarDigitosParesNoFinal(num) << " " << borrarDigitosParesFinal(num,0,1)<< std::endl;

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