#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;

void OutBall(ball &b, ofstream &ofst) {
	ofst << "It is Ball: r = " << b.r << ", Density = " << b.d << endl;
}