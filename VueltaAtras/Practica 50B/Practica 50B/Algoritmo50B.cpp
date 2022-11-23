
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion, que identifica  en este problema a los  niños

using tMatriz = std::vector <std::vector<int>> ;

struct tDatos {
	int numJuguetes, numNinos,satisfaccionMinima;
	std::vector <int> juguetesDisponibles;
	std::vector <std::string> tiposDeJuguetes;
};

struct tSol {
	std::vector <int> sol;
	int sumaSatist;
	bool haySol;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";
	std::cout << '\n';
}
//esValida : tiene coste constante.
bool esValida(std::vector <int >const& sol, int k, int i, std::vector <int> const & juguetesUsados, tDatos const& d, tMatriz const& satisfacionJugueteNino) {

	if (k % 2 != 0) {//el segundo juguete ,k impares

		if (d.tiposDeJuguetes[i] == d.tiposDeJuguetes[sol[k - 1]]) return false; //El segundo juguete no sea del mismo tipo
		if (i < sol[k - 1]) return false; //el identificador del primer juguete sea menor que el identificador del segundo.
		if ((satisfacionJugueteNino[k / 2][i] + satisfacionJugueteNino[k / 2][sol[k-1]] ) <  d.satisfaccionMinima) return false; //todos los ninos puedan llegar a un cierto grado de satisfaccion
	}

	if ( juguetesUsados[i] > d.juguetesDisponibles[i] ) return false; //No hay mas juguetes de este tipo.

	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
void combinaciones(tDatos const& d, int k, tSol & s, std::vector <int> &juguetesUsados,tMatriz const & satisfacionJugueteNino) {

	for (int i = 0; i < d.numJuguetes; i++) {

		s.sol[k] = i;
		juguetesUsados[i]++;

		if (esValida(s.sol, k, i, juguetesUsados, d, satisfacionJugueteNino)) {

			if (k == d.numNinos * 2 - 1) { //Es solución
				escribirSolucion(s.sol);
				s.haySol = true;
			}
			else { // Sigue completando la solucion
				combinaciones(d, k + 1, s, juguetesUsados, satisfacionJugueteNino);
			}
		}
		juguetesUsados[i]--;
	}

}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;

	std::cin >> d.numJuguetes >> d.numNinos  >> d.satisfaccionMinima;
	if (!std::cin) return false;

	tSol s;
	s.sol.resize(d.numNinos * 2);
	s.sumaSatist = 0;
	s.haySol = false;

	d.juguetesDisponibles.resize(d.numJuguetes);
	for (int& x : d.juguetesDisponibles) std::cin >> x;

	d.tiposDeJuguetes.resize(d.numJuguetes);
	for (std::string& x : d.tiposDeJuguetes) std::cin >> x;

	tMatriz satisfacionJugueteNino(d.numNinos, std::vector <int >(d.numJuguetes));

	for (int i = 0; i < d.numNinos; i++) {
		for (int j = 0; j < d.numJuguetes; j++) std::cin >> satisfacionJugueteNino[i][j];
	}

	std::vector <int> juguetesUsados(d.numJuguetes,0); //marcas

	combinaciones(d, 0, s, juguetesUsados, satisfacionJugueteNino);

	if (!s.haySol)std::cout << "SIN SOLUCION\n";

	std::cout << '\n';

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
