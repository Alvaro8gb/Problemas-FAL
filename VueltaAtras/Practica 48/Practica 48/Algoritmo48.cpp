//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion

struct tDatos {
	int numAbrigos,numDias;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";

	std::cout << '\n';
}
//esValida : tiene coste constante.
bool esValida(std::vector <int >const& sol, int k, int i, std::vector <int >const& precipitacionDiaria, std::vector <int >const& precipitacionAbrigos, std::vector <int> const& numDiasAbrigo) {
	
	if (numDiasAbrigo[i] > k / 3 + 2) return false; // No me pongo un abrigo muchos mas dias que otro
	if ( precipitacionDiaria[k] > precipitacionAbrigos[i]  ) return false; // El abrigo soporta la cantidad de lluvia que va a caer
	if (k > 0 && sol[k] == sol[k - 1]) return false; // No llevo dos dias seguidos el mismo abrigo
	
	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
int variaciones(tDatos const &d, int k, std::vector <int >const& precipitacionDiaria, std::vector <int >const& precipitacionAbrigos, std::vector <int >& numDiasAbrigo,std::vector <int >& sol) {
	int numSol = 0;
	for (int i = 0; i < d.numAbrigos; i++) {

		sol[k] = i;
		numDiasAbrigo[i]++;

		if (esValida(sol, k, i, precipitacionDiaria, precipitacionAbrigos, numDiasAbrigo)) {
			
			if (k == d.numDias - 1) {
					
				if (sol[0] != sol[k]) { // El primer abrigo no coincide con el ultimo
					//escribirSolucion(sol);
					numSol++;
				}
			}
			else { // Sigue completando la solucion
				numSol+= variaciones(d, k + 1, precipitacionDiaria, precipitacionAbrigos, numDiasAbrigo, sol);
			}

		}
		numDiasAbrigo[i]--;
	}
	return numSol;
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d; 

	std::cin >> d.numDias >> d.numAbrigos;
	if (d.numDias == 0) return false;

	std::vector <int> sol(d.numDias);
	std::vector <int> precipitacionDiaria(d.numDias);
	std::vector <int> precipitacionAbrigos(d.numAbrigos);
	std::vector <int> numDiasAbrigo(d.numAbrigos,0);

	for (int& n : precipitacionDiaria) std::cin >> n;
	for (int& n : precipitacionAbrigos) std::cin >> n;

	int abrigos =  variaciones(d, 0, precipitacionDiaria, precipitacionAbrigos, numDiasAbrigo, sol);
	
	if (abrigos == 0) std::cout << "Lo puedes comprar \n";
	else std::cout << abrigos << '\n';


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
