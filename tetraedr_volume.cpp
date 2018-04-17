#include <fstream>
#include "tetraedr.h"
#include <iostream>

using namespace std;

double Volume(tetraedr &t) {
	double v = sqrt(2) * t.a * t.a * t.a / 12;
	if (abs((v * 12 / (sqrt(2) * t.a * t.a)) - t.a) >= 0.00001) {
		cerr << "ERROR VOLUME OVERFLOW" << endl;
		return 0;
	}
	return sqrt(2) * t.a * t.a * t.a / 12;
}