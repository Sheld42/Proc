#include "ball.h"
#include "parallelepiped.h"
#include "tetraedr.h"

struct shape {
		enum type { BALL, PARALLELEPIPED, TETRAEDR };
		type key; 
		void* obj;
};