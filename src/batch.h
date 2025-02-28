/*
    batch.h -- command line interface to Instant Meshes

    This file is part of the implementation of

        Instant Field-Aligned Meshes
        Wenzel Jakob, Daniele Panozzo, Marco Tarini, and Olga Sorkine-Hornung
        In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2015)

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

#include "common.h"

namespace stitchMeshing {
extern void batch_process(const std::string &input, const std::string &output,
                          Float scale, bool flip,
                          std::vector<std::vector<int>> &faces,
                          std::vector<std::vector<float>> &verts);
}
