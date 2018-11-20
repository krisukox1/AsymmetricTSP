#pragma once
#include <bitset>
#include "Graph.hpp"

struct Subset
{
    std::bitset<20> bitset;
    Vertex lastVertex;
};

inline bool operator==(const Subset& lv,const Subset& rv)
{
    return lv.bitset == rv.bitset &&
            lv.lastVertex == rv.lastVertex;
}

struct SubsetHasher
{
    std::size_t operator()(const Subset& subset) const
    {
        return subset.lastVertex * 10000000 + subset.bitset.to_ulong();
    }
};
