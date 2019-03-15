#include <boost/python.hpp>

BOOST_PYTHON_MODULE(boost_ext) {
    Py_Initialize();
    using namespace boost::python;
    def("system", system);
}
