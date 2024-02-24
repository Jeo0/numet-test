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


double what(double howmanyIter_left, double velocity, int time) {
	// exit 
	if(!howmanyIter_left){
		return velocity;
	}
	
	// process
	velocity = (gg*mp/cc) * (1 - pow(
				ee,
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

	int time = atoi(asdf[1]);		// convert string to int
	int howmanyIters = time / 2;
	

	std::cout << what(howmanyIters, 0, 0) << "\n\n";
}
