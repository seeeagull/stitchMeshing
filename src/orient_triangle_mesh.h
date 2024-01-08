#pragma once
#include "common.h"
#include <map>
#include <set>
#include <queue>
using namespace std;
namespace stitchMeshing {
extern void orient_triangle_mesh_index(MatrixXf &Vs, MatrixXu &Ts);
}