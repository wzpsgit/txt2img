#ifndef CHARTABLEREADER_H
#define CHARTABLEREADER_H

#include <QFile>
#include <QTextStream> 
#include <QString>
#include <QStringList>
#include <QColor>
#include <map>

class CharTableReader
{
	QFile file;

public:	
	CharTableReader(const QString& fileName)
		:file(fileName)
	{}
	const std::map<uint,std::pair<QColor,QString> >& read()
	{
		charMap.clear();
		file.open(QFile::ReadOnly|QFile::Text);
		QTextStream tstream(&file);
		size_t lineCount = 0;
		bool ok = false;
		while(!tstream.atEnd())
		{
			QString line = tstream.readLine();
			QStringList items = line.split("->");
			if(items.length() < 2)
				throw std::runtime_error("Invalid line in charmap file, line " + lineCount);
			
			QString colorString = items.at(1);
			if(!QColor::isValidColor(colorString))
				throw new std::runtime_error("Invalid color at line " + lineCount);
			QString description;
			if(items.length() > 2)
				description = items.at(2);
			
			QString charCode =  items.at(0);

			std::pair<QColor,QString> charData(QColor(colorString),description);
			if(charCode.contains('-'))	// char range selected
			{
				QStringList codes = charCode.split('-');
				uint start = codes.at(0).toUInt(&ok,16);
				if(!ok)
					throw std::runtime_error("Invalid start code at line " + lineCount);
				uint end = codes.at(1).toInt(&ok,16);
				if(!ok)
					throw std::runtime_error("Invalid end code at line " + lineCount);
				for(uint i = std::min(start,end);i < std::max(start,end); ++i)
					charMap[i] = charData;
			}
			else						// a single character
			{
				uint code = charCode.toUInt(&ok,16);
				charMap[code] = charData;
			}
			++lineCount;
		}

		return charMap;
	}
private:
	std::map<uint,std::pair<QColor,QString> > charMap;
};

#endif // CHARTABLEREADER_H
