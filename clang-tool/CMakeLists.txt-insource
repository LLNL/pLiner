set(LLVM_LINK_COMPONENTS support)

add_clang_executable(pLiner
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
  utils/json.hpp
)

target_link_libraries(pLiner
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
)
