#include "Application.h"

namespace gol {
    static Application* s_Instance = nullptr;

    Application::Application(const ApplicationSpecification& spec)
        : m_Specification(spec), m_Renderer(spec.Width, spec.Height), m_Window(spec.Width, spec.Height, spec.Title, spec.Icon) {
        s_Instance = this;
        m_Game = std::make_unique<Game>();
    }

    Application::~Application() {
        s_Instance = nullptr;
    }

    Application& Application::Get() {
        return *s_Instance;
    }

    void Application::Loop() {
        Update();
        Render();
    }

    void Application::Update() {
        m_Game->Update();
    }

    void Application::Render() {
        m_Game->Render();
        m_Window.Display();
    }

    void Application::Run() {
        m_Window.Init();
        m_Renderer.Init();

        while (!m_Window.ShouldClose()) {
            Loop();
        }
        
        m_Renderer.End();
    }
}
