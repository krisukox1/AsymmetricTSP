#include "include/Graph.hpp"
#include <memory>
#include <fstream>

int main()
{
    auto graph = std::make_unique<Graph>();
    graph->loadFromFile("input.txt");
    graph->display();
}
