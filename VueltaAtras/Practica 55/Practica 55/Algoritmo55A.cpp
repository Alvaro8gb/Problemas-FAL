
//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

// sol vector short int (ternario) que para una cancion i , si v[i] = 0 la esucha en la ida ,
//si v[i] = 1 la escuha en la vuelta  v[i]= 2 no la escucha.
//k  es la cancion que corresponde ala etapa en el arbol de exploracion. 
struct tCancion {
	int duracion, satisfaccion;
};
struct tDatos {
	int numCanciones, t1, t2;
	std::vector <tCancion> cancionesInfo;
};
struct tSol {
	std::vector <short int> sol;
	int sumaDuracionIda, sumaDuracionVuelta, satisfaccionMaxima;
};
// Escribe una solucion
void escribirSolucion(std::vector <short int > const& v) {
	std::vector <short int> cancionesIda;
	std::vector <short int> cancionesVuelta;

	for (int i = 0; i < v.size(); i++) {
		
		switch (v[i]){
		case 0:
			cancionesIda.push_back(i);
			break;
		case 1:
			cancionesVuelta.push_back(i);
			break;
		}
	}
	std::cout << "Canciones ida: ";
	for (int i = 0; i < cancionesIda.size(); i++) std::cout << cancionesIda[i] << " ";

	std::cout << "\nCanciones vuelta: ";
	for (int i = 0; i < cancionesVuelta.size(); i++) std::cout << cancionesVuelta[i] << " ";

	std::cout << "\n";
	
}

// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k,tSol& s, tSol& mejorSol) {

	
		s.sol[k] = 1; //se reproduce en la vuelta
		s.sumaDuracionVuelta += d.cancionesInfo[k].duracion;
		if (s.sumaDuracionVuelta <= d.t2) { //Es valida

			s.satisfaccionMaxima += d.cancionesInfo[k].satisfaccion;
			if (k == d.numCanciones - 1) { //Es solución
				if (s.sumaDuracionIda == d.t1 && s.sumaDuracionVuelta == d.t2) //Es sol valida
				{
					if (mejorSol.satisfaccionMaxima < s.satisfaccionMaxima) mejorSol = s;
				}
			}
			else { // Sigue completando la solucion 
				resolver(d, k + 1, s, mejorSol);
			}

			s.satisfaccionMaxima -= d.cancionesInfo[k].satisfaccion;
		}
		s.sumaDuracionVuelta -= d.cancionesInfo[k].duracion;

		s.sol[k] = 0; // se reproduce en la ida
		s.sumaDuracionIda+= d.cancionesInfo[k].duracion;

		if (s.sumaDuracionIda <= d.t1 ) { //Es valida
			
			s.satisfaccionMaxima += d.cancionesInfo[k].satisfaccion;
			if (k == d.numCanciones - 1) { //Es solución
				if (s.sumaDuracionIda == d.t1 && s.sumaDuracionVuelta == d.t2) //Es sol valida
				{
					if (mejorSol.satisfaccionMaxima < s.satisfaccionMaxima) mejorSol = s;
				}
			}
			else { // Sigue completando la solucion 
					resolver(d, k + 1 ,s, mejorSol);
			}
			
			s.satisfaccionMaxima -= d.cancionesInfo[k].satisfaccion;
		}

		s.sumaDuracionIda -= d.cancionesInfo[k].duracion;

		
		s.sol[k] = 2; //no se reproduce

		if (k == d.numCanciones - 1) { //Es solución
			if (s.sumaDuracionIda == d.t1 && s.sumaDuracionVuelta == d.t2) //Es sol valida
			{
				if (mejorSol.satisfaccionMaxima < s.satisfaccionMaxima) mejorSol = s;
			}
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
	std::cin >> d.numCanciones >> d.t1 >> d.t2;

	if (d.numCanciones == 0) return false;

	d.cancionesInfo.resize(d.numCanciones);
	for (tCancion& x : d.cancionesInfo) std::cin >> x.duracion >> x.satisfaccion;

	tSol s;
	s.sol.resize(d.numCanciones);
	s.satisfaccionMaxima = s.sumaDuracionIda = s.sumaDuracionVuelta = 0;

	tSol mejorSol;//para guardar la solucion

	mejorSol.satisfaccionMaxima = 0; //inicializamos a un valor absurdo

	resolver(d, 0, s, mejorSol);

	if (mejorSol.satisfaccionMaxima == 0) std::cout << "Imposible\n";
	else {
		std::cout << mejorSol.satisfaccionMaxima <<"\n"; //maximaSatisfaccion
		//escribirSolucion(mejorSol.sol);
	}

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
