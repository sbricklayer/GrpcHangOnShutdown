#include <GrpcClient2.h>
#include <iostream>

int main()
{

  ExampleService2Accessor& singletonAccessor = ExampleService2Accessor::getInstance();

  std::cout << "This process will never exit completely.\n";
}
