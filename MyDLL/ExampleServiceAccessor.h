#ifndef GRPCCLIENT1_H
#define GRPCCLIENT1_H

#include <memory>
#include "mydll_export.h"

class MYDLL_EXPORT ExampleServiceAccessor
{
public:
  ExampleServiceAccessor();
  ~ExampleServiceAccessor();
  static ExampleServiceAccessor& getInstance();
  //void callExampleService(); //we could make calls to the gRPC service, but they are not required to demonstrate the infinite block on destruction

private:
  class Impl;
  Impl* pimpl_; //use PIMPL to uncouple consumer from all gRPC dependencies
};

#endif // GRPCCLIENT1_H
