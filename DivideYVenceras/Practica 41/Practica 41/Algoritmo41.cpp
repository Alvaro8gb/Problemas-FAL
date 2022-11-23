//Álvaro García Barragán
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/* Coste 

Ecuaciones de recurrencia:

T(n) = co si n == 1
T(n) = c1 + T(n/2)  si n> 1


Por tanto el algoritmo pertenece al orden O(logn)

*/
struct tSol {
    bool cortan;
    int x, y;
};

// función que resuelve el problema
tSol resolver(std::vector <int> const &v1 , std::vector <int> const& v2,int ini,int fin) {

    if (ini + 1 == fin) {//Dos elementos
        if (v1[ini] < v2[ini]) return { false,ini, fin};
        else if (v1[ini] > v2[ini]) return { false,-1,0 };
        else return  { true, ini ,ini};
    }
    else {
        int m = (ini + fin) / 2;

        if (v1[m] > v2[m])return resolver(v1, v2, ini, m);
        else if (v1[m] < v2[m])  return resolver(v1, v2, m, fin);
        else return { true,m,m };
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
    
        std::vector <int> v1(n);
        std::vector <int> v2(n);

        for (int i = 0; i < n; i++) std::cin >>v1[i];
        for (int i = 0; i < n; i++) std::cin >> v2[i];


        tSol sol = resolver(v1, v2, 0, n);

        if (sol.cortan) std::cout << "SI "<< sol.x << std::endl;
        else std::cout << "NO "<< sol.x << " " << sol.y << std::endl;
       

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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
