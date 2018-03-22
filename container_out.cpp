#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);

void Out(container &c, ofstream &ofst) {
	ofst << "Container contains " << c.len << " elements." << endl;
	for (int i = 0; i < c.len; i++) {
		ofst << i + 1 << ": ";
		Out((c.cont[i]), ofst);
	}
}