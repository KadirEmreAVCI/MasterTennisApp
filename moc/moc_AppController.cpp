/****************************************************************************
** Meta object code from reading C++ file 'AppController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/AppController.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAppControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAppControllerENDCLASS = QtMocHelpers::stringData(
    "AppController",
    "InitProfiles",
    "",
    "std::vector<Profile>",
    "InitOrganizations",
    "std::vector<Organization>",
    "UserLoggedIn",
    "Profile",
    "UserLoggedOut",
    "ChangeInActiveProfile",
    "ChangeInProfiles",
    "ChangeInOrganizations",
    "OnLogOutButtonClicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAppControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,
       8,    0,   71,    2, 0x06,    7 /* Public */,
       9,    1,   72,    2, 0x06,    8 /* Public */,
      10,    1,   75,    2, 0x06,   10 /* Public */,
      11,    1,   78,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   81,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AppController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAppControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAppControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAppControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AppController, std::true_type>,
        // method 'InitProfiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Profile> &, std::false_type>,
        // method 'InitOrganizations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Organization> &, std::false_type>,
        // method 'UserLoggedIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Profile &, std::false_type>,
        // method 'UserLoggedOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangeInActiveProfile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Profile &, std::false_type>,
        // method 'ChangeInProfiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Profile> &, std::false_type>,
        // method 'ChangeInOrganizations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Organization> &, std::false_type>,
        // method 'OnLogOutButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AppController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->InitProfiles((*reinterpret_cast< std::add_pointer_t<std::vector<Profile>>>(_a[1]))); break;
        case 1: _t->InitOrganizations((*reinterpret_cast< std::add_pointer_t<std::vector<Organization>>>(_a[1]))); break;
        case 2: _t->UserLoggedIn((*reinterpret_cast< std::add_pointer_t<Profile>>(_a[1]))); break;
        case 3: _t->UserLoggedOut(); break;
        case 4: _t->ChangeInActiveProfile((*reinterpret_cast< std::add_pointer_t<Profile>>(_a[1]))); break;
        case 5: _t->ChangeInProfiles((*reinterpret_cast< std::add_pointer_t<std::vector<Profile>>>(_a[1]))); break;
        case 6: _t->ChangeInOrganizations((*reinterpret_cast< std::add_pointer_t<std::vector<Organization>>>(_a[1]))); break;
        case 7: _t->OnLogOutButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppController::*)(const std::vector<Profile> & );
            if (_t _q_method = &AppController::InitProfiles; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppController::*)(const std::vector<Organization> & );
            if (_t _q_method = &AppController::InitOrganizations; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppController::*)(const Profile & );
            if (_t _q_method = &AppController::UserLoggedIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppController::*)();
            if (_t _q_method = &AppController::UserLoggedOut; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AppController::*)(const Profile & );
            if (_t _q_method = &AppController::ChangeInActiveProfile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AppController::*)(const std::vector<Profile> & );
            if (_t _q_method = &AppController::ChangeInProfiles; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AppController::*)(const std::vector<Organization> & );
            if (_t _q_method = &AppController::ChangeInOrganizations; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *AppController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAppControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AppController::InitProfiles(const std::vector<Profile> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppController::InitOrganizations(const std::vector<Organization> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppController::UserLoggedIn(const Profile & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AppController::UserLoggedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AppController::ChangeInActiveProfile(const Profile & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AppController::ChangeInProfiles(const std::vector<Profile> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AppController::ChangeInOrganizations(const std::vector<Organization> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
