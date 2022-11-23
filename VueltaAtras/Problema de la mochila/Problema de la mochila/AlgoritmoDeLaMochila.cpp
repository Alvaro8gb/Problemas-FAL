/*
Algoritmo de la mochila o de Alibaba :
Alibaba se quiere llevar de la cueva el maximo botin pero su mochila solo tiene capacidad para un peso P ,que objetos se  lleva para conseguirlo .

Metodos de resolucion :

-Algoritmos géneticos
-BackTraking : coste 2^n (sin estimar)
-Algoritmos voraces : coste nlogn (no siempre tiene solución)
-Programación dinamica: n^2 (no siempre tiene solucion)
*/

//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

// sol vector booleano (binario) que para un objecto i , si v[i] = true si lo compra  , cc v[i] = false (no lo compra).

struct tObjeto {
	int coste, superficie;
};
struct tDatos {
	int numObjetos, presupuesto;
	std::vector <tObjeto> objetosInfo;
};
struct tSol {
	std::vector <bool> sol;
	int sumaCoste,sumaSuperficie;
};
// Escribe una solucion
void escribirSolucion(std::vector <bool > const& v) {
	for (int i = 0; i < v.size(); i++) if (v[i]) std::cout << i << " ";
	std::cout << '\n';
}
// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k, tSol& s, tSol &mejorSol) {

	s.sol[k] = true;
	s.sumaCoste += d.objetosInfo[k].coste;
	s.sumaSuperficie += d.objetosInfo[k].superficie;

	if (s.sumaCoste <= d.presupuesto) { //Es valida
		if (k == d.numObjetos - 1) { //Es solución
			if (mejorSol.sumaSuperficie < s.sumaSuperficie) mejorSol =  s;
		}
		else { // Sigue completando la solucion 
			resolver(d, k + 1, s, mejorSol);
		}
	}

	s.sol[k] = false;
	s.sumaCoste -= d.objetosInfo[k].coste;
	s.sumaSuperficie -= d.objetosInfo[k].superficie;

	if (k == d.numObjetos - 1) { //Es solución
		if (mejorSol.sumaSuperficie < s.sumaSuperficie) mejorSol = s;	
	}
	else { // Sigue completando la solucion 
		resolver(d, k + 1, s, mejorSol);
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;
	std::cin >> d.numObjetos >> d.presupuesto;

	if (!std::cin) return false;
	
	d.objetosInfo.resize(d.numObjetos);
	for (tObjeto& x : d.objetosInfo) std::cin >> x.coste >> x.superficie;

	tSol s;
	s.sol.resize(d.numObjetos);
	s.sumaCoste = s.sumaSuperficie =  0;

	tSol mejorSol;//para guardar la solucion

	mejorSol.sumaSuperficie = 0; //inicializamos a un valor absurdo

	resolver(d, 0, s, mejorSol);

	//escribirSolucion(mejorSol.sol);
	std::cout << mejorSol.sumaSuperficie << "\n"; //maximaSuperficie

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif

	while (resuelveCaso()) {} // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
# endif
	return 0;
}
