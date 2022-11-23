
#include <iostream>
#include <string>
std::string conversorBinarioNoFinal(int n) {

	if (n == 0) return "0";
	else if (n == 1) return "1";
	else return conversorBinarioNoFinal(n / 2) + std::to_string( n% 2);

}
std::string conversorBinarioFinal(int n,std::string act) {

	if (n == 0) return  "0" + act;
	else if (n == 1) return "1" + act;
	else return conversorBinarioFinal(n / 2, std::to_string(n % 2) + act);

}
int main() {


	std::cout << conversorBinarioNoFinal(32);
	std::cout << conversorBinarioFinal(32,"");
	return 0;
}