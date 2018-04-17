#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);
double Volume(shape *s);
void CheckOutputFile(ofstream &ofst);

void Out(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len)
		ofst << "Container contains " << c.len << " elements." << endl;
	else
		ofst << "Container is empty:\n";
	for (int i = 0; i < c.len; i++) {
		ofst << i + 1 << ": ";
		Out((c.cont[i]), ofst);
		ofst << "volume = " << Volume(c.cont[i]) << endl;
	}
}