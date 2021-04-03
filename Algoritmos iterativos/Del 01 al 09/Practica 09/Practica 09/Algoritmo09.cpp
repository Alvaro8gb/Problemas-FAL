//Alvaro García Barrgán
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

/*Las instrucciones de comparaciones , incrementos y asignacion son   instrucciones de coste
constante,no  interesan analizarlas.Por tanto solo interesa analizar los bucles.

El primer bucle tiene coste lineal O(longTela) ,siendo longTela el tamaño de intervalo.
El bucle principal tiene coste lineal O(valla.size()-longTela).El caso peor seria cuando el intervalo tiene tamaño
1 entonces el coste seria de O(valla.size()).

Por tanto el algoritmo tiene coste lineal O(N) ,siendo N el tamaño del vector de entrada.
*/
int resolver(std::vector <int> const &valla,int longTela) {
   

    int sumaActual=0,sumaMinima=longTela,posPrimera=-1;


   
    for (int i = 0; i < longTela; ++i) { 
       
        sumaActual += valla[i];
    }
    
      
    if (sumaActual != longTela) {
        posPrimera = 0;
        sumaMinima = sumaActual;

    }
        
  
    // Bucle principal
    for (int j = longTela; j < valla.size(); ++j) {

        sumaActual -= valla[j - longTela];
        sumaActual += valla[j];
        if (sumaActual <= sumaMinima && sumaActual != longTela) {
            sumaMinima = sumaActual;
            posPrimera = j - longTela+1;
        }
        

    }

    return posPrimera;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int mValla, longTela,pos;
    bool continuar = true;
    std::cin >> mValla;

    if (mValla == 0) continuar=false;
    else {
        std::cin >> longTela;

        std::vector<int> vallas(mValla);
        for (int i = 0; i < mValla; i++)  std::cin >> vallas[i];
       
        pos = resolver(vallas, longTela);
        if ( pos== -1) std::cout << "No hace falta ";
        else std::cout << pos;
        

        std::cout << "\n";
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
