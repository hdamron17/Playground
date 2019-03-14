#include <Python.h>

#ifdef CMAKE
#define MODNAME ext1cmake
#else
#define MODNAME ext1
#endif

#define STR(x) #x
#define XSTR(x) STR(x)
#define MODSTR XSTR(MODNAME)

#define MODVAR_0(pre, mname, post) pre ## mname ## post
#define MODVAR_1(pre, mname, post) MODVAR_0(pre, mname, post)
#define MODVAR(pre, post) MODVAR_1(pre, MODNAME, post)
#define MODPRE(pre) MODVAR(pre ## _,)
#define MODPOST(post) MODVAR(, _ ## post)

static PyObject *ExtError;

static PyObject *MODPOST(system) (PyObject *self, PyObject *args) {
    const char *command;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    long sts = system(command);
    if (sts < 0) {
        PyErr_SetString(ExtError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef extMethods[] = {
    { "system",  MODPOST(system), METH_VARARGS, "Execute a shell command." },
    { NULL, NULL, 0, NULL }
};

char ext_doc[] = "Package demoing C extensions";

static struct PyModuleDef extModule = { PyModuleDef_HEAD_INIT, MODSTR, ext_doc, -1, extMethods };

PyMODINIT_FUNC MODPRE(PyInit) (void) {
    PyObject *m = PyModule_Create(&extModule);
    if (m == NULL)
        return NULL;

    ExtError = PyErr_NewException(MODSTR".error", NULL, NULL);
    Py_INCREF(ExtError);
    PyModule_AddObject(m, "error", ExtError);
    return m;
}

