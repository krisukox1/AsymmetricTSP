#include "../include/Display.hpp"
#include <curses.h>
#include <fstream>

void Display::start()
{
    char key;
    do
    {
        system("clear");
        std::cout<<"1 - wczytaj plik\n"
                   "2 - wyswietl graf\n"
                   "3 - najkrotrza droga dynamic programing\n"
                   "4 - najkrotrza droga brute force\n";
        key = std::getchar();
        switch(key)
        {
        case '1':
            system("clear");
            loadFile();
            break;
        case '2':
            system("clear");
            if(tsm)
                std::cout<<tsm->graph;
            else
                std::cout<<"wczytaj graf!"<<std::endl;
            std::getchar();
            std::getchar();
            break;
        case '3':
            system("clear");
            if(tsm)
                findShortestRouteHK();
            else
                std::cout<<"wczytaj graf!"<<std::endl;
            std::getchar();
            std::getchar();
            break;
        case '4':
            system("clear");
            if(tsm)
                findShortestRouteBF();
            else
                std::cout<<"wczytaj graf!"<<std::endl;
            std::getchar();
            std::getchar();
            break;
        }

    }
    while(key != 27);
}

void Display::loadFile()
{
    std::string fileName;
    std::cout<<"Podaj nazwe pliku: ";
    std::cin>>fileName;
    std::ifstream file(fileName);
    if(not file.is_open())
    {
        std::cout<<"niepoprawna nazwa pliku"<<std::endl;
        std::getchar();
        std::getchar();
        return;
    }
    tsm = std::make_unique<TSM>(file);
}

void Display::findShortestRouteHK()
{
    Vertex startVertex;
    std::cout<<"Podaj wierzcholek poczatkowy: ";
    std::cin>>startVertex;
    std::cout<<tsm->findShortestRouteHK(startVertex);
}


void Display::findShortestRouteBF()
{
    Vertex startVertex;
    std::cout<<"Podaj wierzcholek poczatkowy: ";
    std::cin>>startVertex;
    std::cout<<tsm->findShortestRouteBF(startVertex);
}
