/****************************************************************************
** Meta object code from reading C++ file 'ImageStreamFileReader.h'
**
** Created: Tue Jun 14 12:50:31 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NUView/FileAccess/ImageStreamFileReader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageStreamFileReader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageStreamFileReader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   22,   22,   22, 0x0a,
      70,   22,   22,   22, 0x0a,
      86,   22,   22,   22, 0x0a,
      99,   22,   22,   22, 0x0a,
     123,  111,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageStreamFileReader[] = {
    "ImageStreamFileReader\0\0newData\0"
    "NewDataAvailable(NUImage*)\0nextFrame()\0"
    "previousFrame()\0firstFrame()\0lastFrame()\0"
    "frameNumber\0setFrame(int)\0"
};

const QMetaObject ImageStreamFileReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageStreamFileReader,
      qt_meta_data_ImageStreamFileReader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageStreamFileReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageStreamFileReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageStreamFileReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageStreamFileReader))
        return static_cast<void*>(const_cast< ImageStreamFileReader*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageStreamFileReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: NewDataAvailable((*reinterpret_cast< NUImage*(*)>(_a[1]))); break;
        case 1: nextFrame(); break;
        case 2: previousFrame(); break;
        case 3: firstFrame(); break;
        case 4: lastFrame(); break;
        case 5: setFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ImageStreamFileReader::NewDataAvailable(NUImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE