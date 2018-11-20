#pragma once
#include "Routes.hpp"
#include "MyBitset.hpp"
#include <bitset>

using MapRoutes = std::map<Subset,
                           Route,
                           compareSubset>;

class TSM
{
public:
    TSM(std::string filename):
        graph(filename),
        numberOfVertices(graph.getVectorSize())
    {
    }
    TSM(std::size_t vertices):
        numberOfVertices(vertices),
        graph(vertices)
    {
    }
    Route findShortestRouteHK(Vertex vertex);
    Route findShortestRouteBF(Vertex vertex);
    Graph graph;
private:
    const std::size_t numberOfVertices;
    Vertex startVertex;
    MapRoutes mapRoutes;
    Routes routes;
    void addVertexToRoutes();
    Route addLastVertexToRoutes();
    void findAllRoutes(Route);
};
