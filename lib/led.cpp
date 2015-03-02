#include "builtin.hpp"
#include "led.hpp"

namespace __led__ {


str *__name__;



/**
class led
*/

class_ *cl_led;

void __init() {
    __name__ = new str("led");

    cl_led = new class_("led");
}

} // module namespace

/* extension module glue */

extern "C" {
#include <Python.h>
#include "led.hpp"
#include <structmember.h>
#include "led.hpp"

PyObject *__ss_mod_led;

namespace __led__ { /* XXX */

/* class led */

typedef struct {
    PyObject_HEAD
    __led__::led *__ss_object;
} __ss_led_ledObject;

static PyMemberDef __ss_led_ledMembers[] = {
    {NULL}
};

static PyNumberMethods __ss_led_led_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

PyObject *__ss_led_led__reduce__(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *__ss_led_led__setstate__(PyObject *self, PyObject *args, PyObject *kwargs);

static PyMethodDef __ss_led_ledMethods[] = {
    {(char *)"__reduce__", (PyCFunction)__ss_led_led__reduce__, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {(char *)"__setstate__", (PyCFunction)__ss_led_led__setstate__, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {NULL}
};

PyObject *__ss_led_ledNew(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    __ss_led_ledObject *self = (__ss_led_ledObject *)type->tp_alloc(type, 0);
    self->__ss_object = new __led__::led();
    self->__ss_object->__class__ = __led__::cl_led;
    __ss_proxy->__setitem__(self->__ss_object, self);
    return (PyObject *)self;
}

void __ss_led_ledDealloc(__ss_led_ledObject *self) {
    self->ob_type->tp_free((PyObject *)self);
    __ss_proxy->__delitem__(self->__ss_object);
}

PyGetSetDef __ss_led_ledGetSet[] = {
    {NULL}
};

PyTypeObject __ss_led_ledObjectType = {
    PyObject_HEAD_INIT(NULL)
    0,              /* ob_size           */
    "led.led",        /* tp_name           */
    sizeof(__ss_led_ledObject), /* tp_basicsize      */
    0,              /* tp_itemsize       */
    (destructor)__ss_led_ledDealloc, /* tp_dealloc        */
    0,              /* tp_print          */
    0,              /* tp_getattr        */
    0,              /* tp_setattr        */
    0,              /* tp_compare        */
    0,              /* tp_repr           */
    &__ss_led_led_as_number,  /* tp_as_number      */
    0,              /* tp_as_sequence    */
    0,              /* tp_as_mapping     */
    0,              /* tp_hash           */
    0,              /* tp_call           */
    0,              /* tp_str            */
    0,              /* tp_getattro       */
    0,              /* tp_setattro       */
    0,              /* tp_as_buffer      */
    Py_TPFLAGS_DEFAULT, /* tp_flags          */
    0,              /* tp_doc            */
    0,              /* tp_traverse       */
    0,              /* tp_clear          */
    0,              /* tp_richcompare    */
    0,              /* tp_weaklistoffset */
    0,              /* tp_iter           */
    0,              /* tp_iternext       */
    __ss_led_ledMethods,      /* tp_methods        */
    __ss_led_ledMembers,      /* tp_members        */
    __ss_led_ledGetSet,       /* tp_getset         */
    0,              /* tp_base           */
    0,              /* tp_dict           */
    0,              /* tp_descr_get      */
    0,              /* tp_descr_set      */
    0,              /* tp_dictoffset     */
    0,              /* tp_init           */
    0,              /* tp_alloc          */
    __ss_led_ledNew,          /* tp_new            */
};

PyObject *__ss_led_led__reduce__(PyObject *self, PyObject *args, PyObject *kwargs) {
    PyObject *t = PyTuple_New(3);
    PyTuple_SetItem(t, 0, PyObject_GetAttrString(__ss_mod_led, "__newobj__"));
    PyObject *a = PyTuple_New(1);
    Py_INCREF((PyObject *)&__ss_led_ledObjectType);
    PyTuple_SetItem(a, 0, (PyObject *)&__ss_led_ledObjectType);
    PyTuple_SetItem(t, 1, a);
    PyObject *b = PyTuple_New(0);
    PyTuple_SetItem(t, 2, b);
    return t;
}

PyObject *__ss_led_led__setstate__(PyObject *self, PyObject *args, PyObject *kwargs) {
    int l = PyTuple_Size(args);
    PyObject *state = PyTuple_GetItem(args, 0);
    Py_INCREF(Py_None);
    return Py_None;
}

} // namespace __led__

namespace __led__ { /* XXX */
static PyNumberMethods Global_led_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

static PyMethodDef Global_ledMethods[] = {
    {(char *)"__newobj__", (PyCFunction)__ss__newobj__, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {NULL}
};

PyMODINIT_FUNC initled(void) {
    __shedskin__::__init();
    __led__::__init();

    __ss_mod_led = Py_InitModule((char *)"led", Global_ledMethods);
    if(!__ss_mod_led)
        return;

    if (PyType_Ready(&__ss_led_ledObjectType) < 0)
        return;

    PyModule_AddObject(__ss_mod_led, "led", (PyObject *)&__ss_led_ledObjectType);

    addled();

}

PyMODINIT_FUNC addled(void) {

}

} // namespace __led__

} // extern "C"
namespace __led__ { /* XXX */

PyObject *led::__to_py__() {
    PyObject *p;
    if(__ss_proxy->has_key(this))
        p = (PyObject *)(__ss_proxy->__getitem__(this));
    else {
        __ss_led_ledObject *self = (__ss_led_ledObject *)(__ss_led_ledObjectType.tp_alloc(&__ss_led_ledObjectType, 0));
        self->__ss_object = this;
        __ss_proxy->__setitem__(self->__ss_object, self);
        p = (PyObject *)self;
    }
    Py_INCREF(p);
    return p;
}

} // module namespace

namespace __shedskin__ { /* XXX */

template<> __led__::led *__to_ss(PyObject *p) {
    if(p == Py_None) return NULL;
    if(PyObject_IsInstance(p, (PyObject *)&__led__::__ss_led_ledObjectType)!=1)
        throw new TypeError(new str("error in conversion to Shed Skin (led expected)"));
    return ((__led__::__ss_led_ledObject *)p)->__ss_object;
}
}
int main(int, char **) {
    __shedskin__::__init();
    __shedskin__::__start(__led__::__init);
}
