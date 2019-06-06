#include <iostream>
#include "Common.h"
#include "Ocean.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(nullptr));
    Ocean ocean;
    ocean.addObjects(ObjType::PREY, 5);
    ocean.addObjects(ObjType::PREDATOR, 4);
    ocean.addObjects(ObjType::STONE, 8);
    //ocean.print();

    for (int i=0; i < 6; i++)
    {
        ocean.run();
        cout << "\n\n" << endl;
        ocean.print();
    }
    return 0;
}