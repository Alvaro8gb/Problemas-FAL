// Alvaro Garcia Barragan
// A31

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados
void resolver(std::vector<int> const& a, std::vector<lli>& v){

  lli suma = 0;

    for (int i =0 ; i < a.size(); i++) {
        suma += a[i];
        v[i] = suma;
     
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    int n = a2 - a1 +1;
    std::vector<int> a(n);
    std::vector<lli> v(n);

    for (int i = 0; i < a.size(); i++) {

        std::cin >> a[i];
    
    }
 

    resolver(a, v);
    

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        lli acumulado;
        std::cin >> f1 >> f2;

        

        if (f1 == a1) acumulado = v[f2 - f1];
        else acumulado = v[f2 - a1]-v[f1-a1-1];

            std::cout << acumulado << std::endl;

        // Escribir la respuesta

        // Aqui codigo del estudiante
    }
    std::cout << "---\n";

    return true;

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


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



