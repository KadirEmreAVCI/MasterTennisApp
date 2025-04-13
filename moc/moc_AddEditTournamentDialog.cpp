/****************************************************************************
** Meta object code from reading C++ file 'AddEditTournamentDialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/AddEditTournamentDialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddEditTournamentDialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAddEditTournamentDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAddEditTournamentDialogENDCLASS = QtMocHelpers::stringData(
    "AddEditTournamentDialog",
    "on_CancelButton_clicked",
    "",
    "on_SaveButton_clicked",
    "on_comboBox_Type_currentTextChanged",
    "type",
    "on_comboBox_Category_currentTextChanged",
    "category",
    "on_comboBox_Season_currentTextChanged",
    "season",
    "on_comboBox_OrganizationName_currentTextChanged",
    "org",
    "on_comboBox_SetsBestOf_currentTextChanged",
    "setsbestof",
    "UpdateOrganizations",
    "std::vector<Organization>",
    "UpdateActiveProfileData",
    "Profile",
    "p"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddEditTournamentDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    1,   70,    2, 0x08,    3 /* Private */,
       6,    1,   73,    2, 0x08,    5 /* Private */,
       8,    1,   76,    2, 0x08,    7 /* Private */,
      10,    1,   79,    2, 0x08,    9 /* Private */,
      12,    1,   82,    2, 0x08,   11 /* Private */,
      14,    1,   85,    2, 0x0a,   13 /* Public */,
      16,    1,   88,    2, 0x0a,   15 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddEditTournamentDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddEditTournamentDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddEditTournamentDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddEditTournamentDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddEditTournamentDialog, std::true_type>,
        // method 'on_CancelButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SaveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_Type_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_Category_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_Season_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_OrganizationName_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_SetsBestOf_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'UpdateOrganizations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Organization> &, std::false_type>,
        // method 'UpdateActiveProfileData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Profile &, std::false_type>
    >,
    nullptr
} };

void AddEditTournamentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddEditTournamentDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CancelButton_clicked(); break;
        case 1: _t->on_SaveButton_clicked(); break;
        case 2: _t->on_comboBox_Type_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_comboBox_Category_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_comboBox_Season_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_comboBox_OrganizationName_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_comboBox_SetsBestOf_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->UpdateOrganizations((*reinterpret_cast< std::add_pointer_t<std::vector<Organization>>>(_a[1]))); break;
        case 8: _t->UpdateActiveProfileData((*reinterpret_cast< std::add_pointer_t<Profile>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *AddEditTournamentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddEditTournamentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddEditTournamentDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IQTComponent"))
        return static_cast< IQTComponent*>(this);
    if (!strcmp(_clname, "AddEditDialog"))
        return static_cast< AddEditDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddEditTournamentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
