#include <grpc++/create_channel.h>
#include "ExampleServiceAccessor.h"

class ExampleServiceAccessor::Impl
{

public:
  Impl()
  {
    channel_ptr_ = CreateChannel("localhost:12010",grpc::InsecureChannelCredentials());
  }

private:
  std::shared_ptr<grpc::Channel> channel_ptr_;
  //This class would usually hold a unique_ptr to a gRPC client (stub)
  //and the same behavior is observed in that case, but it turns out
  //that the channel object is actually sufficient to trigger the issue.
};

ExampleServiceAccessor::ExampleServiceAccessor() : pimpl_(new Impl())
{
}

ExampleServiceAccessor::~ExampleServiceAccessor()
{
  delete pimpl_;
  std::cout << "Destructor ~ExampleService2Accessor\n";
}

ExampleServiceAccessor& ExampleServiceAccessor::getInstance()
{
  static ExampleServiceAccessor instance;
  return instance;
}
