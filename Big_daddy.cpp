#include "Big_daddy.h"

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

vector<float> print_layer(Layer layer) {

	vector<float> output(layer.get_layer_size());

	for (int i(0); i < layer.get_layer_size(); i++)
		output[i] = layer.get_neuron(i).get_output();
		
	return output;
}

void war(vector<Layer> fit_net, vector<float> what_is_it) {
	cout << endl << endl << "FIGHT! " << endl;

	fit_net[0].set_first_layer_outputs(what_is_it);
	fit_net[1].set_layer_outputs(fit_net[0]);
	fit_net[2].set_layer_outputs(fit_net[1]);

	cout << "OUT IS ";
	for (int i(0); i < fit_net[2].get_layer_size(); i++)
		cout << print_layer(fit_net[2])[i] << " ";
}

vector<vector<float>> from_file(string filename, int set_size, int elements_in_set) {
	ifstream fin(filename);
	vector<vector<float>> dataset(set_size, vector<float>(elements_in_set));
	while (!fin.eof()) {
		for (int i(0); i < set_size; i++) {
			for (int j(0); j < elements_in_set; j++)
				fin >> dataset[i][j];
		}
	}

	return dataset;
}

