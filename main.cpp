#include <iostream>
#include "DOM/Engine.h"
#include "DOM/JetEngine.h"
#include "DOM/DieselEngine.h"
#include "Utilities/RoundedDoublyLinkedList.h"

using namespace DOM;
using namespace Utilities;

int main() {
    Engine *jetEngine = new DOM::JetEngine(2.2, 1.1, 42.2, 241, 22,
                                           24, 53535, 31, 21);
    Engine *dieselEngine = new DOM::DieselEngine(2.2, 1.1, 42.2, 203132, 123,
                                                 24, 53535);
    Engine *dieselEngine2 = new DOM::DieselEngine(2.2, 1.1, 42.2, 2042, 123,
                                                  24, 53535);
    RoundedDoublyLinkedList engineList(jetEngine);
    engineList.insertNodeHead(dieselEngine);
    engineList.insertNodeHead(dieselEngine2);
    engineList.printNodes();
    std::cout << engineList.sumEnginesPowers(EngineType::JetEngine) << " 🐴" << std::endl;
    std::cout << engineList.sumEnginesPowers(EngineType::DieselEngine) << " 🐴" << std::endl;;
    return 0;
}
