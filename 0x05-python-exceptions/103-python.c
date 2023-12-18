#include <Python.h>
#include <stdio.h>
/**
 * print_python_float - gives data of the PyFloatObject
 * @p: the PyObject
 */
void print_python_float(PyObject *p)
{
	double fvalue = 0;
	char *fstring = NULL;

	fflush(stdout);
	printf("[.] float object info\n");

	if (!PyFloat_CheckExact(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	fvalue = ((PyFloatObject *)p)->ob_fval;
	fstring = PyOS_double_to_string(fvalue, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", fstring);
}
/**
 * print_python_bytes - gives data of the PyBytesObject
 * @p: the PyObject
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t fsize = 0, f = 0;
	char *fstring = NULL;

	fflush(stdout);
	printf("[.] bytes object info\n");
	if (!PyBytes_CheckExact(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	fsize = PyBytes_Size(p);
	printf("  size: %zd\n", fsize);
	fstring = (assert(PyBytes_Check(p)), (((PyBytesObject *)(p))->ob_sval));
	printf("  trying string: %s\n", fstring);
	printf("  first %zd bytes:", fsize < 10 ? fsize + 1 : 10);
	while (f < fsize + 1 && f < 10)
	{
		printf(" %02hhx", fstring[f]);
		f++;
	}
	printf("\n");
}
/**
 * print_python_list - gives data of the PyListObject
 * @p: the PyObject
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t fsize = 0;
	PyObject *fitem;
	int f = 0;

	fflush(stdout);
	printf("[*] Python list info\n");
	if (PyList_CheckExact(p))
	{
		fsize = PyList_GET_SIZE(p);
		printf("[*] Size of the Python List = %zd\n", fsize);
		printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
		while (f < fsize)
		{
			fitem = PyList_GET_ITEM(p, f);
			printf("Element %d: %s\n", f, fitem->ob_type->tp_name);
			if (PyBytes_Check(fitem))
				print_python_bytes(fitem);
			else if (PyFloat_Check(fitem))
				print_python_float(fitem);
			f++;
		}
	}
	else
		printf("  [ERROR] Invalid List Object\n");
}
