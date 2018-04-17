#include <fstream>
#include <iostream>
#include "shape.h"

using namespace std;

ball* InBall(ifstream &ist);
parallelepiped* InParallelepiped(ifstream &ist);
tetraedr* InTetraedr(ifstream &ist);

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

shape* In(ifstream &ifst) {
	shape *sp;
	int k;
	CheckInputFile(ifst);
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3)) {
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	if (ifst.eof()) {
		cerr << "Error: no data after type!" << endl;
		exit(1);
	}
	switch (k) {
	case 1:
		sp = new shape;
		sp->key = shape::type::BALL;
		sp->obj = (void*)InBall(ifst);
		break;
	case 2:
		sp = new shape;
		sp->key = shape::type::PARALLELEPIPED;
		sp->obj = (void*)InParallelepiped(ifst);
		break;
	case 3:
		sp = new shape;
		sp->key = shape::type::TETRAEDR;
		sp->obj = (void*)InTetraedr(ifst);
		break;
	default:
		cerr << "Incorrect figure!" << endl;
		return NULL;
	}
	ifst >> sp->temperature;
	CheckWrongInput(ifst);
	return sp;
}