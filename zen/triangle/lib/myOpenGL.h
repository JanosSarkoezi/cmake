#ifndef _MYOPENGL_H_
#define _MYOPENGL_H_

#include "myShader.h"
#include "myVertex.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace my {
class OpenGL {
    public:
        OpenGL(int width, int height, std::string title);
        GLFWwindow* cretateWindow(int width, int height, std::string title);
        void onResize(int width, int height);
        void createProgram();
        void createVertices();
        void processInput();
        void renderLoop();
        void useProgram();
    private:
        GLFWwindow* window;
        Shader shader;
        Vertex vertex;

        // Für die Benutzung als callback-Funktion.
        static void onResize(GLFWwindow* window, int width, int height) {
            my::OpenGL* obj = (my::OpenGL*) glfwGetWindowUserPointer(window);
            obj->onResize(width, height);
        }
};
}

#endif // _MYOPENGL_H_
