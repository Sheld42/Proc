#include "shape.h"

struct container {
	enum { max_len = 100 }; // максимальная длина
	int len; 			 // текущая длина
	shape *cont[max_len];
};