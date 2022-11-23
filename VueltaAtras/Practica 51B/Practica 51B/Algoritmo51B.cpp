
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

// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k, tSol& s, std::vector <bool>& juguetesUsados, tMatriz const& satisfacionJugueteNino, int& maxSatisfaccion, std::vector <int >const & acum) {

	for (int i = 0; i < d.numJuguetes; i++) {

		s.sol[k] = i;
		s.sumaSatist += satisfacionJugueteNino[k][i];

		if (!juguetesUsados[i]) {

			juguetesUsados[i] = true;

			if (k == d.numNinos - 1) { //Es solución

				//escribirSolucion(s.sol);
				if (maxSatisfaccion < s.sumaSatist) maxSatisfaccion = s.sumaSatist;

			}
			else { // Sigue completando la solucion en el caso que se pueda mejorar 
				if(s.sumaSatist + acum[k + 1] > maxSatisfaccion) resolver(d, k + 1, s, juguetesUsados, satisfacionJugueteNino, maxSatisfaccion,acum);
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

	std::cin >> d.numJuguetes >> d.numNinos;
	if (!std::cin) return false;

	tSol s;
	s.sol.resize(d.numNinos);
	s.sumaSatist = 0;

	tMatriz satisfacionJugueteNino(d.numNinos, std::vector <int >(d.numJuguetes));

	for (int i = 0; i < d.numNinos; i++) {
		for (int j = 0; j < d.numJuguetes; j++) {
			std::cin >> satisfacionJugueteNino[i][j];
		}
	}

	int satisfacionMaxima = 0;

	for(int i =0 ; i< d.numNinos;i++)satisfacionMaxima += satisfacionJugueteNino[i][i];  //Se inicializa una satisfacción posible

	std::vector <bool> juguetesUsados(d.numJuguetes, false); //marcas

	// Calculo del vector de maximos
	std::vector <int > acum(d.numNinos);
	int maxSatfNino;
	for (int i = 0; i < d.numNinos; ++i) {
		maxSatfNino  = satisfacionJugueteNino[i][0];
		for (int j = 1; j < d.numJuguetes; ++j) if (maxSatfNino < satisfacionJugueteNino[i][j]) maxSatfNino = satisfacionJugueteNino[i][j];
		acum[i] = maxSatfNino;
	}
	// Calculo del vector de acumulados
	for (int i = (int)acum.size() - 1; i > 0; --i)  acum[i - 1] += acum[i];

	resolver(d, 0, s, juguetesUsados, satisfacionJugueteNino, satisfacionMaxima,acum);

	std::cout << satisfacionMaxima << "\n";

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
