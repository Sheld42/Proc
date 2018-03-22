#include <fstream>
#include <iostream>
#include "shape.h"

using namespace std;

ball* InBall(ifstream &ist);
parallelepiped* InParallelepiped(ifstream &ist);

shape* In(ifstream &ifst) {
	shape *sp;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sp = new shape;
		sp->key = shape::type::BALL;
		sp->obj = (void*)InBall(ifst);
		return sp;
	case 2:
		sp = new shape;
		sp->key = shape::type::PARALLELEPIPED;
		sp->obj = (void*)InParallelepiped(ifst);
		return sp;
	default:
		return NULL;
	}
}