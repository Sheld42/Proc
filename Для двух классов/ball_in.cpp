#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;

ball* InBall(ifstream &ifst) {
	ball *b;
	b = new ball;
	ifst >> b->r >> b->d;
	return b;
}