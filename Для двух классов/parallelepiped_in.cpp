#include <fstream>
#include "parallelepiped.h"

using namespace std;

parallelepiped* InParallelepiped(ifstream &ifst) {
	parallelepiped *p;
	p = new parallelepiped;
	ifst >> p->a >> p->b >> p->c >> p->d;
	return p;
}