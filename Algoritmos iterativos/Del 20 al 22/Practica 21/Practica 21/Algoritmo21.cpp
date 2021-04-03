// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//coste
/*  
Un bucler for que da n-1 vueltas ,en el cual dentro de el se realizan operaciones de coste constante 
por tanto el orden de complejidad pertenece a O(n),es decir lineal con respecto al
n´umero de marcas de cada participante.

*/

struct tSol {
    int nMaxSinMejora;
    int pos;
};
// función que resuelve el problema
tSol resolver(std::vector <int> const &v) {

    tSol sol = { 0,v.size() };
    int maxMedida = v[0], cont=0;

    for (int i = 1; i < v.size(); i++) {

        if ( maxMedida >=v[i]) {
            cont++;
            if (cont >= sol.nMaxSinMejora) {
                sol.nMaxSinMejora = cont;
                sol.pos = i-cont+1;
            }
        }
        else {
            maxMedida = v[i];
            cont = 0;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n==0) return false;
    else {
        std::vector < int> v(n);

        for (int& m : v) std::cin >> m;

        tSol sol = resolver(v);

        std::cout << sol.nMaxSinMejora << " " << sol.pos << "\n";

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
