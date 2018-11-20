#pragma once
#include <bitset>
#include <map>
#include "Graph.hpp"

struct Subset
{
    std::bitset<20> bitset;
    Vertex lastVertex;
};

struct compareSubset
{
    bool operator()(Subset lv,
                    Subset rv)
    {
        if(lv.bitset.to_ulong() == rv.bitset.to_ulong())
        {
            return lv.lastVertex < rv.lastVertex;
        }
        return lv.bitset.to_ulong() < rv.bitset.to_ulong();
    }
};
