#pragma once

#include "Renderer.h"

#include <vector>

namespace gol {
    class Game {
    public:
        Game();
        ~Game();

        void Update();

        void Render();
        void RenderUI();
    private:
        Renderer& m_Renderer;
        std::vector<Cell> m_Cells = {
            {10, 10}, {11, 10}, {12,10},
            {10, 11},
            {10, 12},
                      {11, 13}
        };
    };
} 
