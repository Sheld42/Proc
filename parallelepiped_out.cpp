#include <fstream>
#include "parallelepiped.h"

using namespace std;
void CheckOutputFile(ofstream &ofst);

void OutParallelepiped(parallelepiped &p, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c
		<< ", Density = " << p.d << endl;
}