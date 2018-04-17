#include <fstream>
#include <iostream>
#include "ball.h"

using namespace std;
void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

ball* InBall(ifstream &ifst) {
	ball *b;
	b = new ball;
	CheckInputFile(ifst);
	ifst >> b->r >> b->d;
	CheckWrongInput(ifst);
	if (b->r <= 0 || b->d <= 0) {
		cerr << "Error: Incorrect values in ball input" << endl;
		exit(1);
	}
	return b;
}