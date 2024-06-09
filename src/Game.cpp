#include "Game.h"

#include "Application.h"

namespace gol {

    Game::Game() : m_Renderer(Application::GetRenderer()) {
    }

    Game::~Game() {
    }

    void Game::Render() {
        m_Renderer.Clear();
        m_Renderer.RenderCells(m_Cells);
    }

    void Game::Update() {
        // Game update logic
    }

    void Game::RenderUI() {
        // UI rendering logic
    }
}

