#ifndef BOXBUILDER_H
#define BOXBUILDER_H
#include <QTextDocument>
#include <QGlyphRun>
#include <QPen>
#include <QChar>
#include <map>
#include "log.h"
class BoxBuilder
{
public:
	struct box
	{
		box(QChar character,const QRect& boundingRect)
			:character(character)
			,boundingRect(boundingRect)
			
		{}

		box(const box& obj)
			:character(obj.character)
			,boundingRect(obj.boundingRect)			

		{}
		
		QChar character;
		QRect boundingRect;
	};	
	
	BoxBuilder(logger& log)
		:log_(log)
		,maxHistogramValue(0)
	{}

	void build(const QTextDocument* doc,const QSize& pixmapSize, const QColor& glyphColor = Qt::black);
	const std::list<box>& boxes() const
	{return boxes_;}

	const QPixmap& pixmap() const
	{return pixmap_;}


	int histValue(const QChar& character) const
	{
		std::map<QChar,unsigned>::const_iterator it = histogram.find(character);
		if(it != histogram.end())
			return it->second;
		else return -1;
	}
	
	void clearBoxes();
	
	
	inline unsigned maxHistValue() const
	{return maxHistogramValue;}
private:
	BoxBuilder& operator = (const BoxBuilder);
	void handleGlyphRun_(const QGlyphRun& glyphRun);	
	logger& log_;
	
	std::list<box> boxes_;
	QPixmap pixmap_;
	// a histogram for changing color depending on character's frequency
	std::map<QChar,unsigned> histogram;
	unsigned maxHistogramValue;
	// these are context variables that are changed when build method runs
	QPen glyphPen_;
	
	QString blockText_;
	QPointF glyphPosition_;

};

#endif // BOXBUILDER_H
