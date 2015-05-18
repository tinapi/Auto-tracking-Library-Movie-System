///////////////////////////////  factory.cpp  ////////////////////////////////
#include "factory.h"

Factory::Factory() {}

Factory::~Factory() {}

int Factory::hash(char ch) const{
	return ch - 'A';
}
