/****************************************************************************
** Meta object code from reading C++ file 'render.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../include/geo/render.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'render.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapDisplayRender_t {
    const uint offsetsAndSize[8];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MapDisplayRender_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MapDisplayRender_t qt_meta_stringdata_MapDisplayRender = {
    {
QT_MOC_LITERAL(0, 16), // "MapDisplayRender"
QT_MOC_LITERAL(17, 4), // "Init"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 5) // "Paint"

    },
    "MapDisplayRender\0Init\0\0Paint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapDisplayRender[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    0 /* Public */,
       3,    0,   27,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MapDisplayRender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapDisplayRender *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Init(); break;
        case 1: _t->Paint(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MapDisplayRender::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_MapDisplayRender.offsetsAndSize,
    qt_meta_data_MapDisplayRender,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MapDisplayRender_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MapDisplayRender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapDisplayRender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapDisplayRender.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MapDisplayRender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
