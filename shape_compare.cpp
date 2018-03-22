#include <fstream>
#include <iostream>
#include "shape.h"

using namespace std;

double Volume(shape *s);

bool Compare(shape *first, shape *second) {
	return Volume(first) < Volume(second);
}