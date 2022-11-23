
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion, que identifica  en este problema a los  niños

using tMatriz = std::vector <std::vector<int>>;

struct tDatos {
	int numJuguetes, numNinos;
};

struct tSol {
	std::vector <int> sol;
	int sumaSatist;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";
	std::cout << '\n';
}
//esValida : tiene coste constante.

// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k, tSol& s, std::vector <bool>& juguetesUsados, tMatriz const& satisfacionJugueteNino,int &maxSatisfaccion) {

	for (int i = 0; i < d.numJuguetes; i++) {

		s.sol[k] = i;
		s.sumaSatist += satisfacionJugueteNino[k][i];

		if (!juguetesUsados[i]) {

			juguetesUsados[i] = true;

			if (k == d.numNinos - 1) { //Es solución
				
				//escribirSolucion(s.sol);
				if (maxSatisfaccion < s.sumaSatist) maxSatisfaccion = s.sumaSatist;
				
			}
			else { // Sigue completando la solucion
				resolver(d, k + 1, s, juguetesUsados, satisfacionJugueteNino, maxSatisfaccion);
			}

			juguetesUsados[i] = false;
		}

		s.sumaSatist -= satisfacionJugueteNino[k][i];
	}

}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;

	std::cin >> d.numJuguetes >> d.numNinos ;
	if (!std::cin) return false;

	tSol s;
	s.sol.resize(d.numNinos);
	s.sumaSatist = 0;

	tMatriz satisfacionJugueteNino(d.numNinos, std::vector <int >(d.numJuguetes));

	int satisfacionMaxima = 0;

	for (int i = 0; i < d.numNinos; i++) {
		for (int j = 0; j < d.numJuguetes; j++) {
			std::cin >> satisfacionJugueteNino[i][j];
			if (i == j)satisfacionMaxima += satisfacionJugueteNino[i][j];
		}
	}

	std::vector <bool> juguetesUsados(d.numJuguetes, false); //marcas

	resolver(d, 0, s, juguetesUsados, satisfacionJugueteNino, satisfacionMaxima);

	std::cout  << satisfacionMaxima << "\n";

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
