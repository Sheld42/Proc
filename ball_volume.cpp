#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;

double Volume(ball &b) {
	double v = 4 * 3.14*b.r*b.r*b.r / 3;
	if (abs((v * 3 / (4 * 3.14 *b.r*b.r)) - b.r) >= 0.00001) {
		cerr << "ERROR VOLUME OVERFLOW" << endl;
		return 0;
	}
	return 4 * 3.14*b.r*b.r*b.r / 3;
}