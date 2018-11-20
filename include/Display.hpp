#pragma once
#include <memory>
#include "TSM.hpp"
class Display
{
public:
    Display(){}
    void start();
private:
    std::unique_ptr<TSM> tsm;
    void loadFile();
    void findShortestRouteHK();
    void findShortestRouteBF();
};
