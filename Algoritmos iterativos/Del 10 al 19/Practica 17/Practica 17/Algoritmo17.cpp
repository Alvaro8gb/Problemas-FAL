//*****************
// IMPORTANTE
//
// ALVARO GARCIA BARRAGAN
//A31
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


//*******************************
//
//
//
//
//El coste del algoritmo es lineal.
// 
// 
// 
//*******************************

struct tEdificio {
    std::string nombre;
    int altura;
    int piso;
};


// Aqui la función implementada por el alumno
std::vector <std::string> resuelve(std::vector <tEdificio>const& edificios, int& numEdificos) {
    std::vector<std::string> edificiosVip;

    int alturaActual, alturaMax =-1;
    numEdificos = 0;

    for (int i = edificios.size()-1; i >= 0; i--) {
        
        alturaActual = edificios[i].piso;
        if (edificios[i].piso > alturaMax) {

            edificiosVip.push_back(edificios[i].nombre);
            alturaMax = edificios[i].altura;
            numEdificos++;
        }
        else {
            if (edificios[i].altura > alturaMax)alturaMax = edificios[i].altura;
        }


    }


    return edificiosVip;
}


bool resuelveCaso() {
    int numEdificios,numEdificiosVip;
    std::cin >> numEdificios;
    std::vector <tEdificio> edificios(numEdificios);
    if (numEdificios == 0) return false;

    // Lectura del resto de los datos
    for (int i = 0; i < numEdificios; i++) {
        std::cin >> edificios[i].nombre >> edificios[i].altura >> edificios[i].piso ;
    }
   
    std::vector<std::string> edificiosVip;

    edificiosVip = resuelve(edificios, numEdificiosVip);

    if (edificiosVip.empty()) std::cout << "Ninguno\n";
    else {
        std::cout << numEdificiosVip<<"\n";

        for (int i = 0; i < numEdificiosVip; i++) {

           std::cout << edificiosVip[i]<<" ";
        }
        std::cout << std::endl;
    }




    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
