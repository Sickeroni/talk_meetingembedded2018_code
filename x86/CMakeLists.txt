cmake_minimum_required(VERSION 3.9)
project(how_to_mock_code_x86)



set(CMAKE_CXX_STANDARD 17)



# define Optimization based on build type
IF(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    SET(CUSTOM_COMPILE_FLAGS "${CUSTOM_COMPILE_FLAGS} -Os -flto")
ELSE(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    SET(CUSTOM_COMPILE_FLAGS "${CUSTOM_COMPILE_FLAGS} -O3 -g3 -flto")
ENDIF(NOT CMAKE_BUILD_TYPE MATCHES Debug)



add_executable(console_ledpanel console_ledpanel.cpp)


SET(PROJECT_DEPENDENCY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")
file(GLOB kvasir_RESULT "${PROJECT_DEPENDENCY_DIR}/Kvasir*")
list(LENGTH kvasir_RESULT kvasir_RES_LEN)
if(kvasir_RES_LEN EQUAL 0)
    message( SEND_ERROR "Kvasir is missing.
Please download from
https://github.com/kvasir-io/kvasir
More Infos @README.MD")
endif(kvasir_RES_LEN EQUAL 0)


include_directories(${PROJECT_DEPENDENCY_DIR}/Kvasir/Lib)
add_executable(pin_toggle_local_kvasir pin_toggle_local_kvasir.cpp)



SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost REQUIRED COMPONENTS system thread regex)
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

add_executable(sfr_wrapper_proof SFR_wrapper_proof.cpp)
TARGET_LINK_LIBRARIES(sfr_wrapper_proof ${Boost_INCLUDE_DIRS} ${USED_LIBS})

#include_directories(${PROJECT_DEPENDENCY_DIR}/Kvasir/Lib)
add_executable(real_ledpanel real_ledpanel.cpp)
TARGET_LINK_LIBRARIES(real_ledpanel ${USED_LIBS})