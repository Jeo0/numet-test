#include <iostream>
#include <cmath>
#include <chrono>
#include <typeinfo>
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

void printDebug(std::string functionName){
	std::cout << "\n\n===================";
	std::cout <<   "\n=======DEBUG=======";
	std::cout <<   "\nfrom " << functionName << ":\n";
}

unsigned long long int convert_uint(const std::string& noice){
	unsigned short int numberOf_digits = noice.size();

	printDebug("convert_uint");
	std::cerr << "\tdigits : " << numberOf_digits << std::endl;
	

	// process
	int remainder = 0;
	int powerIter = 0;
	for(int index = numberOf_digits - 1; index >= 0; index--){

		remainder += (noice[index] - '0') * pow(10, powerIter);
		powerIter++;
	}
	return remainder;
	

}

int main(int argc, char** asdf){
	// error if less than 2
	if(argc != 2){
		std::cerr << "use " << asdf[0] << " <max time>\n";
		return EXIT_FAILURE;
	}
	std::cerr << "type of asdf " << typeid(asdf[1]).name() << std::endl;
	std::chrono::time_point<std::chrono::system_clock> start, end;



	start = std::chrono::system_clock::now();
	unsigned long long int time = atoi(asdf[1]);		// convert string to int
	end   = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsedSeconds = end - start;
	std::cerr << "\n\n\tatoi elapsed: " << elapsedSeconds.count();
	

	start = std::chrono::system_clock::now();
	unsigned long long int time2 = convert_uint(asdf[1]);
	end   = std::chrono::system_clock::now();


	elapsedSeconds = end - start;
	std::cerr << "\n\n\tcust elapsed: " << elapsedSeconds.count();


	auto howmanyIters = time / 2;
	

	std::cout << what(howmanyIters, double (time / time - 1), double(time / time -1) ) << "\n\n";
}
