#ifndef __LED_HPP
#define __LED_HPP

using namespace __shedskin__;
namespace __led__ {

class led;


extern str *__name__;


extern class_ *cl_led;
class led : public pyobj {
public:
    led() { this->__class__ = cl_led; }
    virtual PyObject *__to_py__();
};


extern "C" {
PyMODINIT_FUNC initled(void);

PyMODINIT_FUNC addled(void);

}
} // module namespace
extern PyTypeObject __ss_led_ledObjectType;
namespace __shedskin__ { /* XXX */

template<> __led__::led *__to_ss(PyObject *p);
}
#endif
