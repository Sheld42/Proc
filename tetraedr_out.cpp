#include <fstream>
#include <iostream>
#include "tetraedr.h"

using namespace std;

void OutTetraedr(tetraedr &t, ofstream &ofst) {
	ofst << "It is Tetraedr: a = " << t.a << ", Density = " << t.d << endl;
}