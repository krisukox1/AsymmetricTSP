#pragma once
#include "Graph.hpp"
#include <vector>
#include <iostream>

using BasicRoute = std::vector<Vertex>;

struct Route
{
    Route(std::vector<Vertex>initRoute, Weight weight):
        inRoute{initRoute}, routeWeight{weight}
    {
    }
    Route():routeWeight(UINT32_MAX){}
    bool isVertexInRoute(const Vertex&);
    BasicRoute inRoute;
    Weight routeWeight;
};
using Routes = std::vector<Route>;

inline std::ostream& operator<<(std::ostream& oStreamObj, const Route& route)
{
    for(auto vertex : route.inRoute)
        std::cout<<vertex<<" ";
    std::cout<<"w = "<<route.routeWeight;
    return oStreamObj;
}
