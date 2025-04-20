/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "fileFound",
    "",
    "path",
    "onBrowseButtonClicked",
    "onAddButtonClicked",
    "onClearLButtonClicked",
    "onDeleteSelectedButtonClicked",
    "onClearRButtonClicked",
    "onOpenFileOnExplorerButtonClicked",
    "onSearchButtonClicked",
    "openFileOnExplorer",
    "QModelIndex",
    "index",
    "onAddTagClicked",
    "onLeftSelectionChanged",
    "QItemSelection",
    "selected",
    "deselected",
    "onRightSelectionChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   89,    2, 0x0a,    3 /* Public */,
       5,    0,   90,    2, 0x0a,    4 /* Public */,
       6,    0,   91,    2, 0x0a,    5 /* Public */,
       7,    0,   92,    2, 0x0a,    6 /* Public */,
       8,    0,   93,    2, 0x0a,    7 /* Public */,
       9,    0,   94,    2, 0x0a,    8 /* Public */,
      10,    0,   95,    2, 0x0a,    9 /* Public */,
      11,    1,   96,    2, 0x0a,   10 /* Public */,
      14,    0,   99,    2, 0x0a,   12 /* Public */,
      15,    2,  100,    2, 0x108,   13 /* Private | MethodIsConst  */,
      19,    2,  105,    2, 0x108,   16 /* Private | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   17,   18,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   17,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'fileFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onBrowseButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClearLButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteSelectedButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClearRButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenFileOnExplorerButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearchButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFileOnExplorer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onAddTagClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLeftSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        // method 'onRightSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->fileFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->onBrowseButtonClicked(); break;
        case 2: _t->onAddButtonClicked(); break;
        case 3: _t->onClearLButtonClicked(); break;
        case 4: _t->onDeleteSelectedButtonClicked(); break;
        case 5: _t->onClearRButtonClicked(); break;
        case 6: _t->onOpenFileOnExplorerButtonClicked(); break;
        case 7: _t->onSearchButtonClicked(); break;
        case 8: _t->openFileOnExplorer((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->onAddTagClicked(); break;
        case 10: _t->onLeftSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 11: _t->onRightSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MainWindow::*)(QString );
            if (_q_method_type _q_method = &MainWindow::fileFound; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::fileFound(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
