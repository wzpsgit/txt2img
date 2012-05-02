#ifndef CHARMAPPER_H
#define CHARMAPPER_H

#include<QString>
#include<list>
#include<map>

#include "boxbuilder.h"

// a map for replacement of mutiple characters with a single one
class CharMapper
{
public:
	CharMapper()
		:maxReplacementLength(0)
	{}
	
	CharMapper(const QString fileName)	
		:maxReplacementLength(0)
	{		
		readCharMap(fileName);
	}
	void readCharMap(const QString& fileName);

	void mapBoxes(const std::list<BoxBuilder::box>& boxes);
	
	const std::list<BoxBuilder::box>& boxes() const
	{return boxes_;}
private:
	

	void bufferStep(std::list<BoxBuilder::box>& backBuffer, std::list<BoxBuilder::box>& output,const BoxBuilder::box& box);
	void bufferStep(std::list<BoxBuilder::box>& backBuffer, std::list<BoxBuilder::box>& output, bool popFront = true);

	std::map<QString,QChar> charMap;	
	int maxReplacementLength;	
	std::list<BoxBuilder::box> boxes_;
};

#endif // CHARMAPPER_H
