#define _CRT_SECURE_NO_WARNINING
#include <iostream>			
using namespace std;


void  main(){
	int* p = nullptr;
	int x = 5;
	p = &x;
	cout << x << " are adresa de memorie " << p;
	cout << " valoarea " << *p;
	cout << " adresa " << &p;


}