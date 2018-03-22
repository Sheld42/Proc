#include <fstream>
#include <iostream>
#include "shape.h"

using namespace std;

double Volume(ball &b);
double Volume(parallelepiped &p);

double Volume(shape *s) {
	switch (s->key) {
	case shape::type::BALL:
		return Volume(*(ball *)s->obj);
	case shape::type::PARALLELEPIPED:
		return Volume(*(parallelepiped *)s->obj);
	default:
		return -1;
	}
}