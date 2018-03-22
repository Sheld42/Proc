#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);
void Sort(container &c);
void OutBall(container &c, ofstream &ofst);
void OutParallelepiped(container &c, ofstream &ofst);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			 "Waited: command infile outfile" << endl;
		exit(1);
	}
	
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	
	cout << "Start" << endl;
	
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Sort(c);
	OutBall(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}