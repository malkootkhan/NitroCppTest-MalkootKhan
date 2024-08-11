# Project Overview    
This project is a C++ application developed on Ubuntu 22.04 using the Vim editor. The code has been designed to be portable and has been tested on both Linux and Windows environments. It utilizes the CMake build system for easy configuration and compilation, and it automatically manages dependencies like the JSON library (nlohmann/json.hpp) and the GoogleTest framework. C++ standard 17 is used.    

## Build Instructions    
### Linux Build Process    
To build the project on Linux, follow these steps. Ensure you have the necessary tools installed (g++, CMake, make), and that their paths are added to the system's environment variable.   
**1. clone the repository:**     
`git clone <repository_url>`      
`cd <repository_directory>`    

**2. Create a build directory and navigate into it:**    
`mkdir build`     
`cd build`    

**2. Run CMake to configure the project:**     
`cmake ..`     

**3. Compile the project:**     
`make`    

**4. Run Resulting Binary/executable (project_root/bin/RecIntersection):**    
`$(PROJECT_ROOT)/bin/RecIntersection <inputjsonfile.json>`   

**5. Run all test cases:**    
`$(PROJECT_ROOT)/bin/test_rectangle`   or run `ctest` in the test directory: ctest is a tool and part of Cmake used to automate the testing process 

**Notes:**      
The first build may take some time as it will download the required dependencies, including the JSON header and GoogleTest framework.    
Once downloaded, the dependencies are placed in the appropriate directories for subsequent builds.    

### Windows Build Process   
To build the project on Windows, follow these steps. Ensure that you have a C++ compiler (e.g., MinGW), CMake, and make installed, and that their paths are correctly configured in the system's environment variables.     

**1. Clone the repository:**     
`git clone <repository_url>`    
`cd <repository_directory>`     

**2. Create Build Directory and Navigate into it:**    
`mkdir build`     
`cd build`     

**3. Run CMake with the appropriate generator:**      
`cmake -G "MinGW Makefiles" ..`		->The -G flag specifies the build system generator, which in this case is MinGW Makefiles.      

**4. Compile the Project:**      
`make`    

**5. Run Resulting Binary/executable (project_root/bin/RecIntersection):**     
`$(PROJECT_ROOT)/bin/RecIntersection <inputjsonfile.json>`     

**6. Execute all test cases:**     
 `$(PROJECT_ROOT)/bin/test_rectangle`     

**Notes:**     
It is recommended to use Git Bash or a similar terminal emulator if you are not using VS Code or using another IDE that doesn't natively support Unix-style commands.     

## Additional Information      
### Dependencies   
nlohmann/json.hpp: A single-header JSON library for parsing and manipulating JSON data.   
GoogleTest: A C++ testing framework used to write unit tests for the code.   
These dependencies are automatically downloaded and configured during the build process.   

### IDE Compatibility   
Linux: Developed and tested using Vim. It should work with any modern text editor or IDE that supports C++.   
Windows: Tested with VS Code. Ensure that terminal and build tools are properly configured.   

#### Contact     
If you have any questions or need further assistance, feel free to reach out via email at engr.mkhan1990@gmail.com.  




