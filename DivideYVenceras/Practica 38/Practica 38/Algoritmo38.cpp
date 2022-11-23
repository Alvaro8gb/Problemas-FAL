// ÁLVARO GARCÍA BARRAGÁN
// A31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>




/* 
Coste del algoritmo

ECUACIONES DE RECURRENCIA

n= fin-ini

T(n) = co si n=2;
T(n)= 2T(n/2) + c1 si n > 2

el algoritmo pertenece al orden de O(n) 
*/
const std::string NP = "NP";
struct tSol {
    int partidos;
    int ronda;
    bool alguienPresentado;
};
// función que resuelve el problema
tSol resolver(std::vector <std::string> const &v,int ini,int fin,int ronda) {

    if (ini + 2 == fin) {//2 contrincantes

        if (v[ini] == NP && v[ini + 1] == NP) return { 0,1,false };
        else if (v[ini] == NP || v[ini + 1] == NP) return { 0,1,true};
        else return { 1,1,true};
       
    }
    else {//4 o masa contrincantes

        int m = (ini + fin) / 2;

        tSol partidosIzq = resolver(v, ini, m,ronda);
        tSol partidosDer = resolver(v, m, fin,ronda);

        int rondaActual = partidosDer.ronda + 1;
        if (rondaActual <= ronda) {
            if (partidosIzq.alguienPresentado && partidosDer.alguienPresentado) return { partidosDer.partidos + partidosIzq.partidos + 1,rondaActual ,true };
            else if(partidosIzq.alguienPresentado || partidosDer.alguienPresentado) return { partidosDer.partidos + partidosIzq.partidos , rondaActual, true };
            else return { partidosDer.partidos + partidosIzq.partidos, rondaActual ,false };
        }
        else return { partidosDer.partidos + partidosIzq.partidos, rondaActual ,false };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numJugadores, ronda;

    std::cin >> numJugadores >> ronda;

    if (!std::cin)
        return false;
    else {
       
        std::vector <std::string> v(numJugadores);
        for (std::string &x:v) std::cin >> x;

        tSol sol = resolver(v, 0, numJugadores, ronda);

        std::cout << sol.partidos << std::endl;

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