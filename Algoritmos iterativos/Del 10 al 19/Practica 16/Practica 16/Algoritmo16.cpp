// ALVARO GARCIA BARRAGAN
// A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//explicacion
/*El algoritmo busca en el primer bucle un numero par en el vector , si lo hay lo coloca en la primera posicion , sino devuelve un vector vacio.
Despues en el segundo bucle va comparando el ultimo numero que ya esta bien colocado con el primero que no se sabe, si tiene disitinta paridad 
coloca el la ultima posicion de la parte bien colocado y sino sigue recorriendo el vector hasta encontrar un elemento que tenga distinta paridad o que se acabe el vector.
Finalmente como el numero de elementos pares e impares tiene  que ser el mismo se comprueba que el contadorBueno sea par sino se le resta uno.
*/
//coste
/*
* Tiene dos asiganciones al principio de coste constante 
* El primer bucle en el peor caso da n vueltas (siendo n el tamaño de numeros que se quieren probar),si el primer bucle da n vueltas en el condicional 
y en el segundo bucle no entra.
Por tanto como las condicionales son de coste constante y al tener ambos bucles la misma variable ligada que los recorre con la misma condicion
el coste del algoritmo es O(n).

*/

// función que resuelve el problema
void resolver(std:: vector <int> &v) {

   //tiene q tener mismo numero de pares que impares
    int i = 0, contadorBueno = 0;
    while (i < v.size() && v[i] % 2 != 0) {

        i++;
    }

    if (i < v.size()) {
        std::swap(v[0], v[i]);
        contadorBueno = 1;
    }

    while (i < v.size()) {
        if (v[i] % 2 != v[contadorBueno - 1] % 2) {

            std::swap(v[i], v[contadorBueno]);
            contadorBueno++;
        }
        else i++;

    }
    
    if(contadorBueno % 2 !=0) contadorBueno -=1;

    v.resize(contadorBueno);
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    bool continuar = true;
    int n;

    std::cin >> n;
   
    if (!std::cin) {

        continuar = false;
    }
    else {

            std::vector<int> v(n);


            if (!v.empty()) {

                for (int i = 0; i < v.size(); i++)  std::cin >> v[i];

                resolver(v);


                for (int i = 0; i < v.size(); i++)
                    std::cout << v[i] << " ";



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
       while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}