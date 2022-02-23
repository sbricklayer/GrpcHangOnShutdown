#include <ExampleServiceAccessor.h>
#include <iostream>

int main()
{

  ExampleServiceAccessor& singletonAccessor = ExampleServiceAccessor::getInstance();

  std::cout << "This process will never exit completely.\n";
}
