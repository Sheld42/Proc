#include "shape.h"

struct container {
	enum { max_len = 100 }; // ������������ �����
	int len; 			 // ������� �����
	shape *cont[max_len];
};