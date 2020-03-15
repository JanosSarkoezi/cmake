#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include <iostream>                     // std:cout

#include "myOpenGL.h"


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    my::OpenGL myOpenGL(800, 600, "LearnOpenGL");
    myOpenGL.cretateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    myOpenGL.createProgram();
    myOpenGL.createVertices();
    myOpenGL.useProgram();
    myOpenGL.renderLoop();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
