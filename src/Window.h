#pragma once

#include "Math.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

namespace gol {
    class Window {
    public:
        Window(int width, int height, std::string title, std::string icon = "");
        ~Window();

        void Init();
        void End();

        void Show();
        void Hide();

        void Display();

        bool ShouldClose();
        bool KeyPressed(int key);
        bool MouseButtonPressed(int key);
        Vector2 GetMousePos();

        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }
    private:
        static void ErrorCallback(int error, const char* description);
    private:
        int m_Width;
        int m_Height; 
        std::string m_Title;
        std::string m_Icon;

        GLFWwindow* m_Window;
    };

}
