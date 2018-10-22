#include <vector>
#include <string>

using Vertex = unsigned;
using VectorSize = std::size_t;

class Graph
{
public:
    Graph(){}
    bool loadFromFile(const std::string&);
    void display();
private:
    VectorSize vectorSize;
    std::vector<std::vector<Vertex>> structure;
};
