
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion

struct tDatos {
	int numJuguetes, numNinos;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";

	std::cout << '\n';
}
//esValida : tiene coste constante.
bool esValida(std::vector <int >const& sol, int k, int i, std::vector <std::string> const& juguetes){

	if (k % 2 != 0) {//el segundo juguete ,k impares

		if (juguetes[i] == juguetes[sol[k - 1]]) return false; //El segundo juguete no sea del mismo tipo
		if(i < sol[k - 1]) return false; //el identificador del primer juguete sea menor que el identificador del segundo.
	}

	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
void combinaciones(tDatos const& d, int k, std::vector <std::string> const & juguetes, std::vector <int >& sol,bool & haySol) {


	for (int i = 0; i < d.numJuguetes; i++) {

		sol[k] = i;

		if (esValida(sol,k,i,juguetes)) {

			if (k == d.numNinos*2 - 1) { //Es solución

				escribirSolucion(sol);
				haySol = true;
				
			}
			else { // Sigue completando la solucion
				combinaciones(d, k+1, juguetes, sol,haySol);
			}
		}
	}

}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;

	std::cin >> d.numJuguetes >> d.numNinos ;
	if (!std::cin) return false;

	std::vector <int> sol(d.numNinos*2);
	std::vector <std::string> juguetes(d.numJuguetes);
	bool haySol = false;

	for (std::string &x : juguetes) std::cin >> x;

	combinaciones(d, 0, juguetes, sol,haySol);

	if (!haySol)std::cout << "SIN SOLUCION\n";
	
	std::cout <<'\n';

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
