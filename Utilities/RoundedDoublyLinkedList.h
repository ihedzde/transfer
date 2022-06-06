//
// Created by Ivan Hedz on 16.04.2022.
//

#ifndef OOP_ROUNDEDDOUBLYLINKEDLIST_H
#define OOP_ROUNDEDDOUBLYLINKEDLIST_H
#include "iostream"
#include "../DOM/Engine.h"
namespace Utilities{
    using namespace std;
    enum EngineType{
        JetEngine,
        DieselEngine
    };

    struct NodeItem {
        struct NodeItem *next = nullptr;
        struct NodeItem *prev = nullptr;
        DOM::Engine* data = nullptr;
        ~NodeItem();
    } ;

    class RoundedDoublyLinkedList {
    private:
        NodeItem *head = nullptr;
        NodeItem *end = nullptr;
    public:
        void printNodes() const;
        void writeToFile();
        void readFromFile();
        NodeItem *insertNodeEnd(DOM::Engine* data);
        NodeItem *insertNodeHead(DOM::Engine* data);
        bool deleteById(int id);
        double sumEnginesPowers(EngineType engineType) const;
        bool isListEmpty() const;
        ~RoundedDoublyLinkedList();
    };
} // Utilities
#endif //OOP_ROUNDEDDOUBLYLINKEDLIST_H
