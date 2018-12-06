#include "Big_daddy.h"
#define epochs 7



int main()
{

	vector<float> test = {
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
		1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0}
	};

	vector<float> test1 = {
	{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
	};

	//vector<vector<float>> ideals = { 
	//{ 1.0, 0.0, 0.0 },	//square
	//{ 1.0, 0.0, 0.0 },
	//{ 0.0, 1.0, 0.0 },	//triangle
	//{ 0.0, 1.0, 0.0 },
	//{ 0.0, 0.0, 1.0 },	//circle
	//{ 0.0, 0.0, 1.0 }};

	

	


	
	vector<float> actual;
	Layer layer1(49), layer2(49), layer3(3);
	vector<Layer> net = { layer1, layer2, layer3 };


	for (int i(0); i < epochs; i++) {
		cout << endl << endl << "EPOCH " << i << endl;
		float counter = 0;

		for (int j(0); j < from_file("dataset.txt", 6, 49).size(); j++) {

			net[0].set_first_layer_outputs(from_file("dataset.txt", 6, 49)[j]);
			net[1].set_layer_outputs(net[0]);
			net[2].set_layer_outputs(net[1]);

			//backpropagation

			net[2].set_last_layer_deltas(from_file("ideals.txt", 6, 3)[j]);
			net[1].set_deltas(net[2]);
			net[0].set_deltas(net[1]);

			actual = net[2].get_layer_outputs();
			counter += error_is(actual, from_file("ideals.txt", 6, 3)[j]) * error_is(actual, from_file("ideals.txt", 6, 3)[j]);
		}
		counter /= from_file("dataset.txt", 6, 49).size();
		cout << "MSE: " << counter;
	}
	
	war(net, test);


	
	


}
