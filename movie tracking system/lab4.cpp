#include "management.h"

;using namespace std;

int main() {
	// open movie file 
	ifstream infile1("data4movies.txt");
	if (!infile1) {
      cout << "File could not be opened." << endl;
      return 1;
	}

	Management myManager;
	myManager.buildCollection(infile1);
	myManager.displayCollection();	

	// open user file
	ifstream infile2("data4customers.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	myManager.buildUserDatabase(infile2);
	myManager.displayUser();

	// open command file
	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	myManager.runCommand(infile3);

	return 0;
}
