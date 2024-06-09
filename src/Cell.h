#pragma once

#include <array>

namespace gol {
    struct Cell {
        int x, y;
    };
    std::array<float, 12> GetVertices(Cell cell, float cell_size);
}
