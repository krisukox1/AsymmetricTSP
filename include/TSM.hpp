#pragma once
#include "Routes.hpp"
#include "Subset.hpp"
#include <bitset>
#include <map>
#include <unordered_map>

using MapRoutes = std::unordered_map<Subset,
                                     Route,
                                     SubsetHasher>;

class TSM
{
public:
    TSM(std::ifstream& file):
        graph(file),
        numberOfVertices(graph.getVectorSize()){}
    TSM(std::size_t vertices):
        numberOfVertices(vertices),
        graph(vertices){}

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
