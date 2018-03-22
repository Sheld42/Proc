#include <fstream>
#include <iostream>
#include "tetraedr.h"

using namespace std;

tetraedr* InTetraedr(ifstream &ifst) {
	tetraedr *t;
	t = new tetraedr;
	ifst >> t->a >> t->d;
	return t;
}