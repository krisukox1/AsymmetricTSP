#pragma once
#include <vector>
#include <string>
#include <iostream>

using Weight = unsigned;
using Vertex = unsigned;
using VectorSize = std::size_t;

class Graph
{
public:
    friend std::ostream& operator<<(std::ostream&, const Graph&);
    Graph(std::ifstream& file)
    {
        loadFromFile(file);
    }
    Graph(std::size_t numberOfVertices)
    {
        generate(numberOfVertices);
    }
    bool loadFromFile(std::ifstream &);
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
