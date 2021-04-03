// ALVARO GARCIA BARRAGAN
// A31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema

//Caoste

/*El coste del algoritmo es:
4 creaciones y asiganciones de coste constante.

Un bucle que da n vueltas siendo n el numero de gramos testeados.

y como todo lo que hay dentro del bucle que son condicionales asicnaciones e incrementos son de coste constante 
el algoritmo tiene coste lineal O(n) siendo n o los gramos que engordan o adelgagazan cada dia.

*/
void resolver(std::vector  <int> const & v, int& sumaMayor,int &primerDia,int &longMin) {

    int longAct,sumaAct,pos;
    sumaAct  = longAct = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] + sumaAct > 0) { // El elemento continua la racha
           
            if (longAct==0) pos = i;
            longAct++;
            sumaAct += v[i];
            if (sumaAct == sumaMayor) {
                if (longAct < longMin) {
                    longMin = longAct;
                    primerDia = pos;
                    sumaMayor = sumaAct;
                }
                else if (longAct == longMin) {

                    if (pos < primerDia) {
                        longMin = longAct;
                        primerDia = pos;
                        sumaMayor = sumaAct;
                    }
                }
            }
            else if (sumaAct > sumaMayor) {

                sumaMayor = sumaAct;
                longMin = longAct;
                primerDia = pos;
            }
          
        }
        else {
            longAct = 0; // Se rompe la racha
            sumaAct = 0;

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    bool continuar = true;
    int n,sumaMayor, primerDia, longMin;

    sumaMayor = primerDia = longMin = 0;

    std::cin >> n;

    if (!std::cin) {

        continuar = false;
    }
    else {

        std::vector<int> v(n);


        if (!v.empty()) {

            for (int i = 0; i < v.size(); i++)  std::cin >> v[i];

            
            
            resolver(v, sumaMayor, primerDia ,longMin);

           
             std::cout << sumaMayor << " " << primerDia << " " << longMin;



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
    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}