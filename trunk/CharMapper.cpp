#include "CharMapper.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>

#include <QStringList>

void CharMapper::readCharMap(const QString& fileName)
{
	QFile mappingFile(fileName);
	mappingFile.open(QFile::ReadOnly|QFile::Text);
	QTextStream mappingFileStream(&mappingFile);
	mappingFileStream.setCodec(QTextCodec::codecForName("UTF-8"));
	int count = 0;
	while(!mappingFileStream.atEnd())
	{
		QString curLine = mappingFileStream.readLine();
		QStringList lexems = curLine.split('=');
		if(lexems.size() < 2)
		{
			QString message = "syntax error at line " + QString::number(count);
			throw std::runtime_error(message.toStdString());
		}
		QString replacement = *lexems.begin();
		QString subject = *(--lexems.end());

		replacement = replacement.trimmed();
		subject = subject.trimmed();
		
		charMap[subject] = replacement.at(0);
		if(subject.length() > maxReplacementLength)
			maxReplacementLength = subject.length();
		
		++count;
	}
}

void CharMapper::bufferStep(std::list<BoxBuilder::box>& backBuffer, std::list<BoxBuilder::box>& output,const BoxBuilder::box& box)
{
	backBuffer.push_back(box);
	bool popFront = (static_cast<int>(backBuffer.size()) >= maxReplacementLength);
	bufferStep(backBuffer,output,popFront);
}

void CharMapper::bufferStep(std::list<BoxBuilder::box>& backBuffer, std::list<BoxBuilder::box>& output,bool popFront)
{
	// NOTE: pushing to the backbuffer is not responsibility of this function
	QString bufferContents;	
	typedef std::list<BoxBuilder::box>::iterator BoxIterator;
	for(BoxIterator boxIt = backBuffer.begin();boxIt != backBuffer.end(); ++boxIt)	
	{
		const BoxBuilder::box& box = *boxIt;
		bufferContents += box.character;
		std::map<QString,QChar>::const_iterator found = charMap.find(bufferContents);
		if(found != charMap.end())
		{
			QRect resultingRect;
			BoxIterator boxItNext = boxIt;
			++boxItNext;
			std::for_each(backBuffer.begin(),boxItNext,
				[&resultingRect](const BoxBuilder::box& box)
			{
				resultingRect |= box.boundingRect;
			});
			BoxBuilder::box outputValue(found->second,resultingRect);
			output.push_back(outputValue);

			backBuffer.erase(backBuffer.begin(),boxItNext);
			break;
		}
		
	}
	if(popFront)
	{
		if(backBuffer.size() > 0)
		{
			output.push_back(backBuffer.front());
			backBuffer.pop_front();
		}
	}
}

void CharMapper::mapBoxes(const std::list<BoxBuilder::box>& boxes)
{
	boxes_.clear();
	QString subject;
	std::list<BoxBuilder::box> backBuffer;

	std::for_each(boxes.begin(),boxes.end(),
		[this,&backBuffer](const BoxBuilder::box& box)
	{
		bufferStep(backBuffer,boxes_,box);
	});
	
	while(backBuffer.size() > 0)
		bufferStep(backBuffer,boxes_);
}
