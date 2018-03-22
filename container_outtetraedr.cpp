#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);

void OutTetraedr(container &c, ofstream &ofst) {
	ofst << "Only tetraedrs." << endl;
	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->key == shape::type::TETRAEDR) {
			ofst << i << ": ";
			Out((c.cont[i]), ofst);
		}
		else
			ofst << endl;
	}
}