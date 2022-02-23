#include <grpc++/create_channel.h>
#include "GrpcClient2.h"

class ExampleService2Accessor::Impl
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

ExampleService2Accessor::ExampleService2Accessor() : pimpl_(new Impl())
{
}

ExampleService2Accessor::~ExampleService2Accessor()
{
  delete pimpl_;
  std::cout << "Destructor ~ExampleService2Accessor\n";
}

ExampleService2Accessor& ExampleService2Accessor::getInstance()
{
  static ExampleService2Accessor instance;
  return instance;
}
