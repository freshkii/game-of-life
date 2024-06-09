#include "Cell.h"

#define CELL_SIZE 2.0f

namespace gol {
    std::array<float, 12> GetVertices(const Cell cell, const float cell_size) {
        float x_left = (float)cell.x * cell_size;
        float x_right = (float)cell.x * cell_size + cell_size;
        float y_top = (float)cell.y * cell_size;
        float y_bot = (float)cell.y * cell_size + cell_size;
        return {
            x_left, y_top, 0.0f, // top left
            x_right, y_top, 0.0f, // top right
            x_left, y_bot, 0.0f, // bottom left
            x_right, y_bot, 0.0f, // bottom right
        };
    }
}
