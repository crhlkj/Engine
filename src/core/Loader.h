#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderLoader {
public:
    static std::string LoadShaderFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error " << filePath << std::endl;
            return "";
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};