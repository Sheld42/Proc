#include <fstream>
#include <iostream>
#include "parallelepiped.h"

using namespace std;

double Volume(parallelepiped &p) {
	double v = p.a * p.b * p.c;
	if (abs(v / (p.a * p.b) - p.c) >= 0.00001) {
		cerr << "ERROR VOLUME OVERFLOW" << endl;
		return 0;
	}
	return p.a * p.b * p.c;
}