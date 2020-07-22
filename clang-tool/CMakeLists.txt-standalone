cmake_minimum_required(VERSION 2.8.4)

project(pLiner DESCRIPTION "pLiner" LANGUAGES CXX)

#set(LLVM_PATH /home/huiguo15/home1/clang+llvm)
#link_directories(${LLVM_PATH}/lib)
#include_directories(${LLVM_PATH}/include)

execute_process(COMMAND llvm-config --cxxflags
OUTPUT_VARIABLE MY_LLVM_CXX_FLAGS
OUTPUT_STRIP_TRAILING_WHITESPACE)

add_definitions(
-D_GNU_SOURCE 
-D__STDC_CONSTANT_MACROS 
-D__STDC_FORMAT_MACROS 
-D__STDC_LIMIT_MACROS
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_LLVM_CXX_FLAGS} -fno-rtti")
set(LLVM_LINK_COMPONENTS Support)

add_executable(pLiner
  FPDebugger.cpp
  FPDebugger.h
  analysis/funcAnalysis.cpp
  analysis/funcAnalysis.h
  analysis/funcPrint.cpp
  analysis/funcPrint.h
  transform/funcTrans.cpp
  transform/funcTrans.h
  core/_fp.h
  core/_funcRecord.cpp
  core/_funcRecord.h
  core/_lineRecord.cpp
  core/_lineRecord.h
  json.hpp
)

target_link_libraries(pLiner
  clangTooling 
  clangDriver 
  clangFrontend 
  clangParse 
  clangSerialization 
  clangSema 
  clangAnalysis 
  clangEdit 
  clangLex 
  clangAST 
  clangBasic 
  clangRewrite 
  clangRewriteFrontend 
)

execute_process(COMMAND llvm-config --ldflags 
OUTPUT_VARIABLE MY_LLVM_LINKER_FLAGS1
OUTPUT_STRIP_TRAILING_WHITESPACE)

execute_process(COMMAND llvm-config --libs
OUTPUT_VARIABLE MY_LLVM_LINKER_FLAGS2
OUTPUT_STRIP_TRAILING_WHITESPACE)

set(MY_LLVM_LIBRARY "${MY_LLVM_LINKER_FLAGS1} ${MY_LLVM_LINKER_FLAGS2}")

target_link_libraries(pLiner
  ${MY_LLVM_LIBRARY}
)

include(FindCurses)
target_link_libraries(pLiner
    pthread
    z
    dl
    ${CURSES_LIBRARIES}
)

install(TARGETS pLiner
  DESTINATION bin)
