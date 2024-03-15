using std::cout, std::cin, std::endl, std::cerr;
using std::string, std::atoi;

void check_correctArgs(const int argc, char* argv[]){
	const string usage = "Usage: ";

	if(argc != 3){
		cerr << "usage: " << argv[0] << " <lowerbound> <upperBound>\n";

		exit(1);
	}

	else if (atoi(argv[1]) < 0 
			|| atoi(argv[2]) < 0){
		cerr << "lowerbound or upperbound must not be negative\n";
		exit(1);
	}
	

}
