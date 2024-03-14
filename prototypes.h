using std::cout, std::cin, std::endl, std::cerr;
using std::string;

void check_correctArgs(int argv, char argc[]){
	const string usage = "Usage: ";

	if(argv != 3){
		cerr << "usage: " << argc[0] << " <lowerbound> <upperBound>\n";

		exit(1);
	}

	else if ((int)argc[1] - '0' < 0
			|| (int) argc[2] - '0' < 0){
		cerr << "lowerbound or upperbound must not be negative\n";
		cout << argc[1] - '0';
		exit(1);
	}

}
