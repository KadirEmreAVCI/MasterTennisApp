/****************************************************************************
** Meta object code from reading C++ file 'StatController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/StatController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StatController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSStatControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStatControllerENDCLASS = QtMocHelpers::stringData(
    "StatController",
    "CareerStatsUpdated",
    "",
    "uiTotalTournament",
    "uiTotalQualificationFromGroupStages",
    "std::array<WinLoseStat,gTotalCareerStat>",
    "FinalsStatsUpdated",
    "std::array<WinLoseStat,gTotalFinalStat>",
    "UpdateActiveProfileData",
    "Profile"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStatControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   32,    2, 0x06,    1 /* Public */,
       6,    1,   39,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   42,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 5,    3,    4,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject StatController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSStatControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStatControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStatControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StatController, std::true_type>,
        // method 'CareerStatsUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned , std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned , std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::array<WinLoseStat,gTotalCareerStat> &, std::false_type>,
        // method 'FinalsStatsUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::array<WinLoseStat,gTotalFinalStat> &, std::false_type>,
        // method 'UpdateActiveProfileData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Profile &, std::false_type>
    >,
    nullptr
} };

void StatController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StatController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->CareerStatsUpdated((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::array<WinLoseStat,gTotalCareerStat>>>(_a[3]))); break;
        case 1: _t->FinalsStatsUpdated((*reinterpret_cast< std::add_pointer_t<std::array<WinLoseStat,gTotalFinalStat>>>(_a[1]))); break;
        case 2: _t->UpdateActiveProfileData((*reinterpret_cast< std::add_pointer_t<Profile>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StatController::*)(unsigned  , unsigned  , const std::array<WinLoseStat,gTotalCareerStat> & );
            if (_t _q_method = &StatController::CareerStatsUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StatController::*)(const std::array<WinLoseStat,gTotalFinalStat> & );
            if (_t _q_method = &StatController::FinalsStatsUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *StatController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStatControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StatController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void StatController::CareerStatsUpdated(unsigned  _t1, unsigned  _t2, const std::array<WinLoseStat,gTotalCareerStat> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StatController::FinalsStatsUpdated(const std::array<WinLoseStat,gTotalFinalStat> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
