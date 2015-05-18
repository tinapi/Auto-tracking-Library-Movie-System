#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama: public Movie {

public:
	Drama();					//default constructor
	Drama(const Drama  &);	//copy constructor

	virtual NodeData* create() const;
	virtual bool setSorting(ifstream &); // overide sorting data

	// overwriting opeartors
	virtual bool operator== (const NodeData&) const;
	virtual bool operator!= (const NodeData&) const;
	virtual bool operator> (const NodeData&) const;
	virtual bool operator< (const NodeData&) const;
};

#endif
