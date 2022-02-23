# GrpcInDLLsIssues

This repository is supposed to document an issue that was posted in the gRPC github project.

### Infinite block on shutdown using singleton to access gRPC service
A DLL provides a singleton of a class that wraps the gRPC service client (using the PIMPL idiom). The executable gets an instance of the singleton (actually nothing happens beyond instantiation of a channel object) and the process blocks indefinitely on shutdown. Although we use DLLs here, (static) gRPC libs are only linked into this one DLL, so no duplicate static gRPC data).
The result seems to be flaky: If the environment variables GRPC_VERBOSITY=debug and GRPC_TRACE=all are set to enable debugging, the process ends without issues.

## Build
The project as well as gRCP were built with Visual Studio 2019.

### Build gRPC
To build gRPC, these were the steps that were used
#### Clone gRPC repo including submodules
```
git clone https://github.com/grpc/grpc
cd grpc
git submodule update --init
```

#### Build gRPC using cmake with Visual Studio 2019 and limited to the required components
The following will install gRPC in the folder `c:\temp\grpc` (last parameter in the long config command) which is also used in the cmake file of this repo. Feel free to change it at both locations. 
```
md .build
cd .build
cmake .. -G "Visual Studio 16 2019" -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF -DABSL_ENABLE_INSTALL=ON -DCMAKE_INSTALL_PREFIX="c:/temp/grpc"
cmake --build . --config Release
cmake --install .
```

### Build this repo and run the example
After successful build and install of gRPC as described above, you can build this repository.
* Clone this repository
* Open the folder in Visual Studio 2019
* Generate the cmake cache
* Build
* Run the target _InfiniteBlockExample.exe (Install)_
