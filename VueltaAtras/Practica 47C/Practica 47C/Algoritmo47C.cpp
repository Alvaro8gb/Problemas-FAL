//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//VR
//Variaciones con repeticion de 3 elementos tomados de n en n  VR 3,n= 3^n 

//k es la estapa del arbol de exploracion

std::string numToColor(int n) {
	switch (n) {
		case(0): return "azul";
		case(1): return "rojo";
		case(2): return  "verde";
	}
}
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << numToColor(num) << " ";

	std::cout << '\n';
}

bool esValida(std::vector <int >const& sol, int k, int color, std::vector <int >const& piezasDisposibles, std::vector <int >const & piezasUsadas) {
	if (color == 2) {
		if(piezasUsadas[2] >= piezasUsadas[0])return false;//el numero de piezas verdes supere al de piezas azules
		
		if (sol[k - 1] == 2) return false;//No puede haber dos verdes seguidas
	}

	 if (piezasDisposibles[color] <= piezasUsadas[color]) return false;
	
	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
void variaciones(int m, int n, int k, std::vector <int >const & piezasDisposibles, std::vector <int >& piezasUsadas,std::vector <int >& sol,bool &haySol) {

	for (int i = 0; i < m; i++) {

		sol[k] = i;

		if (esValida(sol, k, i, piezasDisposibles, piezasUsadas)) {

			piezasUsadas[i]++;

			if (k == n - 1) { // Es solucion
				if (piezasUsadas[1] > piezasUsadas[0] + piezasUsadas[2]) { //el numero de piezas rojas debe ser mayor que la suma de las piezas azules y verdes.
					escribirSolucion(sol);
					if(!haySol) haySol = true;
				}
			}
			else { // Sigue completando la solucion
				variaciones(m, n, k + 1, piezasDisposibles, piezasUsadas, sol, haySol);
			}

			piezasUsadas[i]--;
			
		}
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int n;
	const int COLORS = 3; // azul(0),rojo(1),verde(2)

	std::cin >> n;
	if (n == 0) return false;

	std::vector <int> sol(n);
	std::vector <int> piezasDisposibles(COLORS);
	std::vector <int> piezasUsadas(COLORS, 0);

	bool haySol = false;

	for (int& n : piezasDisposibles) std::cin >> n;
		
	if (piezasDisposibles[1] > 0) {
		sol[0] = 1; //la torre empieza en el color rojo siempre
		piezasUsadas[1]++;

		//la torre contiene n >= 2 piezas
		variaciones(COLORS, n, 1, piezasDisposibles, piezasUsadas, sol, haySol);
	}

	if(!haySol)std::cout << "SIN SOLUCION \n";

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
	system(" PAUSE ");
# endif
	return 0;
}
