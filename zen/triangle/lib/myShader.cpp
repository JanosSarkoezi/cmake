#include "myShader.h"
#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

namespace my {
    Shader::Shader() {
        messages[GL_VERTEX_SHADER] = "ERROR::SHADER::VERTEX::COMPILATION_FAILED";
        messages[GL_FRAGMENT_SHADER] = "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED";
    }
    
    void Shader::loadShader(std::string fileName, unsigned int program) {
        std::string shaderCode = loadFile(fileName);
        const char* vs = shaderCode.c_str();

        unsigned int shaderID = glCreateShader(program);
        shaderIDs[program] = shaderID;
        glShaderSource(shaderID, 1, &vs, NULL);
        glCompileShader(shaderID);

        int  success;
        char infoLog[512];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
            std::cout << messages[program] << std::endl << infoLog << std::endl;
        }
    }

    void Shader::createProgram() {
        programID = glCreateProgram();

        for (const auto& s : shaderIDs) {
            glAttachShader(programID, s.second);
        }

        glLinkProgram(programID);
    }

    std::string Shader::loadFile(std::string fileName) {
        std::ifstream input(fileName);
        std::stringstream sstr;

        while(input >> sstr.rdbuf());

        return sstr.str();
    }
}
