#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Layer.h"

using namespace std; 

float error_is(vector<float> actual, vector<float> ideal) {
	if (actual.size() == ideal.size()) {
		float summ = 0, count = 0;
		for (unsigned i(0); i < actual.size(); i++) {
			count++;
			summ += ideal[i] - actual[i];
		}
		
		return abs(summ / count);
	}
	else {
		cout << "False dimensions";
	}
}

void print_layer_outputs(Layer layer) {
	for (int i(0); i < layer.get_layer_size(); i++) {
		cout << layer.get_layer_outputs()[i] << " ";
	}
	cout << endl;
}

void print_v(vector <float>& arr) {
	for (unsigned int i(0); i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_layer(Layer layer) {
	
	for (int i(0); i < layer.get_layer_size(); i++) {
		cout << layer.get_neuron(i).get_output() << " ";
	}

	cout << endl << endl << endl;
	
}




int main()
{

	vector<vector<float>>
		inputs = { 
			
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
	
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
		0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
	};


		
	vector<vector<float>>
		ideals = { { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } };

	
	vector<float> actual;
	Layer layer1(49), layer2(49), layer3(3);
	int epochs= 25; 
	
	
	
	for(int i(0); i < epochs; i++){
		cout << endl << "EPOCH " << i << endl << endl;
		float counter = 0;
		for(int j(0); j < inputs.size(); j++) {
			
				layer1.set_first_layer_outputs(inputs[j]);
				
				layer2.set_layer_outputs(layer1);
				layer3.set_layer_outputs(layer2);

				//backpropagation

				layer3.set_last_layer_deltas(ideals[j]);
				layer2.set_deltas(layer3);
				layer1.set_deltas(layer2);

				actual = layer3.get_layer_outputs();
				counter += error_is(actual, ideals[j]) * error_is(actual, ideals[j]);
		}
		counter /= inputs.size();
		cout << "Error: " << counter; 
	}

	cout << "WAR: " << endl;
	layer1.set_first_layer_outputs(inputs[2]);
	layer2.set_layer_outputs(layer1);
	layer3.set_layer_outputs(layer2);
	print_layer(layer3);

}
