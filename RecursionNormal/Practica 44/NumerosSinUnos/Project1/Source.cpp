#include <iostream>

using namespace std;

int numerosSinUno(int n) {
	int cont = 0;
	for (int i = 0; i <= n; i++) {

		if (i < 10 && i != 1) cont++;
		else if (i >= 10 && i < 100 && i % 10 != 1 && i / 10 != 1) cont++;
		else if (i >= 100 && i % 10 != 1 && (i / 10 % 10) != 1 && i / 100 != 1)cont++;
	}

	return cont;
}
int main() {

	cout << numerosSinUno(511)<<endl;
	cout << numerosSinUno(500)<<endl;
	cout << numerosSinUno(50)<<endl;
	cout << numerosSinUno(51)<<endl;


	return 0;
}