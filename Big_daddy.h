#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Layer.h"

using namespace std;

float error_is(vector<float> actual, vector<float> ideal);

vector<float> print_layer(Layer layer);

void war(vector<Layer> fit_net, vector<float> what_is_it);