// Álvaro García Barragán
//A31


#include <iostream>
#include <iomanip>
#include <fstream>


using lli = long long int;

lli complementarioNoFinal(lli num) {

    if (num < 10)  return 9 - num;
    else return complementarioNoFinal(num/10)*10  + (9 - (num % 10));

}
lli complementarioFinal(lli num,lli act,lli pot) {

    if (num < 10)  return (9 - num)*pot + act ;
    else return complementarioFinal(num / 10,(9 - (num % 10))*pot + act,pot*10) ;

}

lli invertirComplementarioFinal(lli num, lli actual) {
   
    if (num < 10) return (9 - num)  + actual*10 ;
    else return invertirComplementarioFinal(num / 10, (9 - num % 10)  + actual*10);

}
struct tSol {
    lli act;
    lli pot;
};
tSol invertirComplementarioNoFinal(lli num) {

    if (num < 10) return { 9 - num,10 };
    else {
       
        
        tSol s = invertirComplementarioNoFinal(num / 10);
           return {s.act+ (9 - num % 10) * s.pot,s.pot * 10 };

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    std::cin >> num;

    tSol s = invertirComplementarioNoFinal(num);
    std::cout << complementarioNoFinal(num) << " " << s.act << std::endl;
    std::cout << complementarioFinal(num,0,1) <<" "<< invertirComplementarioFinal(num, 0) << std::endl;
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