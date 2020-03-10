#ifndef _MYSHADER_H_
#define _MYSHADER_H_

#include <string>
#include <map>

namespace my {
class Shader {
    public:
        Shader();
        void loadShader(std::string filename, unsigned int program);
        void createProgram();
        unsigned int getProgramID() {
            return programID;
        }
    private:
        std::string loadFile(std::string filename);
        unsigned int programID;
        std::map<unsigned int, std::string> messages;
        std::map<unsigned int, unsigned int> shaderIDs;
};
}

#endif // _MYSHADER_H_
