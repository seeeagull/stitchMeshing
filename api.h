#pragma once

#include <vector>

#ifndef EXPORT
#  if defined(_MSC_VER) || defined(__CYGWIN__)
#    ifdef StitchMeshing_EXPORT
#      define EXPORT __declspec(dllexport)
#    else
#      define EXPORT __declspec(dllimport)
#    endif
#  elif defined(__clang__) || defined(__GNUC__)
#    define EXPORT __attribute__((visibility("default")))
#  endif
#endif


EXPORT int runStitchMeshing(std::vector<std::vector<int>> &faces,
                            std::vector<std::vector<float>> &verts,
                            int argc, char **argv);
