#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Clear(container &c) {
	for (int i = 0; i < c.len; i++) {
		delete c.cont[i];
	}
	c.len = 0;
}