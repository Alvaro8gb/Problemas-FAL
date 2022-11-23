// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<long int> resolver(std::vector<long int> const & v,int primerAno) {

    std::vector <long int> sol;

    long int max=v[0];
    for (int i = 1; i < v.size(); i++) {

        if (v[i] > max) { 
          max = v[i];
          sol.push_back(primerAno + i);
        }
    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int primerAno, ultimoAno,longitud;

    std::cin >> primerAno;
    std::cin >> ultimoAno;

    longitud = ultimoAno - primerAno+1;

    std::vector<long int> v(longitud);

    for (long int& x : v) {
       
        std::cin >> x;
        
    }
    
    std::vector<long int> sol = resolver(v,primerAno);
    // escribir sol

    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout << ' ' << sol[i];
    }
    std::cout<<"\n";


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