#include <iostream>
#include <string>
#include <vector>
#include <CL/cl.h>
#include "absl/status/status.h"
#include "opencl_stub.h"

int main() {
  char* driver_version;
  cl_int status_;
  cl_platform_id cpPlatform;
  cl_device_id deviceId;
  cl_uint numPlatforms;
  cl_uint numDevices;

  absl::Status status;
  std::cout << "Loading OpenCL!" << std::endl;
  status = opencl_stub::LoadOpenCL();
  if (!status.ok()) {
    std::cout << status.message();
    return 0;
  }

  std::cout << "OpenCL loaded successfully!" << std::endl;

  status_ = opencl_stub::clGetDeviceInfo(0, CL_DRIVER_VERSION, sizeof(char*), &driver_version, NULL);
  std::cout << status_;
  std::cout << "OpenCL Version: " << driver_version << std::endl;

  opencl_stub::clGetPlatformIDs(1, &cpPlatform, &numPlatforms);
  std::cout << "Number of platforms: " <<  numPlatforms << std::endl;
  
  return 0;
}