// ALVARO GARCIA BARRAGAN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//coste lineal

// función que resuelve el problema
int resolver(std::vector <short int> const &v, int paginasLeibles) {
    int max, pos, sumaPuntuaciones ,maxSuma, posMax;
    max = sumaPuntuaciones = v[0];
    posMax = 0;
    for (int i = 1; i < paginasLeibles; i++) {
        sumaPuntuaciones += v[i];
        if (v[i] >= max) {
            max = v[i];
            posMax = i;
        }
        
    }
    pos = 0;
    maxSuma = sumaPuntuaciones;


    for (int i = paginasLeibles; i < v.size(); i++) {

        sumaPuntuaciones -= v[i - paginasLeibles];
        sumaPuntuaciones += v[i];
        
        if (v[i] > max) { // se cambia el maximo
            max = v[i];
            pos = i - paginasLeibles + 1;
            maxSuma = sumaPuntuaciones;
            posMax = i;
        }
        else if (v[i] == max) {
            posMax  = i;
            if (sumaPuntuaciones >= maxSuma) {

                maxSuma = sumaPuntuaciones;
                pos = i - paginasLeibles +1;
            }
        }
        else {//si el maximo esta en el intervalo y la suma es mayor
            if (posMax > i - paginasLeibles && sumaPuntuaciones >= maxSuma) {

                maxSuma = sumaPuntuaciones;
                pos = i - paginasLeibles + 1;
            }
        }
         
    }

    return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPaginas, paginasLeibles;
    std::cin >> numPaginas >> paginasLeibles;

    if (numPaginas == 0)  return false;

    std::vector <short int> puntuaciones(numPaginas);

    for (short int& x : puntuaciones) std::cin >> x;

    std::cout << resolver(puntuaciones,paginasLeibles) << std::endl;

    return true;
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
