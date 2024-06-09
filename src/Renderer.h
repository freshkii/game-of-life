#pragma once

#include "Cell.h"
#include "Shader.h"

#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

namespace gol {
    struct RendererSpecification {
        float CellSize = 2;
        float Zoom = 1;
    };
    class Renderer {
    public:
        Renderer(int width, int height, const RendererSpecification& spec = RendererSpecification());
        ~Renderer();

        void Zoom(float zoom);

        void Init();
        void End();

        void Clear();
        void RenderCells(std::vector<Cell> cells);

        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }

        void RenderText();
    private:
        int m_Width = 0;
        int m_Height = 0;
        float m_CellSize;
        float m_Zoom;
    private:
        Shader m_CellShader, m_TextShader;
        unsigned int m_CellVBO;
        unsigned int m_CellVAO;
        unsigned int m_CellEBO;
    };
}
