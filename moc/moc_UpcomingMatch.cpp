/****************************************************************************
** Meta object code from reading C++ file 'UpcomingMatch.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/UpcomingMatch.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpcomingMatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUpcomingMatchENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUpcomingMatchENDCLASS = QtMocHelpers::stringData(
    "UpcomingMatch",
    "UpcomingMatchStarted",
    "",
    "Tournament",
    "t",
    "Match",
    "m",
    "PrintCountdown",
    "on_UpcomingMatchButton_clicked",
    "MatchStarted"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUpcomingMatchENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   43,    2, 0x08,    4 /* Private */,
       8,    0,   44,    2, 0x08,    5 /* Private */,
       9,    0,   45,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UpcomingMatch::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUpcomingMatchENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUpcomingMatchENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUpcomingMatchENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UpcomingMatch, std::true_type>,
        // method 'UpcomingMatchStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Tournament &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Match &, std::false_type>,
        // method 'PrintCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_UpcomingMatchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MatchStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UpcomingMatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UpcomingMatch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->UpcomingMatchStarted((*reinterpret_cast< std::add_pointer_t<Tournament>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Match>>(_a[2]))); break;
        case 1: _t->PrintCountdown(); break;
        case 2: _t->on_UpcomingMatchButton_clicked(); break;
        case 3: _t->MatchStarted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UpcomingMatch::*)(const Tournament & , const Match & );
            if (_t _q_method = &UpcomingMatch::UpcomingMatchStarted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *UpcomingMatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpcomingMatch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUpcomingMatchENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::UpcomingMatchClass"))
        return static_cast< Ui::UpcomingMatchClass*>(this);
    if (!strcmp(_clname, "IQTComponent"))
        return static_cast< IQTComponent*>(this);
    return QWidget::qt_metacast(_clname);
}

int UpcomingMatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void UpcomingMatch::UpcomingMatchStarted(const Tournament & _t1, const Match & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
