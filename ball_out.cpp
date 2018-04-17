#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;
void CheckOutputFile(ofstream &ofst);

void OutBall(ball &b, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is Ball: r = " << b.r << ", Density = " << b.d << endl;
}