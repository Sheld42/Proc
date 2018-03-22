#include <fstream>
#include "parallelepiped.h"

using namespace std;

double Volume(parallelepiped &p) {
	return p.a*p.b*p.c;
}