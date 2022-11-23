//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

// Variaciones sin repeticion de m elementos tomados de n en n Vm,n=m!
// si n= m entonces se le llama permutacion
struct tDatos {
	int m, n;
};
struct tSol {
	std::vector <char> sol;
	std::vector <bool> marcas;
};

// Escribe una solucion
void escribirSolucion(std::vector <char > const& v) {
	for (char c : v) std::cout << c;
	std::cout << '\n';
}
// Calcula de forma recursiva las variaciones de los elementos
void variaciones(tDatos const &datos, int k, tSol &s) {
	for (char i = 'a'; i < 'a' + datos.m; ++i) {
		s.sol[k] = i;

		if (!s.marcas[i-'a']) { // Si la letra no esta utilizada
			s.marcas[i-'a'] = true;
			if (k == datos.n - 1) { // Es solucion
				escribirSolucion(s.sol);
			}
			else { // Genera el resto de la solucion
				variaciones(datos, k + 1, s);
			}
			s.marcas[i - 'a'] = false;
		}
	
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int m, n; 
	std::cin >> m >> n;

	if (!std::cin) return false;
	// Generar las soluciones
	
	tSol s;
	s.sol.resize(n);
	s.marcas.assign(m, false);

	variaciones({ m,n }, 0, s);

	std::cout << '\n';
	return true;
}
int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}
