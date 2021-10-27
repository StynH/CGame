#include "Random.h"
#include <stdlib.h>

float RandomFloatBetween(float _min, float _max)
{
	const float random = ((float)rand()) / (float)RAND_MAX;
	const float diff = _max - _min;
	const float r = random * diff;
    return _min + r;
}
