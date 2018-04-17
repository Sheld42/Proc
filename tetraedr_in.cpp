#include <fstream>
#include <iostream>
#include "tetraedr.h"

using namespace std;
void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

tetraedr* InTetraedr(ifstream &ifst) {
	tetraedr *t;
	t = new tetraedr;
	CheckInputFile(ifst);
	ifst >> t->a >> t->d;
	CheckWrongInput(ifst);
	if (t->a <= 0 || t->d <= 0) {
		cerr << "Error: Incorrect values in tetrahedron input" << endl;
		exit(1);
	}
	return t;
}