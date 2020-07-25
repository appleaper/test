去官网下载cmake：https://cmake.org/download/

下载linux版本，然后解压，要是解压之后需要权限就

```
chmod -R 777 cmake-3.14.0
```

要是没有就跳过这个

检查gcc和g++是否安装，要是没有安装就需要

```
sudo apt-get install build-essential
或者：
sudo apt-get install gcc
sudo apt-get install g++
```

cd到cmake解压后的目录。执行

```
sudo ./bootstrap
sudo make
sudo make install
cmake --version
```

要是返回版本信息那么就说明安装成功了！



cmake安装时候出现没有OpenSSL的错误

```
sudo apt-get install libssl-dev
```



pytorch的C++发行版：

我下载的linux的cpu版本的，然后下载后进行解压

创建这样的目录结构

```
example-app/
  CMakeLists.txt
  example-app.cpp
```

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(example-app)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(example-app example-app.cpp)
target_link_libraries(example-app "${TORCH_LIBRARIES}")
set_property(TARGET example-app PROPERTY CXX_STANDARD 14)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)
```

 example-app.cpp

```c++
#include <torch/torch.h>
#include <iostream>

int main() {
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}
```

再执行一下命令

```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch ..
cmake --build . --config Release
```

DCMAKE_PREFIX_PATH需要是libtorch的绝对目录

要是成功的话大概会是这样：

```
appleaper@appleaper-A320M-S2H:~/libtouch/example-app/build$ cmake --build . --config Release
Scanning dependencies of target example-app
[ 50%] Building CXX object CMakeFiles/example-app.dir/example-app.cpp.o
[100%] Linking CXX executable example-app
[100%] Built target example-app
```

最后让example-app的结果打印一下

```
appleaper@appleaper-A320M-S2H:~/libtouch/example-app/build$ ./example-app 
 0.3686  0.5517  0.5257
 0.5098  0.0900  0.9775
[ CPUFloatType{2,3} ]
```



opencv的linux上编译

先下载Opencv，选3x版本的，然后选择源代码进行下载，解压。

```
mkdir build # 创建编译的文件目录
cd build
sudo apt-get install libgtk2.0-dev
sudo apt-get install pkg-config
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j8  #编译
sudo make install #安装
pkg-config --modversion opencv   #查看OpenCV的版本
```

测试：

目录结构：

```
Demo
	-build
	-test
		-1.jpg
	CMakeLists.txt
	main.cpp
```

CMakeLists.txt

```
# cmake needs this line
cmake_minimum_required (VERSION 2.8)
# Define project name
project(TestOpencv)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
set(OpenCV_DIR /home/appleaper/opencv/opencv-3.4.9/build)
find_package(OpenCV 3 REQUIRED)
message(STATUS "Opencv library status: ")
message(STATUS "> version: ${OpenCV_VERSION} ")
message(STATUS "> libraries: ${OpenCV_LIBS}")
message(STATUS "> include: ${OpenCV_INCLUDE_DIRS} ")

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})


# Declare the executable target built from your sources
add_executable(main main.cpp)

# Link your application with OpenCV libraries
target_link_libraries(main ${OpenCV_LIBS})
```

改一下OpenCV_DIR的路径就行

main.cpp

```c++
#include <stdio.h>
#include "opencv2/opencv.hpp"

int main()
{
   cv::Mat image = cv::imread("/home/appleaper/opencv/test/Demo1/test/1.jpg");
    //printf("image.col=%d image.raw=%d \n", image.cols, image.raws);
		if (image.empty()) {
		printf("没有图片");
		return -1;
	}
    cv::imshow("picture",image);
    cv::waitKey(0);
    return 0;

}
```

执行命令：

```
cd build
cmake ..
cmake --build .
./main
```

看到一张图片就对了
