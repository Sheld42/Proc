#include <fstream>
#include <iostream>
#include "tetraedr.h"

using namespace std;
void CheckOutputFile(ofstream &ofst);

void OutTetraedr(tetraedr &t, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is Tetraedr: a = " << t.a << ", Density = " << t.d << endl;
}