/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../include/geo/map.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapDisplay_t {
    const uint offsetsAndSize[18];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MapDisplay_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MapDisplay_t qt_meta_stringdata_MapDisplay = {
    {
QT_MOC_LITERAL(0, 10), // "MapDisplay"
QT_MOC_LITERAL(11, 11), // "QML.Element"
QT_MOC_LITERAL(23, 4), // "auto"
QT_MOC_LITERAL(28, 4), // "Sync"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 7), // "Cleanup"
QT_MOC_LITERAL(42, 19), // "HandleWindowChanged"
QT_MOC_LITERAL(62, 13), // "QQuickWindow*"
QT_MOC_LITERAL(76, 3) // "win"

    },
    "MapDisplay\0QML.Element\0auto\0Sync\0\0"
    "Cleanup\0HandleWindowChanged\0QQuickWindow*\0"
    "win"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapDisplay[] = {

 // content:
       9,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   34,    4, 0x0a,    0 /* Public */,
       5,    0,   35,    4, 0x0a,    1 /* Public */,
       6,    1,   36,    4, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void MapDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Sync(); break;
        case 1: _t->Cleanup(); break;
        case 2: _t->HandleWindowChanged((*reinterpret_cast< QQuickWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickWindow* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MapDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_MapDisplay.offsetsAndSize,
    qt_meta_data_MapDisplay,
    qt_static_metacall,
    nullptr,
qt_metaTypeArray<

void, void, void, QQuickWindow *


>,
    nullptr
} };


const QMetaObject *MapDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapDisplay.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MapDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
