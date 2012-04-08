#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QThread>
#include <QEvent>
#include <QMutex>
#include <QTextFragment>
#include <QActionGroup>
#include <QFileInfo>

#include "boxbuilder.h"


namespace Ui {
class MainWindow;
}

class TestThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
	
private slots:
    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_imgSizeSetButton_clicked();


	void textBold();
	void textItalic();
	void textUnderline();
	void textSize(QString);

	void textAlignChanged(QAction* action);

    void on_genImgButton_clicked();

    void on_textEdit_cursorPositionChanged();

    void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);
	void clipboardDataChanged();

	void zoomin();
	void zoomout();
	void cancelZoom();

	void saveBoxAndImage();

    void on_checkBox_toggled(bool checked);

    void on_selectFolderButton_clicked();

    void on_letterSpacingSpinBox_valueChanged(double arg1);

	void textOpen();
	void textNew();
	void textSave();
	void textSaveAs();

	void textDocModificationChanged(bool changed);

private:
	logger log_;
    Ui::MainWindow *ui;
	QString folder;
	QActionGroup textAlignGroup;	
	QSize pixmapSize;
	QPixmap pixmapBuf;
	BoxBuilder boxBuilder;

	double imageScaleFactor;
	
	QFileInfo textDocFileInfo;	
	static const unsigned imageDPIs[];
	
	void setupActions();

	void mergeFormatOnWordOrSelection(const QTextCharFormat& format);
	void scaleImage(double scaleFactor);
	
	void showImage();
	
	void textBoxFontChanged(const QFont& font);
	void alignmentChanged(Qt::Alignment a);
	void updateOutFilename();
	QString getWindowTitle() const;
	void updateWindowTitle();

	void saveTextDoc(const QString& fileName);
};




#endif // MAINWINDOW_H
