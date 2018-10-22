#include "../include/Graph.hpp"
#include <fstream>
#include <iostream>

bool Graph::loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if(not file.is_open())
        return 0;
    file >> vectorSize;

    structure.reserve(vectorSize);
    for(unsigned x = 0;x < vectorSize;x++)
    {
        std::vector<Vertex> vecVertex;
        vecVertex.reserve(vectorSize);
        for(unsigned y = 0;y < vectorSize;y++)
        {
            Vertex vertex;
            file >> vertex;
            vecVertex.push_back(std::move(vertex));
        }
        structure.push_back(std::move(vecVertex));
    }
    return 1;
}


void Graph::display()
{
    for(const auto& vect : structure)
    {
        for(const auto& vertex : vect)
        {
            std::cout<<vertex<<" ";
        }
        std::cout<<std::endl;
    }
}
