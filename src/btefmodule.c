#include <Python.h>

static PyObject *
set_encoding(PyObject *self, PyObject *args, PyObject *kwds)
{
    const char *encoding = "utf-8";
    static char *kwlist[] = {"file", "encoding", 0};
    PyObject *f;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O|s:set_encoding", kwlist, &f, &encoding)) {
        return NULL;
    }
    if (!PyFile_Check(f)) {
        PyErr_SetString(PyExc_TypeError,
                        "btef.set_encoding() 1st arg must be a file");
        return NULL;
    }
    PyFile_SetEncoding(f, encoding);
    Py_INCREF(Py_None);
    return Py_None;
}

PyDoc_STRVAR(set_encoding_doc,
"set_encoding(file, encoding='utf-8')\n\
\n\
set the encoding attribute of a file object.");

static PyMethodDef BtefMethods[] = {
    {"set_encoding",  (PyCFunction)set_encoding, METH_VARARGS | METH_KEYWORDS , set_encoding_doc},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyDoc_STRVAR(btef_module_doc,
"module for extending file object.");

PyMODINIT_FUNC
initbtef(void)
{
    (void) Py_InitModule3("btef", BtefMethods, btef_module_doc);
}
