
// ÁLVARO GARCÍA BARRAGÁN
// A31
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//Coste O(logn) 

bool resolver(std::vector<int> const& v,int x, int ini, int fin) {


    if (ini == fin) return false; //ningun elemento
    else if (ini + 1 == fin) { //un elemento
        if (x == v[ini]) return true;
        else return false;
    }
    else {//2 elementos o mas
        int m = (ini + fin) / 2;
        
        //Hipotesis : siempre hay una mitad ascendente

       // dos tipos de mitades ascendente o ascendente-descendente
      //ver dibujo
      
        if (v[m] == x)return true;
        else if (v[m] > v[ini]) {   //mitad ascendente
         
            if (v[ini] <= x && v[m] >= x) return resolver(v, x, ini, m);
            else return resolver(v, x, m+1, fin);
        }
        else {

            if (v[fin - 1] >= x && v[m] <= x) return resolver(v, x, m, fin);
            else return resolver(v, x, ini, m);      
        }
    }
}
bool resuelveCaso() {
    int n,x;

    std::cin >> n >> x;

    if (n==-1) return false;
    else {

        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) std::cin >> v[i];
     
        if (resolver(v, x, 0, n)) std::cout << "SI\n";
        else std::cout << "NO\n";

        return true;
    }
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}