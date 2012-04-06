#ifndef BOXBUILDER_H
#define BOXBUILDER_H
#include <QTextDocument>
#include <QGlyphRun>
#include <QPen>
#include <QChar>
#include "log.h"
class BoxBuilder
{
public:
	struct box
	{
		box(QChar character,const QRect& boundingRect)
			:character(character),
			boundingRect(boundingRect)
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
	{}

	void build(const QTextDocument* doc,const QSize& pixmapSize, const QColor& glyphColor = Qt::black);
	const std::list<box>& boxes() const
	{return boxes_;}

	const QPixmap& pixmap() const
	{return pixmap_;}

private:
	void handleGlyphRun_(const QGlyphRun& glyphRun);	
	logger& log_;
	
	std::list<box> boxes_;
	QPixmap pixmap_;

	// these are context variables that are changed when build method runs
	QPen glyphPen_;
	
	QString blockText_;
	QPointF glyphPosition_;

};

#endif // BOXBUILDER_H
