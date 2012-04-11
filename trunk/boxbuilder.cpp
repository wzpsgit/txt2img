#include "boxbuilder.h"
#include <iostream>
#include <QTextBlock>

#include <QTextLayout>
#include <QPainter>

void BoxBuilder::handleGlyphRun_(const QGlyphRun& glyphRun)
{
		QPainter painter_(&pixmap_);
		painter_.setPen(glyphPen_);
		painter_.drawGlyphRun(glyphPosition_,glyphRun);

		QVector<quint32> indices = glyphRun.glyphIndexes();		
		QVector<QPointF> positions = glyphRun.positions();
			
		if(indices.size() != positions.size())
			log_ << "the number of indices and the number of positions are different: "
				<< indices.size() << " and " << positions.size() << std::endl;
		QVector<QPointF>::Iterator posit = positions.begin();			

		qreal	posx = glyphPosition_.x(),
				posy = glyphPosition_.y();		
			
		for(QVector<quint32>::iterator ixIt = indices.begin();ixIt != indices.end();++ixIt)
		{

			QRawFont rawFont = glyphRun.rawFont();
			QPainterPath painterPath = rawFont.pathForGlyph(*ixIt);
			QRectF glyphBoundingRect = painterPath.boundingRect();

			QVector<uint> blockTextIndices(blockText_.length());
			int blockTextIndicesSize  = blockTextIndices.size();
			rawFont.glyphIndexesForChars(blockText_.begin(),blockText_.length(),blockTextIndices.begin(),&blockTextIndicesSize);
			std::map<uint,QChar> glyphIndicesToChars;
			std::wstring blockTextStdw = blockText_.toStdWString();
			// build index for acessing chars in text, since glyphs order may not correspond chars order in text
			for(int i = 0; i < blockTextIndices.size(); ++i)				
				glyphIndicesToChars[blockTextIndices[i] ] = blockText_.at(i);				

			QChar currentChar = glyphIndicesToChars[*ixIt];
			unsigned histValue = 0;
			if(histogram.find(currentChar) == histogram.end())
				histogram[currentChar] = 0;
			else histValue = ++histogram[currentChar];
			maxHistogramValue = std::max(maxHistogramValue,histValue);
			
			//std::wcout << "processing \" "<<  QString(currentChar).toStdWString() << " \"... " << std::endl;
			//
			//
			//log_ << "glyphBoundingRect = (" << glyphBoundingRect.x() << "," << glyphBoundingRect.y() <<
			//	"," << glyphBoundingRect.width() << "," << glyphBoundingRect.height()  << ")" << std::endl;
				
				
			QRect screenBoundingRect(										
									posx + posit->x() + glyphBoundingRect.x(),
									posy + posit->y() + glyphBoundingRect.y(),
									glyphBoundingRect.width()+1,
									glyphBoundingRect.height()+1);
				
/*			log_ << "screen layout position = (" << posx << "," << posy <<  ")" << std::endl;
			log_ << "screen glyph position = (" <<  posit->x() << "," << posit->y() << ")" << std::endl;
			
			log_ << "screenBoundingRect = (" << screenBoundingRect.x() << "," << screenBoundingRect.y() <<
				"," << screenBoundingRect.width() << "," << screenBoundingRect.height() << ")" << std::end*/;
			
			QRect  imageBoundingRect(QPoint(	screenBoundingRect.x(),
												pixmap_.height()-1 - screenBoundingRect.y() - screenBoundingRect.height()+1),
									
									QPoint(		screenBoundingRect.x() + screenBoundingRect.width()-1,
												pixmap_.height() - screenBoundingRect.y()-1)
												);

			//log_ << "imageBoundingRect = (" << imageBoundingRect.x() << "," << imageBoundingRect.y() <<
			//	"," << imageBoundingRect.width() << "," << imageBoundingRect.height() << ")" << std::endl;
			
			if(glyphBoundingRect.width()&&glyphBoundingRect.height())
				boxes_.push_back(box(glyphIndicesToChars[*ixIt],imageBoundingRect));
			
			//painter_.setPen(boxPen_);
			painter_.setPen(Qt::green);
			//painter_.drawRect(screenBoundingRect);
				
			++posit;				
		}
}
void BoxBuilder::clearBoxes()
{
	boxes_.clear();
	histogram.clear();
	maxHistogramValue = 0;
}
void BoxBuilder::build(const QTextDocument* doc,const QSize& pixmapSize, const QColor& glyphColor)
{
	pixmap_ = QPixmap(pixmapSize);
	pixmap_.fill(Qt::white);

	glyphPen_ = QPen(glyphColor);
		
	boxes_.clear();
	for(QTextBlock block = doc->begin();block!=doc->end();block=block.next())
	{
		log_ << "BLOCK has started" << std::endl;
		QTextLayout* tl = block.layout();
		QString blockText = block.text();

			
		QList<QGlyphRun> glyphs = tl->glyphRuns();		
		
		int glyphsNum = 0;
		std::for_each(glyphs.begin(),glyphs.end(),[&glyphsNum](QGlyphRun grun)
		{
			glyphsNum += grun.glyphIndexes().size();
		});

		if(glyphsNum != blockText.length())
			log_ << " the number of glyphs in the layout differs with text length, the numbers are: " <<
			glyphsNum << " and " << blockText.length() << std::endl;
		
		glyphPosition_ = tl->position();		
		blockText_ = blockText;
			
		std::for_each(glyphs.begin(),glyphs.end(),[this](const QGlyphRun& grun){handleGlyphRun_(grun);});
	}
}