#include "myOpenGL.h"

namespace my {
    OpenGL::OpenGL(int width, int height, std::string title) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        // i3wm floating window
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }

    GLFWwindow* OpenGL::cretateWindow(int width, int height, std::string title) {
        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        // TODO handle window == NULL
        glfwSetWindowUserPointer(window, this);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, onResize);

        return window;
    }

    void OpenGL::createProgram() {
        shader.loadShader("resources/vertexShader.txt",   GL_VERTEX_SHADER);
        shader.loadShader("resources/fragmentShader.txt", GL_FRAGMENT_SHADER);
        shader.createProgram();
    }

    void OpenGL::createVertices() {
        vertex.loadVertices();
        vertex.createVAO();
        vertex.createVBO();
        vertex.defineProperties();
    }

    void OpenGL::useProgram() {
        glUseProgram(shader.getProgramID());
    }

    void OpenGL::renderLoop() {
        while (!glfwWindowShouldClose(window)) {
            processInput();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // draw our first triangle
            glBindVertexArray(vertex.getVAO());
            glDrawArrays(GL_TRIANGLES, 0, 3);

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void OpenGL::onResize(int width, int height) {
        glViewport(0, 0, width, height);
    }

    void OpenGL::processInput() {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}
