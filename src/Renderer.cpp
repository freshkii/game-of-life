#include "Renderer.h"
#include "Cell.h"

#include <glad/glad.h>

#include <iostream>
#include <array>

namespace gol { 

    Renderer::Renderer(int width, int height, const RendererSpecification& spec) 
        : m_Width(width), m_Height(height), m_CellSize(spec.CellSize), m_Zoom(spec.Zoom)  {
    }

    Renderer::~Renderer() {
    }

    void Renderer::Init() {
        if (!gladLoadGL()) {
            std::cerr << "GLAD: error while loading glad" << std::endl; 
        } else {
            std::cout << "GLAD: loaded" << std::endl;
        }

        glViewport(0, 0, m_Width, m_Height);
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        m_CellShader = Shader("./res/shaders/cell.vs", "./res/shaders/cell.fs");
        m_TextShader = Shader("./res/shaders/text.vs", "./res/shaders/text.fs");

        glGenBuffers(1, &m_CellVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_CellVBO);
        glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
    }

    void Renderer::End() {
        glDeleteBuffers(1, &m_CellVBO);
    }

    void Renderer::Clear() {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }

    void Renderer::Zoom(float zoom) {
        m_Zoom = zoom;
    }

    void Renderer::RenderCells(std::vector<Cell> cells) {
        std::vector<float> vertices;
        std::vector<int> indices;
        int i = 0;

        for (auto& cell: cells) {
            std::array<float, 12> tmp_vertices = GetVertices(cell, m_CellSize);
            std::array<int, 6> tmp_indices = {
                0 + 4 * i, 1 + 4 * i, 2 + 4 * i,
                0 + 4 * i, 2 + 4 * i, 3 + 4 * i
            };
            vertices.insert(vertices.end(), tmp_vertices.begin(), tmp_vertices.end());
            indices.insert(indices.end(), tmp_indices.begin(), tmp_indices.end());
            i++;
        }

        glBindBuffer(GL_ARRAY_BUFFER, m_CellVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertices.size() * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        m_CellShader.Use();
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    }
}
