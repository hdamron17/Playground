#include <Python.h>

static PyObject *ExtError;

static PyObject *ext_system(PyObject *self, PyObject *args) {
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
    { "system",  ext_system, METH_VARARGS, "Execute a shell command." },
    { NULL, NULL, 0, NULL }
};

char ext_doc[] = "Package demoing C extensions";

static struct PyModuleDef extModule = { PyModuleDef_HEAD_INIT, "basic_ext", ext_doc, -1, extMethods };

PyMODINIT_FUNC PyInit_basic_ext (void) {
    PyObject *m = PyModule_Create(&extModule);
    if (m == NULL)
        return NULL;

    ExtError = PyErr_NewException("basic_ext.error", NULL, NULL);
    Py_INCREF(ExtError);
    PyModule_AddObject(m, "error", ExtError);
    return m;
}

