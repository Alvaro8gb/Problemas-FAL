// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//coste 
/*
T(n) = co si n =0
T(n) = n + T(n/2) + c1 si n >1


Por tanto pertenece al orden O(nlogn)
*/

// función que resuelve el problema
int resolver(std::vector <int>const &  v,int limiteInferior, int limiteSuperior, int maxNumViajes) {

    if (limiteInferior == limiteSuperior) return limiteInferior;
    else {

        int m = (limiteInferior + limiteSuperior) / 2;
        int numeroViajes = 0,pesoCamion = 0;

        for (int i = 0; i < v.size(); i++) {

            pesoCamion += v[i];

            if (pesoCamion >= m) {

                numeroViajes++;

                if (pesoCamion == m) pesoCamion = 0;
                else pesoCamion = v[i]; //un peso solo nunca es mayor o igual que m            
            }               
        }

        if (pesoCamion > 0) numeroViajes ++;

        if (numeroViajes <= maxNumViajes) return resolver(v, limiteInferior, m, maxNumViajes);
        else if (numeroViajes > maxNumViajes)  return resolver(v,m+1, limiteSuperior, maxNumViajes);

        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, maxDias;

    std::cin >> n >> maxDias;
    if (n == 0)return false;
    else {

      std::vector <int> v(n);
      int sumaPesos = 0, maxPeso = 0;

      for (int i = 0; i < n; i++) {
          std::cin >> v[i];
          sumaPesos += v[i];

          if (v[i] > maxPeso) maxPeso = v[i];
      }

      std::cout << resolver(v, maxPeso, sumaPesos, maxDias) << std::endl;

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
