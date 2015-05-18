//////////////////////////////  management.cpp  /////////////////////////////
#include "management.h"

//--------------------------  constructor  -----------------------------------
;Management::Management() {};

//--------------------------  destructor  ------------------------------------
Management::~Management() {};

//--------------------------  build collection  ------------------------------
void Management::buildCollection(ifstream & infile) {
	for(;;){
		char type;
		infile >> type;

		if (infile.eof()) break;		

		if (type == 'C' || type == 'F' || type == 'D') {
			NodeData* m = movieFactory.createIt(type);
			m->setData(infile);
			movieCollection.addMovie(m, type);
		}
		else { // ignore invalid movie type
			string s;					
			getline(infile, s);
		}
	}
}

//--------------------------  display collection  ----------------------------
void Management::displayCollection() const {
	cout << movieCollection;
}

void Management::buildUserDatabase(ifstream& infile) {
	for (;;){
		if (infile.eof()) break;
		
		User* oneUser = new User();
		oneUser->setdata(infile);
		users.addUser(oneUser);
	}
}

void Management::displayUser() const {
	cout << users << endl;
}

void Management::runCommand(ifstream& infile) const {
	for (;;) {
		char commandCode;
		infile >> commandCode;

		if (infile.eof()) break;

		// verify commandCode
		if (commandCode == 'B' || commandCode == 'R') {
			//verify user ID
			int userID;
			infile >> userID;
			if (!users.findUser(userID)) { // invalid userID, ignore rest line of data
				string s;
				getline(infile, s);
				continue;
			}
			// retrive user 
			User* targetUser;
			users.retrieveUser(userID, targetUser);

			// verify media type
			char mediaType;
			infile >> mediaType;
			if (mediaType != 'D') {
				string s;
				getline(infile, s);
				continue;
			}

			// verify movie code
			char movieCode;
			infile >> movieCode;
			if (movieCode == 'C' || movieCode == 'D' || movieCode == 'F') {
				// read in sorting data
				NodeData* m = movieFactory.createIt(movieCode);
				m->setSorting(infile);

				// check if movie is valid
				NodeData* targetMovie;
				if (movieCollection.retriveMovie(*m, targetMovie, movieCode)) {
					// when movie is valid, initiate transaction object
					Transaction* t = transacFactory.createIt(commandCode);
					// if process succeeds, add transaction obj to user history
					if (t->process(targetUser, targetMovie)) {
						targetUser->addHistory(t);
					}
				}
			}
		else if (commandCode == 'H') {
			//verify user ID
			int userID;
			infile >> userID;
			if (!users.findUser(userID)) { 
				// invalid userID, ignore rest line of data
				string s;
				getline(infile, s);
			}

			// retrive user 
			User* targetUser;
			users.retrieveUser(userID, targetUser);

			Transaction* t = transacFactory.createIt(commandCode);
			if (t->process(targetUser, NULL)) {
				t->process(); // display history
			}
		}
		else if (commandCode == 'S') {
			Transaction* t = transacFactory.createIt(commandCode);    //!!!!!!!!!!!! Need help in this part! How to link to Collection?
			t->setCollection(*movieCollection);
			t->process();
		}
		else { // ignore invalid movie code
			string s;
			getline(infile, s);
		}
	}
}
