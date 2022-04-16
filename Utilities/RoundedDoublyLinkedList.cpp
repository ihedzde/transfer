//
// Created by Ivan Hedz on 16.04.2022.
//

#include "RoundedDoublyLinkedList.h"
#include "../DOM/JetEngine.h"
#include "../DOM/DieselEngine.h"
#include <iostream>

namespace Utilities {

    void RoundedDoublyLinkedList::printNodes() {
        auto tmp = head;
        while (tmp != end) {
            tmp->data->show();
            std::cout << std::endl;
            tmp = tmp->next;
        }
        tmp->data->show();
    }

    NodeItem *RoundedDoublyLinkedList::insertNodeEnd(DOM::Engine *data) {
        auto new_node = new NodeItem;
        new_node->next = head;
        new_node->prev = end;
        new_node->data = data;

        head->prev = new_node;
        end->next = new_node;
        head = new_node;
        return head;
    }

    NodeItem *RoundedDoublyLinkedList::insertNodeHead(DOM::Engine *data) {
        auto new_node = new NodeItem;
        new_node->next = head;
        new_node->prev = end;
        new_node->data = data;

        head->prev = new_node;
        end->next = new_node;
        end = end->next;
        return end;
    }

    RoundedDoublyLinkedList::~RoundedDoublyLinkedList() {
        while (head != end) {
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        delete head;
    }

    double RoundedDoublyLinkedList::sumEnginesPowers(EngineType engineType) {
        auto sum = 0;
        auto tmp = head;
        switch (engineType) {
            case EngineType::DieselEngine:
                while (tmp != end) {
                    if (dynamic_cast<DOM::DieselEngine *>(tmp->data) != nullptr)
                        sum += tmp->data->getHorsepower();
                    tmp = tmp->next;
                }
                if (dynamic_cast<DOM::DieselEngine *>(tmp->data) != nullptr)
                    sum += tmp->data->getHorsepower();
                return sum;
            case EngineType::JetEngine:
                while (tmp != end) {
                    if (dynamic_cast<DOM::JetEngine *>(tmp->data) != nullptr)
                        sum += tmp->data->getHorsepower();
                    tmp = tmp->next;
                }
                if (dynamic_cast<DOM::JetEngine *>(tmp->data) != nullptr)
                    sum += tmp->data->getHorsepower();
                return sum;
            default:
                return sum;;
        }
    }


} // Utilities