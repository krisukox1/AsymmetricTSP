#include "TSM.hpp"
#include <memory>
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
