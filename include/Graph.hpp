#pragma once
#include <vector>
#include <string>
#include <iostream>

using Weight = unsigned;
using Vertex = std::size_t;
using VectorSize = std::size_t;

class Graph
{
public:
    friend std::ostream& operator<<(std::ostream&, const Graph&);
    Graph(const std::string& filename)
    {
        loadFromFile(filename);
    }
    Graph(std::size_t numberOfVertices)
    {
        generate(numberOfVertices);
    }
    bool loadFromFile(const std::string&);
    void display();
    Weight getWeight(Vertex beginVertex, Vertex endVertex) const;
    VectorSize getVectorSize() const;
private:
    VectorSize vectorSize;
    std::vector<std::vector<Weight>> structure;
    void generate(std::size_t numberOfVertices);
};

inline std::ostream& operator<<(std::ostream& oStreamObj, const Graph& graph)
{
    for(auto weights : graph.structure)
    {
        for(auto weight : weights)
            std::cout<<weight<<" ";
        std::cout<<std::endl;
    }
    return oStreamObj;
}
