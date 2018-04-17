#include <fstream>
#include <iostream>
#include "parallelepiped.h"

using namespace std;
void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

parallelepiped* InParallelepiped(ifstream &ifst) {
	parallelepiped *p;
	p = new parallelepiped;
	CheckInputFile(ifst);
	ifst >> p->a >> p->b >> p->c >> p->d;
	CheckWrongInput(ifst);
	if (p->a <= 0 || p->b <= 0 || p->c <= 0 || p->d <= 0) {
		cerr << "Error: Incorrect values in parallelepiped input" << endl;
		exit(1);
	}
	return p;
}