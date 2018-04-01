#include <fstream>
#include "tetraedr.h"

using namespace std;

double Volume(tetraedr &t) {
	return sqrt(2)*t.a*t.a*t.a / 12;
}