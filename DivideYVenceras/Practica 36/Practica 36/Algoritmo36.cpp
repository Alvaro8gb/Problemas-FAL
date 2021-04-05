// ÁLVARO GARCÍA BARRAGÁN 
//A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste de recursión

/*
* n=fin-ini= longitud de la fila
T(n) = c0 si n=2 
T(n) = c1 + 2T(n/2)

    dESPLEGANDO y utlizando las mates sale que T(n) pertene al orden de O(n)
*/
using tMatriz = std::vector <std::vector <int>>;

struct tSol {
    bool ok;
    int suma;
};
// función que resuelve el problema
tSol resolver(tMatriz const &matriz ,int fila,int ini,int fin ){
    if (ini + 1 == fin) {//un elemento 2^0=1
        return { true, matriz[fila][ini]};
    }
    else {//2 elementos o mas
        int m = (ini + fin) / 2;
        
        tSol iz = resolver(matriz, fila, ini, m);
        tSol dr = resolver(matriz, fila, m, fin);
  
        if (iz.suma < dr.suma && dr.ok && iz.ok) return { true,iz.suma + dr.suma };
        else return { false,0 };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int filas, columnas;
    std::cin >> filas >> columnas;

    if (!std::cin) return false;
    else {
       
        tMatriz matriz(filas, std::vector <int >(columnas));

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) std::cin >> matriz[i][j];
        }

        tSol degradado;

        int i = 0;
        do {
            degradado = resolver(matriz, i, 0, columnas);
           
            if(degradado.ok)i++;

        }while (degradado.ok && i < filas);

        if (degradado.ok) std::cout << "SI\n";
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


    while (resuelveCaso()) ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}