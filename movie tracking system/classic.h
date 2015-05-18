#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

const int MONTH_OUTPUT_WIDTH = 5;

class Classic: public Movie {
	//friend ostream& operator<<(ostream&, const NodeData&); // use << call print since << can’t be virtual

public:
	Classic();					//default constructor
	Classic(const Classic &);	//copy constructor

	virtual NodeData* create() const;
	virtual ostream& print(ostream &) const;
	virtual bool setData(ifstream &); // override set data
	virtual bool setSorting(ifstream &); // overide sorting data

	// accesssors
	int getMonth() const;
	string getActFirst() const;
	string getActLast() const;

	// mutators
	void setMonth(int);
	void setActor(string, string);

	// ovewriting opeartors
	virtual bool operator== (const NodeData &) const;
	virtual bool operator!= (const NodeData &) const;
	virtual bool operator> (const NodeData &) const;
	virtual bool operator< (const NodeData &) const;

private:
	int month;
	string actorFirst;
	string actorLast;
};

#endif
