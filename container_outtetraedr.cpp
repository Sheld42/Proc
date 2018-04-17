#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);
void CheckOutputFile(ofstream &ofst);

void OutTetraedr(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len) {
		ofst << "Container contains " << c.len << " elements." << endl;
		ofst << "Only tetraedrs." << endl;
	}
	else
		ofst << "Container is empty:\n";
	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->key == shape::type::TETRAEDR) {
			ofst << i + 1 << ": ";
			Out((c.cont[i]), ofst);
		}
		else
			ofst << endl;
	}
}