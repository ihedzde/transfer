#include <iostream>
#include "DOM/Engine.h"
#include "DOM/JetEngine.h"
#include "DOM/DieselEngine.h"
#include "Utilities/RoundedDoublyLinkedList.h"
#include "Utilities/Cui.h"

using namespace DOM;
using namespace Utilities;

int main() {
    auto *engineList = new RoundedDoublyLinkedList();
    char variant;
    do {
        variant = CUI::printMenu();
        switch (variant) {
            case '1':
                engineList->insertNodeHead(CUI::initNewJet());
                break;
            case '2':
                engineList->insertNodeHead(CUI::initNewDiesel());
                break;
            case '3':
                engineList->printNodes();
                break;
            case '4':
                std::cout << engineList->sumEnginesPowers(EngineType::DieselEngine);
                break;
            case '5':
                std::cout << engineList->sumEnginesPowers(EngineType::JetEngine);
                break;
            case '6':
                std::cout<< "Input id:";
                std::uint32_t id;
                std::cin >> id;
                if(engineList->deleteById(id))
                    std::cout << "Deleted" << std::endl;
                break;
            case '7':
                engineList->WriteToFile();
                break;
            case '8':
                engineList->ReadFromFile();
                break;
            case '9':
                CUI::setUpMockData(engineList);
                break;
        }
    } while (variant != 'e');
    delete engineList;
    return 0;
}
