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
        ~NodeItem();
    } ;

    class RoundedDoublyLinkedList {
    private:
        NodeItem *head = nullptr;
        NodeItem *end = nullptr;
    public:
        void printNodes() const;
        void WriteToFile();
        void ReadFromFile();
        NodeItem *insertNodeEnd(DOM::Engine* data);
        NodeItem *insertNodeHead(DOM::Engine* data);
        bool deleteById(std::atomic_uint32_t id);
        double sumEnginesPowers(EngineType engineType) const;

        ~RoundedDoublyLinkedList();
    };
} // Utilities
#endif //OOP_ROUNDEDDOUBLYLINKEDLIST_H
