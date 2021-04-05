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

struct tSol {
    bool caucasico;
    int numElementosPares;
};

// función que resuelve el problema
tSol resolver(std::vector <int>const & v, int ini, int fin) {
    if (ini + 1 == fin) {//un elemento
        if (v[ini] % 2 == 0)return{ true,1 };
        else return{ true,0 };
    }
    else {//2 elementos o mas
        int m = (ini + fin) / 2;

        tSol iz = resolver(v, ini, m);
        tSol dr = resolver(v, m, fin);


        int elementosPares = abs(iz.numElementosPares-dr.numElementosPares);
 
        if (iz.caucasico && dr.caucasico && elementosPares <= 2) return { true,iz.numElementosPares + dr.numElementosPares };
        else return { false,0 };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    std::cin >> n;

    if (n==0) return false;
    else {
        std::vector <int> v(n);

        for (int i = 0; i < n; i++)   std::cin >> v[i];

        tSol sol = resolver(v, 0, n);
        if (sol.caucasico) std::cout << "SI\n";
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