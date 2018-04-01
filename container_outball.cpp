#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);

void OutBall(container &c, ofstream &ofst) {
	ofst << "Only balls." << endl;
	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->key == shape::type::BALL) {
			ofst << i + 1 << ": ";
			Out((c.cont[i]), ofst);
		}
		else
			ofst << endl;
	}
}