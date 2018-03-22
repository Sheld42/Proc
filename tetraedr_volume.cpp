#include <fstream>
#include "tetraedr.h"

using namespace std;

double Volume(tetraedr &t) {
	return t.a*t.a*t.a;
}