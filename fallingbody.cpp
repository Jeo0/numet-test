#include <iostream>
#include <cmath>
// see seatwork 1 & 2 from numerical methods
// testing recursion instead of loops

namespace constants{
	double ee = 2.14;
	double mp = 68.1;
	double gg = 9.81;
	double cc = 12.5;
} using namespace constants;


double what(auto howmanyIter_left, auto velocity, auto time) {
	// exit 
	if(!howmanyIter_left){
		return velocity;
	}
	
	// process
	/*velocity = (gg*mp/cc) * (1 - pow(
				ee,
				(-1 * cc / mp)  * 2 * time)
				);
	*/
	velocity = (gg*mp/cc) * (1 - pow(
				M_E,
				(-1 * cc / mp)  * 2 * time)
				);

	// recursion to the next step after processing
	return what(howmanyIter_left - 1, velocity, time + 2);
}

int main(int argc, char** asdf){
	// error if less than 2
	if(argc != 2){
		std::cerr << "use " << asdf[0] << " <max time>\n";
		return EXIT_FAILURE;
	}

	unsigned long long int time = atoi(asdf[1]);		// convert string to int
	auto howmanyIters = time / 2;
	

	std::cout << what(howmanyIters, time / time - 1, time / time -1) << "\n\n";
}
