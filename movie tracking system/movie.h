#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iomanip>

#include "nodedata.h"
using namespace std;

const int DEFAULT_QUANTITY = 10;
const int QUANTIRY_OUTPUT_WIDTH = 5;
const int TITLE_OUTPUT_WIDTH = 20;
const int TITLE_OUTPUT_MAX_LENGTH = 18;
const int DIRECTOR_OUTPUT_WIDTH = 18;
const int DIRECTOR_OUTPUT_MAX_LENGTH = 15;
const int YEAR_OUTPUT_WIDTH = 6;

class Movie : public NodeData {
	//friend ostream& operator<<(ostream&, const NodeData&); // use << call print since << can't be virtual

public:
	Movie();					// default constructor
	Movie(const Movie &);	// copy constructor

	virtual ostream& print(ostream &) const;
	virtual bool setData(ifstream &);

	// accessors
	string getDirector() const;
	string getTitle() const;
	int getYear() const;
	int getQuantity() const;
	string getMedia() const;

	// mutators
	void setDirector(string);
	void setTitle(string);
	void setYear(int);
	void setQuantity(int);
	bool increment();
	bool decrement();

protected:
	string director;
	string title;
	int year;
	int instock;
	string media;

};

#endif
