/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 5. Apr 15:55:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     151,  144,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     247,  240,   11,   11, 0x08,
     301,   11,   11,   11, 0x08,
     324,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     371,  363,   11,   11, 0x08,
     397,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0f\0on_fontComboBox_currentFontChanged(QFont)\0"
    "on_imgSizeSetButton_clicked()\0textBold()\0"
    "textItalic()\0textUnderline()\0"
    "textSize(QString)\0action\0"
    "textAlignChanged(QAction*)\0"
    "on_genImgButton_clicked()\0"
    "on_textEdit_cursorPositionChanged()\0"
    "format\0on_textEdit_currentCharFormatChanged(QTextCharFormat)\0"
    "clipboardDataChanged()\0zoomin()\0"
    "zoomout()\0cancelZoom()\0save()\0checked\0"
    "on_checkBox_toggled(bool)\0"
    "on_selectFolderButton_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 1: _t->on_imgSizeSetButton_clicked(); break;
        case 2: _t->textBold(); break;
        case 3: _t->textItalic(); break;
        case 4: _t->textUnderline(); break;
        case 5: _t->textSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->textAlignChanged((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->on_genImgButton_clicked(); break;
        case 8: _t->on_textEdit_cursorPositionChanged(); break;
        case 9: _t->on_textEdit_currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 10: _t->clipboardDataChanged(); break;
        case 11: _t->zoomin(); break;
        case 12: _t->zoomout(); break;
        case 13: _t->cancelZoom(); break;
        case 14: _t->save(); break;
        case 15: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_selectFolderButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
