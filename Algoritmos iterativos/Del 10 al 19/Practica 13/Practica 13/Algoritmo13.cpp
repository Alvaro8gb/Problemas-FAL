//ALVARO GARCÍA BARRAGÁN
//A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


/*El coste del algoritmo es lineal O(n),siendo n el numero de puntos kilometricos ,ya que solo hay un bucle que da n vueltas las demas 
operacones son condicionales y asiganciones que son de coste constante*/


// función que resuelve el problema
int resolver(std::vector <int> const & v) {
    int moda = v[0],maxCont  = 0, cont = 1;

    for (int i = 1; i < v.size(); i++) {

       

        if (v[i]==v[i-1]) {
            cont++;

            if (cont > maxCont) {
                moda = v[i];
                maxCont = cont;
            }

        }
        else cont = 1;

       

    }

    return moda;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,moda;
    bool continuar = true;


    std::cin >> n;

    if (n==-1) continuar = false;
    else {
            

            std::vector<int> v(n);
            for (int i = 0; i < n; i++) 
                std::cin >> v[i];
              
            
           
            sort(v.begin(), v.end());


       

            moda = resolver(v);
            std::cout << moda << "\n";;


            
      }

    return continuar;
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
