#include "Window.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>

#define MOUSE_LEFT_BUTTON GLFW_MOUSE_BUTTON_LEFT
#define MOUSE_RIGHT_BUTTON GLFW_MOUSE_BUTTON_LEFT

namespace gol {

    Window::Window(int width, int height, std::string title, std::string icon) 
        : m_Width(width), m_Height(height), m_Title(title),  m_Icon(icon) {
    } 

    Window::~Window() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::ErrorCallback(int error, const char* description) {
        fprintf(stderr, "Error: %s\n", description);
    }
    
    void Window::Init() {
        glfwSetErrorCallback(ErrorCallback);

        // GLFW setup
        if (!glfwInit()) {
            std::cerr << "GLFW: error while init" << std::endl;
            exit(1); 
        } else {
            std::cout << "GLFW: initialized" << std::endl;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
        if (!m_Window) {
            std::cerr << "GLFW: error while creating window" << std::endl;
            glfwTerminate();
            exit(1);
        } else {
            std::cout << "GLFW: window created" << std::endl;
        }

        // load icon 
        if (m_Icon.c_str() && std::fstream(m_Icon.c_str()).good()) {
            int width, height, channels;

            unsigned char* data = stbi_load(m_Icon.c_str(), &width, &width, &channels, 4);
            if (data) {
                GLFWimage icon;
                icon.width = width;
                icon.height = height;
                icon.pixels = data;
            } else {
                std::cerr << "STBI: error while loading icon - " << m_Icon << std::endl;
            }

            stbi_image_free(data);
        }
        Show();
    }

    void Window::Show() {
        glfwMakeContextCurrent(m_Window);
        glfwShowWindow(m_Window);
    }

    void Window::Hide() {
        glfwMakeContextCurrent(0);
    }

    void Window::Display() {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }


    bool Window::ShouldClose() {
        return glfwWindowShouldClose(m_Window) || KeyPressed(GLFW_KEY_ESCAPE);
    }

    bool Window::KeyPressed(int key) {
        return glfwGetKey(m_Window, key) == GLFW_PRESS;
    }

    bool Window::MouseButtonPressed(int key) {
        return glfwGetMouseButton(m_Window, key) == GLFW_PRESS;
    }

    Vector2 Window::GetMousePos() {
        double x, y;
        glfwGetCursorPos(m_Window, &x, &y);

        return Vector2(x,y);
    }
}
