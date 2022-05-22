//
// Created by Ivan Hedz on 17.04.2022.
//
#include "iostream"
#include "../DOM/JetEngine.h"
#include "../DOM/DieselEngine.h"
#include "RoundedDoublyLinkedList.h"

#ifndef OOP_CUI_H
#define OOP_CUI_H

namespace Utilities {
    class CUI {
    public:
        static char printMenu();
        static void setUpMockData(RoundedDoublyLinkedList * engineList);
        static DOM::JetEngine *initNewJet();

        static DOM::DieselEngine *initNewDiesel();
    };
} // Utilities

#endif //OOP_CUI_H
