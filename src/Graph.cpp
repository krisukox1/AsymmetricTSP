#include "../include/Graph.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

bool Graph::loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if(not file.is_open())
        return 0;
    file >> vectorSize;

    structure.reserve(vectorSize);
    for(unsigned x = 0;x < vectorSize;x++)
    {
        std::vector<Weight> vecWeight;
        vecWeight.reserve(vectorSize);
        for(unsigned y = 0;y < vectorSize;y++)
        {
            Weight weight;
            int tmp;
            file >> tmp;
            if(tmp > 0)
                weight = static_cast<unsigned>(tmp);
            else
                weight = 0;
            vecWeight.push_back(std::move(weight));
        }
        structure.push_back(std::move(vecWeight));
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

Weight Graph::getWeight(Vertex beginVertex, Vertex endVertex) const
{
    if(beginVertex == endVertex)
        throw std::invalid_argument("getWeight - "
                                    "vertices can't be the same");
    return structure[beginVertex][endVertex];
}

VectorSize Graph::getVectorSize() const
{
    return vectorSize;
}

void Graph::generate(std::size_t numberOfVertices)
{
    for(int x = 0;x < numberOfVertices;x++)
    {
        std::vector<Weight> weights;
        for(int y = 0;y < numberOfVertices;y++)
        {
            if(x == y)
                weights.push_back(0);
            else
                weights.push_back(rand()%50 + 1);
        }
        structure.push_back(std::move(weights));
    }
}
