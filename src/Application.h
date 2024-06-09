#pragma once

#include "Renderer.h"
#include "Window.h"
#include "Game.h"

#include <memory>
#include <string>

namespace gol {
    struct ApplicationSpecification {
        int Width = 800;
        int Height = 620;
        std::string Title = "Game of Life";
        std::string Icon = "./assets/img/icon.png";
    };

    class Application {
    public:
        Application(const ApplicationSpecification& spec = ApplicationSpecification());
        ~Application();

        static Application& Get();
        static Renderer& GetRenderer() { return Get().m_Renderer; }

        void Run();
        void Loop();
    private:
        void Render();
        void Update();
    private:
        Renderer m_Renderer;
        ApplicationSpecification m_Specification;
        Window m_Window;
        std::unique_ptr<Game> m_Game;
    };

}
