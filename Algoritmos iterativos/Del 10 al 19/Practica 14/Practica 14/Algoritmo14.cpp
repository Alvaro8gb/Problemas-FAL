//Alvaro García Barrgán
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

/*Las instrucciones de comparaciones , incrementos y asignacion son   instrucciones de coste
constante,no  interesan analizarlas.Por tanto solo interesa analizar los bucles.

El bucle tiene coste lineal N-2 ,siendo n los valores tomados por Heidi,las demas operaciones tienen coste constante.

Por tanto el algoritmo tiene coste lineal O(N) ,siendo N el tamaño del vector de entrada.
*/
std::vector <int> resolver(std::vector <int> const& v, const int &min,int &longMax,int &nLlanos) {


    int cont , pos, elementoMax;

    elementoMax =v[v.size()-1];
    nLlanos = 0;
    longMax = 0;
    cont = 1;

    std::vector <int> posiciones;

    for (int i =( v.size()-2); i > 0; i--) {

       
        if (elementoMax < v[i]) elementoMax = v[i];
        
        if (v[i] == v[i + 1] && v[i] >= elementoMax ) {


            cont++;
            if (i == 1 && v[i] == v[i - 1])cont++;

            if (cont >= min) {


                if (v[i]!=v[i-1] ) {

                    
                    pos = i + cont - 1;
                    posiciones.push_back(pos);
                    nLlanos++;

                }
                else {

                    if (i == 1) {

                        
                        pos = i + cont - 2;
                        posiciones.push_back(pos);
                        nLlanos++;
                        
                    }


                }
              

                if (cont > longMax) longMax = cont;
            }

        }
        else {

            cont = 1;
        }     
       
    }

    return posiciones;
  
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int datos=0, min,longMax,nLlanos;
    bool continuar = true;
 

    
      
    if (!std::cin) {

        continuar = false;
    }
    else{



        std::cin >> datos;
        std::cin >> min;

        std::vector<int> v(datos);
        for (int i = 0; i < v.size(); i++)  std::cin >> v[i];

       
        if (!v.empty()) {

            std::vector <int> posiciones;
            posiciones = resolver(v, min, longMax, nLlanos);

            std::cout << longMax << " " << nLlanos << " ";

            if (!posiciones.empty()) {
                for (int i = 0; i < nLlanos; i++)
                    std::cout << posiciones[i] << " ";
            }


            std::cout << "\n";
        }
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