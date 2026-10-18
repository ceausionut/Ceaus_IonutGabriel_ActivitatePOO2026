#include <iostream>
using namespace std;

void main() {
	int vector[4];
	vector[0] = 1;
	vector[1] = 2;
	vector[2] = 3;
	vector[3] = 4;
	unsigned int dimensiune = sizeof(vector);
	cout << dimensiune;

	for (int i = 0; i < dimensiune; i++) {

		cout << vector[i] << "";
	}
	cout << endl;


}