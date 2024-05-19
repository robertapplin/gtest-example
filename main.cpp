#include <boost/python.hpp>

#include <iostream>
#include <string>

void printStr(const std::string &testStr) {
  std::cout << "BEFORE" <<std::endl;
  std::cout << testStr <<std::endl;
  std::cout << "AFTER" <<std::endl;
}

BOOST_PYTHON_MODULE(my_module) {
  using namespace boost::python;

  def("printStr", printStr);

}
