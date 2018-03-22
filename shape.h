#include "ball.h"
#include "parallelepiped.h"

struct shape {
		enum type { BALL, PARALLELEPIPED };
		type key; 
		void* obj;
		int temperature;
};