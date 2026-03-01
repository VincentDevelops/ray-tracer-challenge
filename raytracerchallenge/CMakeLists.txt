cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("raytracerchallenge")

# C++ standard (RTC-friendly)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
add_library(rtc
  "src/rtc.cpp"
  "src/rtc.h"
  "src/core/tuple.cpp" "src/core/tuple.h" 
  "src/practice/chapter1_projectile.cpp" "src/practice/chapter1_projectile.h" 
  "src/core/color.h" "src/core/color.cpp" 
  "src/core/canvas.cpp" "src/core/canvas.h" 
  "src/practice/chapter2_ppm.h" 
  "src/core/matrix.h" "src/core/matrix.cpp")

add_executable(raytracerchallenge
  "src/raytracerchallenge.cpp" 
  "src/practice/chapter1_projectile.cpp" "src/practice/chapter1_projectile.h" 
  "src/core/color.h" "src/core/color.cpp" 
  "src/core/canvas.cpp" "src/core/canvas.h" 
  "src/practice/chapter2_ppm.h" "src/core/matrix.h" "src/core/matrix.cpp")

target_link_libraries(raytracerchallenge PRIVATE rtc)

find_package(Catch2 CONFIG REQUIRED)

add_executable(rtc_tests
  "tests/tests.cpp"
  "tests/core/tuple.tests.cpp"
  "tests/core/color.tests.cpp"
  "tests/core/canvas.tests.cpp"
  "tests/core/matrix.tests.cpp")

target_link_libraries(rtc_tests PRIVATE rtc Catch2::Catch2WithMain)
target_include_directories(rtc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")