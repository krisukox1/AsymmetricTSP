#include "../include/TSM.hpp"
#include <iostream>
#include <map>

namespace
{
void displayMap(MapRoutes map)
{
    for(const auto& mapElement : map)
    {
        const auto bitsetSize = mapElement.first.bitset.size();
        for(unsigned i = 0;i < bitsetSize;i++)
            std::cout<<mapElement.first.bitset[i]<<" ";
        std::cout<<"last - "<<mapElement.first.lastVertex;
        std::cout<<std::endl<<mapElement.second<<std::endl;
    }
}
}

Route TSM::findShortestRouteHK(Vertex vertex)
{
    startVertex = vertex;

    mapRoutes = MapRoutes();

    std::bitset<20> initBitset;
    initBitset[startVertex] = true;

    Route initRoute{{startVertex},0};

    mapRoutes[Subset{initBitset,startVertex}] = initRoute;
    for(unsigned i = 0;i < numberOfVertices-1;i++)
        addVertexToRoutes();
    return addLastVertexToRoutes();
}

void TSM::addVertexToRoutes()
{
    MapRoutes newMap;
    for(const auto& element : mapRoutes)
    {
        const std::bitset<20>& bitset = element.first.bitset;
        for(Vertex vertex = 0;vertex < numberOfVertices;vertex++)
        {
            if(bitset[vertex])
                continue;
            auto newBitset = bitset;
            newBitset[vertex] = true;
            if(newMap.find({newBitset, vertex}) != newMap.end() &&
                    newMap[Subset{newBitset, vertex}].routeWeight <= element.second.routeWeight + graph.getWeight(element.second.inRoute.back(),vertex))
                continue;
            Route route = element.second;
            route.routeWeight = route.routeWeight + graph.getWeight(route.inRoute.back(),vertex);
            route.inRoute.push_back(vertex);
            newMap[Subset{newBitset,vertex}] = route;
        }
    }
    mapRoutes = newMap;
}

Route TSM::addLastVertexToRoutes()
{
    Route shortestRoute{};
    for(auto& element : mapRoutes)
    {
        element.second.routeWeight += graph.getWeight(element.first.lastVertex,startVertex);
        element.second.inRoute.push_back(startVertex);
        if(shortestRoute.routeWeight > element.second.routeWeight)
            shortestRoute = element.second;
    }
    return shortestRoute;
}

Route TSM::findShortestRouteBF(Vertex vertex)
{
    routes = Routes{};
    startVertex = vertex;
    Route route({startVertex},0);
    findAllRoutes(route);
    Route shortestRoute{};
    for(Route route : routes)
    {
        if(route.routeWeight < shortestRoute.routeWeight)
            shortestRoute = route;
    }
    return shortestRoute;
}

void TSM::findAllRoutes(Route route)
{
    if(route.inRoute.size() >= numberOfVertices)
    {
        route.routeWeight += graph.getWeight(route.inRoute.back(),startVertex);
        route.inRoute.push_back(startVertex);
        routes.push_back(route);
        return;
    }
    for(unsigned i = 0;i < numberOfVertices;i++)
    {
        if(!route.isVertexInRoute(i))
        {
            Route newRoute = route;
            newRoute.routeWeight += graph.getWeight(newRoute.inRoute.back(),i);
            newRoute.inRoute.push_back(i);
            findAllRoutes(newRoute);
        }
    }
}
