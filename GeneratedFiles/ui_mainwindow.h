/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 6. Apr 01:45:13 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_bold;
    QAction *action_italic;
    QAction *action_underline;
    QAction *action_font;
    QAction *action_fontSize;
    QAction *action_justify;
    QAction *action_center;
    QAction *action_right;
    QAction *action_left;
    QAction *action_copy;
    QAction *action_cut;
    QAction *action_paste;
    QAction *action_undo;
    QAction *action_redo;
    QAction *action_zoomin;
    QAction *action_zoomout;
    QAction *action_nozoom;
    QAction *action_save;
    QAction *action_letterSpacing;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QPushButton *genImgButton;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *imgYEdit;
    QLabel *label_6;
    QLineEdit *imgXEdit;
    QPushButton *imgSizeSetButton;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *folderLabel_;
    QSplitter *splitter;
    QLineEdit *outFilenameLineEdit;
    QPushButton *selectFolderButton;
    QPushButton *pushButton;
    QComboBox *fontSizeComboBox;
    QFontComboBox *fontComboBox;
    QDoubleSpinBox *letterSpacingSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(732, 386);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        action_bold = new QAction(MainWindow);
        action_bold->setObjectName(QString::fromUtf8("action_bold"));
        action_bold->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/:/images/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_bold->setIcon(icon);
        action_italic = new QAction(MainWindow);
        action_italic->setObjectName(QString::fromUtf8("action_italic"));
        action_italic->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/:/images/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_italic->setIcon(icon1);
        action_underline = new QAction(MainWindow);
        action_underline->setObjectName(QString::fromUtf8("action_underline"));
        action_underline->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/:/images/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_underline->setIcon(icon2);
        action_font = new QAction(MainWindow);
        action_font->setObjectName(QString::fromUtf8("action_font"));
        action_fontSize = new QAction(MainWindow);
        action_fontSize->setObjectName(QString::fromUtf8("action_fontSize"));
        action_justify = new QAction(MainWindow);
        action_justify->setObjectName(QString::fromUtf8("action_justify"));
        action_justify->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/:/images/textjustify.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_justify->setIcon(icon3);
        action_center = new QAction(MainWindow);
        action_center->setObjectName(QString::fromUtf8("action_center"));
        action_center->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/:/images/textcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_center->setIcon(icon4);
        action_right = new QAction(MainWindow);
        action_right->setObjectName(QString::fromUtf8("action_right"));
        action_right->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/:/images/textright.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_right->setIcon(icon5);
        action_left = new QAction(MainWindow);
        action_left->setObjectName(QString::fromUtf8("action_left"));
        action_left->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/:/images/textleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_left->setIcon(icon6);
        action_copy = new QAction(MainWindow);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/:/images/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_copy->setIcon(icon7);
        action_cut = new QAction(MainWindow);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/:/images/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_cut->setIcon(icon8);
        action_paste = new QAction(MainWindow);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/:/images/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_paste->setIcon(icon9);
        action_undo = new QAction(MainWindow);
        action_undo->setObjectName(QString::fromUtf8("action_undo"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/:/images/editundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_undo->setIcon(icon10);
        action_redo = new QAction(MainWindow);
        action_redo->setObjectName(QString::fromUtf8("action_redo"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/:/images/editredo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_redo->setIcon(icon11);
        action_zoomin = new QAction(MainWindow);
        action_zoomin->setObjectName(QString::fromUtf8("action_zoomin"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/:/images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_zoomin->setIcon(icon12);
        action_zoomout = new QAction(MainWindow);
        action_zoomout->setObjectName(QString::fromUtf8("action_zoomout"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/:/images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_zoomout->setIcon(icon13);
        action_nozoom = new QAction(MainWindow);
        action_nozoom->setObjectName(QString::fromUtf8("action_nozoom"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/:/images/nozoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_nozoom->setIcon(icon14);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/:/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon15);
        action_letterSpacing = new QAction(MainWindow);
        action_letterSpacing->setObjectName(QString::fromUtf8("action_letterSpacing"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        genImgButton = new QPushButton(centralWidget);
        genImgButton->setObjectName(QString::fromUtf8("genImgButton"));

        verticalLayout->addWidget(genImgButton);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        imgYEdit = new QLineEdit(centralWidget);
        imgYEdit->setObjectName(QString::fromUtf8("imgYEdit"));
        imgYEdit->setMinimumSize(QSize(50, 0));
        imgYEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(imgYEdit);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        imgXEdit = new QLineEdit(centralWidget);
        imgXEdit->setObjectName(QString::fromUtf8("imgXEdit"));
        imgXEdit->setMinimumSize(QSize(50, 0));
        imgXEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(imgXEdit);

        imgSizeSetButton = new QPushButton(centralWidget);
        imgSizeSetButton->setObjectName(QString::fromUtf8("imgSizeSetButton"));
        imgSizeSetButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(imgSizeSetButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 100, 100));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        folderLabel_ = new QLabel(centralWidget);
        folderLabel_->setObjectName(QString::fromUtf8("folderLabel_"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        folderLabel_->setFont(font);
        folderLabel_->setFrameShape(QFrame::NoFrame);
        folderLabel_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(folderLabel_);


        verticalLayout_4->addLayout(horizontalLayout_4);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        outFilenameLineEdit = new QLineEdit(splitter);
        outFilenameLineEdit->setObjectName(QString::fromUtf8("outFilenameLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outFilenameLineEdit->sizePolicy().hasHeightForWidth());
        outFilenameLineEdit->setSizePolicy(sizePolicy1);
        outFilenameLineEdit->setMinimumSize(QSize(151, 0));
        splitter->addWidget(outFilenameLineEdit);
        selectFolderButton = new QPushButton(splitter);
        selectFolderButton->setObjectName(QString::fromUtf8("selectFolderButton"));
        selectFolderButton->setMaximumSize(QSize(30, 16777215));
        splitter->addWidget(selectFolderButton);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButton);

        verticalLayout_4->addWidget(splitter);


        horizontalLayout_5->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 2);

        fontSizeComboBox = new QComboBox(centralWidget);
        fontSizeComboBox->setObjectName(QString::fromUtf8("fontSizeComboBox"));
        fontSizeComboBox->setEditable(true);

        gridLayout_2->addWidget(fontSizeComboBox, 2, 1, 1, 1);

        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout_2->addWidget(fontComboBox, 2, 0, 1, 1);

        letterSpacingSpinBox = new QDoubleSpinBox(centralWidget);
        letterSpacingSpinBox->setObjectName(QString::fromUtf8("letterSpacingSpinBox"));
        letterSpacingSpinBox->setMinimum(0);
        letterSpacingSpinBox->setMaximum(10);
        letterSpacingSpinBox->setSingleStep(0.1);
        letterSpacingSpinBox->setValue(1);

        gridLayout_2->addWidget(letterSpacingSpinBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 732, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        MainWindow->insertToolBarBreak(toolBar);

        mainToolBar->addAction(action_save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_copy);
        mainToolBar->addAction(action_cut);
        mainToolBar->addAction(action_paste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_undo);
        mainToolBar->addAction(action_redo);
        mainToolBar->addSeparator();
        toolBar->addAction(action_font);
        toolBar->addSeparator();
        toolBar->addAction(action_fontSize);
        toolBar->addSeparator();
        toolBar->addAction(action_letterSpacing);
        toolBar->addSeparator();
        toolBar->addAction(action_bold);
        toolBar->addAction(action_italic);
        toolBar->addAction(action_underline);
        toolBar->addSeparator();
        toolBar->addAction(action_justify);
        toolBar->addAction(action_center);
        toolBar->addAction(action_left);
        toolBar->addAction(action_right);
        toolBar->addSeparator();
        toolBar->addAction(action_zoomin);
        toolBar->addAction(action_zoomout);
        toolBar->addAction(action_nozoom);

        retranslateUi(MainWindow);
        QObject::connect(action_bold, SIGNAL(triggered()), MainWindow, SLOT(textBold()));
        QObject::connect(action_italic, SIGNAL(triggered()), MainWindow, SLOT(textItalic()));
        QObject::connect(action_underline, SIGNAL(triggered()), MainWindow, SLOT(textUnderline()));
        QObject::connect(fontSizeComboBox, SIGNAL(activated(QString)), MainWindow, SLOT(textSize(QString)));
        QObject::connect(action_zoomin, SIGNAL(triggered()), MainWindow, SLOT(zoomin()));
        QObject::connect(action_zoomout, SIGNAL(triggered()), MainWindow, SLOT(zoomout()));
        QObject::connect(action_nozoom, SIGNAL(triggered()), MainWindow, SLOT(cancelZoom()));
        QObject::connect(action_save, SIGNAL(triggered()), MainWindow, SLOT(save()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(save()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "txt2img", 0, QApplication::UnicodeUTF8));
        action_bold->setText(QApplication::translate("MainWindow", "&bold", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_bold->setToolTip(QApplication::translate("MainWindow", "Bold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_bold->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        action_italic->setText(QApplication::translate("MainWindow", "&italic", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_italic->setToolTip(QApplication::translate("MainWindow", "Italic", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_italic->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        action_underline->setText(QApplication::translate("MainWindow", "&underline", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_underline->setToolTip(QApplication::translate("MainWindow", "Underline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_underline->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        action_font->setText(QString());
#ifndef QT_NO_TOOLTIP
        action_font->setToolTip(QApplication::translate("MainWindow", "Font", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_fontSize->setText(QString());
#ifndef QT_NO_TOOLTIP
        action_fontSize->setToolTip(QApplication::translate("MainWindow", "Font size", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_justify->setText(QApplication::translate("MainWindow", "&justify", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_justify->setToolTip(QApplication::translate("MainWindow", "Justify", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_justify->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", 0, QApplication::UnicodeUTF8));
        action_center->setText(QApplication::translate("MainWindow", "c&enter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_center->setToolTip(QApplication::translate("MainWindow", "Align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_center->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        action_right->setText(QApplication::translate("MainWindow", "&right", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_right->setToolTip(QApplication::translate("MainWindow", "Align right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_right->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        action_left->setText(QApplication::translate("MainWindow", "&left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_left->setToolTip(QApplication::translate("MainWindow", "Align left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_left->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        action_copy->setText(QApplication::translate("MainWindow", "&copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_copy->setToolTip(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        action_cut->setText(QApplication::translate("MainWindow", "&cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_cut->setToolTip(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        action_paste->setText(QApplication::translate("MainWindow", "&paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_paste->setToolTip(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_paste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        action_undo->setText(QApplication::translate("MainWindow", "&undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_undo->setToolTip(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_undo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        action_redo->setText(QApplication::translate("MainWindow", "&redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_redo->setToolTip(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_redo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        action_zoomin->setText(QApplication::translate("MainWindow", "&zoomin", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_zoomin->setToolTip(QApplication::translate("MainWindow", "Zoom in", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_zoomin->setShortcut(QApplication::translate("MainWindow", "Ctrl+=, Ctrl+=", 0, QApplication::UnicodeUTF8));
        action_zoomout->setText(QApplication::translate("MainWindow", "&zoomout", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_zoomout->setToolTip(QApplication::translate("MainWindow", "Zoom out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_zoomout->setShortcut(QApplication::translate("MainWindow", "Ctrl+-, Ctrl+-", 0, QApplication::UnicodeUTF8));
        action_nozoom->setText(QApplication::translate("MainWindow", "&nozoom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_nozoom->setToolTip(QApplication::translate("MainWindow", "Cancel zoom", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_save->setText(QApplication::translate("MainWindow", "&save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_save->setToolTip(QApplication::translate("MainWindow", "Save image and box", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_letterSpacing->setText(QString());
#ifndef QT_NO_TOOLTIP
        action_letterSpacing->setToolTip(QApplication::translate("MainWindow", "letter spacing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("MainWindow", "use anti-aliasing", 0, QApplication::UnicodeUTF8));
        genImgButton->setText(QApplication::translate("MainWindow", "Generate image", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Output image", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "width", 0, QApplication::UnicodeUTF8));
        imgYEdit->setInputMask(QApplication::translate("MainWindow", "0000; ", 0, QApplication::UnicodeUTF8));
        imgYEdit->setText(QApplication::translate("MainWindow", "1024", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "height", 0, QApplication::UnicodeUTF8));
        imgXEdit->setInputMask(QApplication::translate("MainWindow", "0000; ", 0, QApplication::UnicodeUTF8));
        imgXEdit->setText(QApplication::translate("MainWindow", "768", 0, QApplication::UnicodeUTF8));
        imgSizeSetButton->setText(QApplication::translate("MainWindow", "set", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "folder:", 0, QApplication::UnicodeUTF8));
        folderLabel_->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        outFilenameLineEdit->setText(QApplication::translate("MainWindow", "type in box & image file name", 0, QApplication::UnicodeUTF8));
        selectFolderButton->setText(QApplication::translate("MainWindow", "..", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "save box  + image", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
