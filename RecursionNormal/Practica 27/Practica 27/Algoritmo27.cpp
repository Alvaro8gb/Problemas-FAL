// ALVARO GARCIA BARRAGAN
//A31


#include <iostream>
#include <iomanip>
#include <fstream>
using lli = long long int;

struct tInteresante {
    lli sumaIzq;
    bool intersting;
};

// función que resuelve el problema
tInteresante resolver(lli num, int sumaDer,bool intersting) {

    if (num < 10) {

        if (((sumaDer - num) % num) == 0) return { num,true }; //si divide ala suma de todos los digitos de su derecha
        else return { 0,false };

    }
    else {
      
        short int digito = num % 10;
        tInteresante actual = resolver(num / 10, sumaDer + digito, intersting);
        if (actual.intersting) {
            if ((sumaDer - digito) % digito == 0 && (actual.sumaIzq - digito) % digito == 0) {// si el digito divide a ambas mitades

                actual.sumaIzq += digito;
                return { actual.sumaIzq,true };
            }
            else return { 0,false };
        }return actual;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    lli num;
    std::cin >> num;

    if (num == 0) {// el cero no es interesante)
        std::cout << "NO\n";
    }
    else {
        tInteresante sol = resolver(num, 0, false);

        if (sol.intersting) std::cout << "SI\n";
        else  std::cout << "NO\n";

    }
    
       
 
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}