#include <fstream>
#include "parallelepiped.h"

using namespace std;

void OutParallelepiped(parallelepiped &p, ofstream &ofst) {
	ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c
		<< ", Density = " << p.d << endl;
}