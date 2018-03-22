#include <fstream>
#include <iostream>
#include "shape.h"

using namespace std;

void OutBall(ball &b, ofstream &ofst);
void OutParallelepiped(parallelepiped &p, ofstream &ofst);

void Out(shape *s, ofstream &ofst) {
	switch (s->key) {
	case shape::type::BALL:
		OutBall(*(ball *)s->obj, ofst);
		break;
	case shape::type::PARALLELEPIPED:
		OutParallelepiped(*(parallelepiped *)s->obj, ofst);
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
}