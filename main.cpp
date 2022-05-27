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
    CUI::RunActions(engineList);
    delete engineList;
    return 0;
}
