#include <Python.h>

static PyMethodDef methods[] = {
  {NULL, NULL},
};

PyMODINIT_FUNC PyInit_cmake_example(void)
{
    static struct PyModuleDef moduledef = {                   
        PyModuleDef_HEAD_INIT, "cmake_example", "", -1, methods,
    }; 

    PyObject *m = PyModule_Create(&moduledef);

    return m;
}

