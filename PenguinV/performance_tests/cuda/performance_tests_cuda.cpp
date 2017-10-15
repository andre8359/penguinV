// This application is designed to run performance tests on penguinV library
#include <iostream>
#include "performance_test_image_function_cuda.h"
#include "../performance_test_framework.h"
#include "../../Library/thirdparty/multicuda/src/cuda_device.cuh"

int main()
{
    // The main purpose of this application is to test everything within library
    // To do this we need an engine (framework) and a bunch of tests

    multiCuda::CudaDeviceManager::instance().initializeDevices();

    // We preallocate memory (32 MB)
    multiCuda::MemoryManager::memory().reserve( 32 * 1024 * 1024 );

    // We create a framework
    Performance_Test::PerformanceTestFramework framework;

    // We add tests
    Performance_Test::addTests_Image_Function_Cuda( framework );

    // Just run the framework what will handle all tests
    framework.run();

    return 0;
}
