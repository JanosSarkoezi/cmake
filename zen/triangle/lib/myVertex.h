#ifndef _MYVERTEX_H_
#define _MYVERTEX_H_

#include <vector>

namespace my {
class Vertex {
    public:
        void loadVertices();
        void createVAO();
        void createVBO();
        void defineProperties();

        unsigned int getVAO() {
            return VAO;
        }
    private:
        unsigned int VAO;
        unsigned int VBO;
        std::vector<float> vertices;
};
}

#endif // _MYVERTEX_H_
