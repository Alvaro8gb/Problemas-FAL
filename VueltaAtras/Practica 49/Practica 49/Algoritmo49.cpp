
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion

struct tDatos {
	int longitud, numColores, consumoMax;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";

	std::cout << '\n';
}
//esValida : tiene coste constante.
bool esValida(std::vector <int >const& sol, int k, int i, std::vector <int >const& usoDeColorPorLinea) {

	if (k > 1 && i == sol[k - 1] && i == sol[ k - 2]) return false; //No haya mas de dos luces seguidas del mismo color

	//La suma de las luces de un color no supere en mas de una unidad la suma de las luces de todos los demas colores
	if (usoDeColorPorLinea[i] > ( usoDeColorPorLinea[usoDeColorPorLinea.size() -1]- usoDeColorPorLinea[i])) return false;

	
	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
int variaciones(tDatos const& d, int k, std::vector <int >const& consumoPorBombilla,std::vector <int >& usoDeColorPorLinea, int &sumaEnergetica,std::vector <int >& sol) {
	int numSol = 0;

	for (int i = 0; i < d.numColores; i++) {

		sol[k] = i;
		sumaEnergetica += consumoPorBombilla[i];

		if (esValida(sol, k, i, usoDeColorPorLinea)) {

			usoDeColorPorLinea[i]++;
			usoDeColorPorLinea[d.numColores]++;

			if (k == d.longitud - 1) {
				
				if (sumaEnergetica <= d.consumoMax) { // No se puede superar el consumo maximo 
					//escribirSolucion(sol);
					numSol++;
				}
				
			}
			else { // Sigue completando la solucion
				numSol += variaciones(d, k + 1, consumoPorBombilla, usoDeColorPorLinea, sumaEnergetica,sol);
			}

			usoDeColorPorLinea[d.numColores]--;
			usoDeColorPorLinea[i]--;

		}
		sumaEnergetica -= consumoPorBombilla[i];
		

	}
	return numSol;
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;

	std::cin >> d.longitud >> d.numColores >>d.consumoMax;
	if (d.longitud == 0) return false;

	std::vector <int> sol(d.longitud);
	std::vector <int> consumoPorBombilla(d.numColores);
	std::vector <int> usoDeColorPorLinea(d.numColores+1,0);


	for (int& n : consumoPorBombilla) std::cin >> n;

	int sumaEnergetica = 0;
	int abrigos = variaciones(d, 0, consumoPorBombilla, usoDeColorPorLinea, sumaEnergetica, sol);


	std::cout << abrigos << '\n';
	//if (abrigos == 0) std::cout << "SIN SOLUCION \n";



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
