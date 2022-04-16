//
// Created by Ivan Hedz on 16.04.2022.
//
#include "iostream"
#include "../DOM/Engine.h"
#ifndef OOP_ROUNDEDDOUBLYLINKEDLIST_H
#define OOP_ROUNDEDDOUBLYLINKEDLIST_H
namespace Utilities{
    enum EngineType{
        JetEngine,
        DieselEngine
    };

    struct NodeItem {
        struct NodeItem *next = nullptr;
        struct NodeItem *prev = nullptr;
        DOM::Engine* data = nullptr;
    } ;

    class RoundedDoublyLinkedList {
    private:
        NodeItem *head = nullptr;
        NodeItem *end = nullptr;
    public:
        explicit RoundedDoublyLinkedList(DOM::Engine* data) {
            head = new NodeItem;
            head->next = head;
            head->prev = head;
            head->data = data;
            end = head;
        };
        void printNodes();
        NodeItem *insertNodeEnd(DOM::Engine* data);
        NodeItem *insertNodeHead(DOM::Engine* data);
        double sumEnginesPowers(EngineType engineType);

        ~RoundedDoublyLinkedList();
    };
} // Utilities
#endif //OOP_ROUNDEDDOUBLYLINKEDLIST_H
