#include <math.h>

float sigmoid(float arg) {

	return 1 / (1 + exp(-arg));
	
}

float sigmoid_d(float arg) {

	return arg * (1 - arg);
	
}


