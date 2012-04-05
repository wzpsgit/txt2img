#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextDocument>
#include <QTextBlock>
#include <QTextFragment>
#include <qtextlayout.h>
#include <QList>
#include <QMutex>
#include <QThread>
#include <QCustomEvent>
#include <QPainter>
#include <QTextDocumentFragment>
#include <cmath>

#include <QClipboard>
#include <QFileDialog>

#include <QFile>
#include <QTextStream>
#include <QImageWriter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	log_(std::cout),
    ui(new Ui::MainWindow),
	folder("."),
	pixmapSize(1024,768),
	pixmapBuf(pixmapSize),
	textAlignGroup(this),
	imageScaleFactor(1.),
	boxBuilder(log_)

{
	ui->setupUi(this);
	QApplication::addLibraryPath("./imageformats");
	//ui->label->setPixmap(pixmap);//,Qt::ColorOnly | Qt::ThresholdDither | Qt::ThresholdAlphaDither));	
	ui->scrollArea->widget()->resize(pixmapSize);
	ui->textEdit->setText("text pattern");	
	setupActions();
	//init();
}

void MainWindow::setupActions()
{
	ui->toolBar->insertWidget(ui->action_font,ui->fontComboBox);
	ui->toolBar->insertWidget(ui->action_fontSize,ui->fontSizeComboBox);

	QFontDatabase db;
	foreach(int size,db.standardSizes())
		ui->fontSizeComboBox->addItem(QString::number(size));
	
	textAlignGroup.addAction(ui->action_justify);
	textAlignGroup.addAction(ui->action_left);
	textAlignGroup.addAction(ui->action_right);
	textAlignGroup.addAction(ui->action_center);

	connect(&textAlignGroup,SIGNAL(triggered(QAction*)),this,SLOT(textAlignChanged(QAction*)));

	ui->action_copy->setEnabled(false);
	ui->action_cut->setEnabled(false);

	connect(ui->action_copy,SIGNAL( triggered()),ui->textEdit,SLOT(copy()));
	connect(ui->action_paste,SIGNAL( triggered()),ui->textEdit,SLOT(paste()));
	connect(ui->action_cut,SIGNAL( triggered()),ui->textEdit,SLOT(cut()));

	connect(QApplication::clipboard(),SIGNAL(dataChanged()),this,SLOT(clipboardDataChanged()));
	connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->action_cut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->action_copy, SLOT(setEnabled(bool)));


	
     connect(ui->textEdit->document(), SIGNAL(undoAvailable(bool)),
             ui->action_undo, SLOT(setEnabled(bool)));
     connect(ui->textEdit->document(), SIGNAL(redoAvailable(bool)),
             ui->action_redo, SLOT(setEnabled(bool)));

	 connect(ui->action_undo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
     connect(ui->action_redo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));


	 ui->action_undo->setEnabled(ui->textEdit->document()->isUndoAvailable());
     ui->action_redo->setEnabled(ui->textEdit->document()->isRedoAvailable());  

	 updateOutFilename();

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::scaleImage(double scaleFactor)
{
	//ui->label->resize(scaleFactor*pixmap.size());
	ui->scrollArea->widget()->resize(scaleFactor*pixmapSize);
	pixmapBuf = QPixmap(ui->scrollArea->widget()->size());
	showImage();
	ui->action_zoomin->setEnabled(imageScaleFactor < 4.);
	ui->action_zoomout->setEnabled(imageScaleFactor > .025);
}

void MainWindow::on_fontComboBox_currentFontChanged(const QFont &font)
{
	ui->textEdit->setCurrentFont(font);
	
}
void MainWindow::textBoxFontChanged(const QFont& font)
{
	
	ui->fontComboBox->setCurrentIndex(ui->fontComboBox->findText(QFontInfo(font).family()));
	ui->fontSizeComboBox->setCurrentIndex(ui->fontSizeComboBox->findText(QString::number(font.pointSize())));
	ui->action_bold->setChecked(font.bold());
	ui->action_italic->setChecked(font.italic());
	ui->action_underline->setChecked(font.underline());
	QFont::StyleStrategy ss = font.styleStrategy();
	bool checked = (ss & QFont::PreferAntialias && !(ss & QFont::NoAntialias));
	ui->checkBox->setChecked(checked);	
	updateOutFilename();
}


void MainWindow::on_imgSizeSetButton_clicked()
{
	bool ok;
	int width = ui->imgXEdit->text().toInt(&ok);
	if(!ok) return;
	int height = ui->imgYEdit->text().toInt(&ok);
	if(!ok) return;
	pixmapSize.setWidth(width);
	pixmapSize.setHeight(height);
}

void MainWindow::textBold()
{
	QTextCharFormat format;
	format.setFontWeight(ui->action_bold->isChecked() ? QFont::Bold : QFont::Normal);
	mergeFormatOnWordOrSelection(format);
}

void MainWindow::textItalic()
{
	QTextCharFormat format;
	format.setFontItalic(ui->action_italic->isChecked());
	mergeFormatOnWordOrSelection(format);
}

void MainWindow::textUnderline()
{
	QTextCharFormat format;
	format.setFontUnderline(ui->action_underline->isChecked());
	mergeFormatOnWordOrSelection(format);
}

void MainWindow::textSize(QString size)
{
	bool ok;
	qreal pointSize = size.toFloat(&ok);
	if(ok)
	{
		QTextCharFormat format;
		format.setFontPointSize(pointSize);
		mergeFormatOnWordOrSelection(format);
	}
}

void MainWindow::showImage()
{
	pixmapBuf.fill(Qt::white);
	QPainter painter(&pixmapBuf);
	painter.setPen(Qt::red);
	QPixmap pm = boxBuilder.pixmap().scaled(pixmapBuf.size());
	painter.drawPixmap(0,0,pm);

	const std::list<BoxBuilder::box>& boxes = boxBuilder.boxes();	
	for(std::list<BoxBuilder::box>::const_iterator boxIt = boxes.begin(); boxIt != boxes.end(); ++boxIt)
	{
		double scaleFactor = static_cast<double>(pixmapBuf.size().width())/boxBuilder.pixmap().size().width();
		QRect boundingRect = boxIt->boundingRect;
		QRect scaledRect(	scaleFactor*boundingRect.x(),
							scaleFactor*(boxBuilder.pixmap().height() - boundingRect.y() - boundingRect.height()),
							scaleFactor*boundingRect.width(),
							scaleFactor*boundingRect.height());

		//log_ << "scaledRect = (" << scaledRect.x() << "," << scaledRect.y() <<
		//		"," << scaledRect.width() << "," << scaledRect.height() << ")" << std::endl;
		
		painter.drawRect(scaledRect);
	}
	
	ui->label->setPixmap(pixmapBuf);
}

void MainWindow::on_genImgButton_clicked()
{
	QTextDocument* doc = ui->textEdit->document();	
	boxBuilder.build(doc,pixmapSize);
	showImage();
}

void MainWindow::mergeFormatOnWordOrSelection(const QTextCharFormat& format)
{
	QTextCursor cursor = ui->textEdit->textCursor();
	if(!cursor.hasSelection())
		cursor.select(QTextCursor::WordUnderCursor);
	cursor.mergeCharFormat(format);
	ui->textEdit->mergeCurrentCharFormat(format);
}
void MainWindow::on_textEdit_cursorPositionChanged()
{
	alignmentChanged(ui->textEdit->alignment());
}

void MainWindow::on_textEdit_currentCharFormatChanged(const QTextCharFormat &format)
{
	textBoxFontChanged(format.font());
}
void MainWindow::textAlignChanged(QAction* action)
{
	if (action == ui->action_left)
         ui->textEdit->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
	else if (action == ui->action_center)
         ui->textEdit->setAlignment(Qt::AlignHCenter);
	else if (action == ui->action_right)
         ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
	else if (action == ui->action_justify)
         ui->textEdit->setAlignment(Qt::AlignJustify);
}

void MainWindow::alignmentChanged(Qt::Alignment a)
{
	 if (a & Qt::AlignLeft)
		 ui->action_left->setChecked(true);
     else if (a & Qt::AlignHCenter)
		 ui->action_center->setChecked(true);
     else if (a & Qt::AlignRight)
		 ui->action_right->setChecked(true);
     else if (a & Qt::AlignJustify)
		 ui->action_justify->setChecked(true);     
}


void MainWindow::clipboardDataChanged()
{
	if (const QMimeData *md = QApplication::clipboard()->mimeData())
         ui->action_paste->setEnabled(md->hasText());
}


void MainWindow::zoomin()
{
	imageScaleFactor *= 1.25;
	scaleImage(imageScaleFactor);
	
}

void MainWindow::zoomout()
{
	imageScaleFactor *= 0.75;
	scaleImage(imageScaleFactor);	
}

void MainWindow::cancelZoom()
{
	imageScaleFactor = 1.;
	scaleImage(imageScaleFactor);
}
void MainWindow::on_checkBox_toggled(bool checked)
{
	QFont font = ui->textEdit->currentFont();
	QFont::StyleStrategy ss = font.styleStrategy();	
	if(checked)
	{	
		ss = static_cast<QFont::StyleStrategy>(ss & ~QFont::NoAntialias);		
		ss = static_cast<QFont::StyleStrategy>(ss | QFont::PreferAntialias);	
	}
	else 
	{
		ss = static_cast<QFont::StyleStrategy>(ss & ~QFont::PreferAntialias);
		ss = static_cast<QFont::StyleStrategy>(ss | QFont::NoAntialias);		
	}

	font.setStyleStrategy(ss);	
	ui->textEdit->setCurrentFont(font);
	ui->textEdit->update();
}

void MainWindow::save()
{	
	
	QFile boxLineFormat("./config.txt");
	if(!boxLineFormat.open(QFile::ReadOnly))
		throw std::runtime_error("cannot open box line format config file");
	QString formatLine = boxLineFormat.readLine();


	QFile boxOut(QString(folder + "/" + ui->outFilenameLineEdit->text() + ".box"));
	if(!boxOut.open(QFile::WriteOnly))
		throw std::runtime_error("cannot open box output file for write");

	QTextStream boxStream(&boxOut);
	
	const std::list<BoxBuilder::box>& boxes = boxBuilder.boxes();
	if(!boxBuilder.pixmap().save(folder + "/" + ui->outFilenameLineEdit->text() + ".tif"))
		log_ << "couldn't write image" << std::endl;
	
	QList<QByteArray> formats = QImageWriter::supportedImageFormats();
	logger& logr = log_;
	std::for_each(formats.begin(),formats.end(),[&logr](const QByteArray& f)
	{
		logr << QString(f).toStdString() << std::endl;
	});
	
	std::for_each(boxes.begin(),boxes.end(),[&boxStream,&formatLine](const BoxBuilder::box& b)
	{
		QString left = QString::number(b.boundingRect.left());
		QString top = QString::number(b.boundingRect.top());
		QString right = QString::number(b.boundingRect.right());
		QString bottom = QString::number(b.boundingRect.bottom());

		QString width = QString::number(b.boundingRect.width());
		QString height = QString::number(b.boundingRect.height());
		QString boxOutLine = formatLine;
		
		boxOutLine.replace(QString("$CHAR"),QString(b.character));
		
		boxOutLine.replace(QString("$LEFT"),left);
		boxOutLine.replace(QString("$TOP"),top);

		boxOutLine.replace(QString("$RIGHT"),right);
		boxOutLine.replace(QString("$BOTTOM"),bottom);

		boxOutLine.replace(QString("$WIDTH"),width);
		boxOutLine.replace(QString("$HEIGHT"),height);

		boxStream << boxOutLine << "\n";
	});
	boxOut.close();

}

void MainWindow::updateOutFilename()
{
	ui->outFilenameLineEdit->setText(QString("eng.") + ui->textEdit->currentFont().family() + ".exp0");	
}
void MainWindow::on_selectFolderButton_clicked()
{
	folder = QFileDialog::getExistingDirectory();
	ui->folderLabel_->setText(folder);
}
