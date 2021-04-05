// ÁLVARO GARCÍA BARRAGÁN 
//A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//Coste de recursión

/*
* n= fin-ini= v.size()
*
* Ecuaciones de Recurrencia:

T(n) = c0 ,si n==1
T(n) = T(n/2) + c1 , si n >1

Por tanto el algoritmo tiene coste logaritmico O(longn)
*/

/*
En este problema diremos que un vector esta parcialmente ordenado, si el valor
m´aximo de su mitad derecha es mayor o igual que todos los valores de la mitad izquierda y el valor
m´ınimo de su mitad izquierda es menor o igual que todos los valores de su mitad derecha. Adem´as tanto
la mitad izquierda como la derecha cumplen que est´an parcialmente ordenados.
*/
struct tSol {
    bool parcialmenteOrdenado;
    int max,min;
};

// función que resuelve el problema
tSol resolver(std::vector <int>const& v, int ini, int fin) {
    if (ini + 1 == fin) {//un elemento
        return { true,v[ini],v[ini] };
    }
    else {//2 elementos o mas
        int m = (ini + fin) / 2;

        tSol iz = resolver(v, ini, m);
        tSol dr = resolver(v, m, fin);

        if (dr.parcialmenteOrdenado && iz.parcialmenteOrdenado && dr.max >= iz.min && iz.min<=dr.min) return { true,dr.max,iz.min };
        else return { false,0,0 };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    std::cin >> n;

    if (n == 0) return false;
    else {
        std::vector <int> v;

        do{
            v.push_back(n);
            std::cin >> n;
         }while (n != 0);


        tSol sol = resolver(v,0,v.size());
        if (sol.parcialmenteOrdenado) std::cout << "SI\n";
        else std::cout << "NO\n";

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