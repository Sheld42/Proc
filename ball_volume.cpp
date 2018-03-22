#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;

double Volume(ball &b) {
	return 4 * 3.14*b.r*b.r*b.r / 3;
}