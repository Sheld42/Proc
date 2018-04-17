#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

shape* In(ifstream &ifst);
void CheckInputFile(ifstream &ifst);

void In(container &c, ifstream &ifst) {
	CheckInputFile(ifst);
	while (!ifst.eof() && container::max_len != c.len) {
		if ((c.cont[c.len] = In(ifst)) != 0) {
			c.len++;
		}
	}
}