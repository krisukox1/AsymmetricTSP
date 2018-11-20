#include "../include/Routes.hpp"
#include <algorithm>

bool Route::isVertexInRoute(const Vertex& input)
{
    auto a = std::find(inRoute.cbegin(),inRoute.cend(),input);
    if(a == inRoute.cend())
        return 0;
    return 1;
}
