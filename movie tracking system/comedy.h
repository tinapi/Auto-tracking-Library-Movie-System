#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy: public Movie {
	//friend ostream& operator<<(ostream&, const NodeData&); // use << call print since << can’t be virtual

public:
	Comedy();					//default constructor
	Comedy(const Comedy  &);	//copy constructor

	virtual NodeData* create() const;
	virtual bool setSorting(ifstream &); // overide sorting data

	// ovewriting opeartors
	virtual bool operator== (const NodeData&) const;
	virtual bool operator!= (const NodeData&) const;
	virtual bool operator> (const NodeData&) const;
	virtual bool operator< (const NodeData&) const;
};

#endif
