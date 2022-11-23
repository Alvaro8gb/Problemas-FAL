
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion, que identifica  en este problema a los funcionarios

using tMatriz = std::vector <std::vector<int>>;

struct tSol {
	std::vector <int> sol;
	int sumaTiempo;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";
	std::cout << '\n';
}

// Calcula de forma recursiva las variaciones de los elementos
void resolver(int numFyT, int k, tSol& s, std::vector <bool>& funcionariosUsados, tMatriz const& tiempoFuncionarioTrabajo, int& tiempoMinimo) {

	for (int i = 0; i < numFyT; i++) {

		s.sol[k] = i;
		if (!funcionariosUsados[i]) {

			s.sumaTiempo += tiempoFuncionarioTrabajo[k][i];
			funcionariosUsados[i] = true;

			if (k == numFyT - 1) { //Es solución

				//escribirSolucion(s.sol);
				if (tiempoMinimo > s.sumaTiempo) tiempoMinimo = s.sumaTiempo;

			}
			else { // Sigue completando la solucion
				  resolver(numFyT, k + 1, s, funcionariosUsados, tiempoFuncionarioTrabajo, tiempoMinimo);
			}

			s.sumaTiempo -= tiempoFuncionarioTrabajo[k][i];
			funcionariosUsados[i] = false;
		}	
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int numFyT;

	std::cin >> numFyT;

	if (numFyT == 0) return false;

	tSol s;
	s.sol.resize(numFyT);
	s.sumaTiempo = 0;

	tMatriz tiempoFuncionarioTrabajo(numFyT, std::vector <int >(numFyT));

	for (int i = 0; i < numFyT; i++) {
		for (int j = 0; j < numFyT; j++) std::cin >> tiempoFuncionarioTrabajo[i][j];
	}

	int tiempoMinimo = 0;

	for (int i = 0; i < numFyT; i++)tiempoMinimo += tiempoFuncionarioTrabajo[i][i];  //Se inicializa con  una solucion posible

	std::vector <bool> funcionariosUsados(numFyT, false); //marcas

	resolver(numFyT, 0, s, funcionariosUsados, tiempoFuncionarioTrabajo, tiempoMinimo);

	std::cout << tiempoMinimo << "\n";

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
