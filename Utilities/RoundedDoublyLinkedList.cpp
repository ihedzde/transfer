//
// Created by Ivan Hedz on 16.04.2022.
//

#include "RoundedDoublyLinkedList.h"
#include "../DOM/JetEngine.h"
#include "../DOM/DieselEngine.h"
#include <iostream>
#include <initializer_list>
#include <fstream>

namespace Utilities {

    void RoundedDoublyLinkedList::printNodes() {
        if(head== nullptr)
        {
            std::cout << "No data in list" << std::endl;
            return;
        }
        auto tmp = head;
        if(head->data == nullptr)
        {
            std::cout<<"List is empty" << std::endl;
            return;
        }
        while (tmp != end) {
            tmp->data->show();
            std::cout << std::endl;
            tmp = tmp->next;
        }
        tmp->data->show();
    }

    NodeItem *RoundedDoublyLinkedList::insertNodeEnd(DOM::Engine *data) {

        if(end == nullptr)
        {
            end = new NodeItem;
            end->next = end;
            end->prev = end;
            end->data = data;
            head = end;
        }
        if(end->data == nullptr)
        {
            end->data = data;
            return  end;
        }
        auto new_node = new NodeItem;
        new_node->next = head;
        new_node->prev = end;
        new_node->data = data;

        head->prev = new_node;
        end->next = new_node;
        head = new_node;
        return head;
    }

    NodeItem *RoundedDoublyLinkedList::insertNodeHead(DOM::Engine *const data) {
        if(head == nullptr)
        {
            head = new NodeItem;
            head->next = head;
            head->prev = head;
            head->data = data;
            end = head;
        }
        if(head->data == nullptr)
        {
            head->data = data;
            return  head;
        }
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
        delete end;
    }

    double RoundedDoublyLinkedList::sumEnginesPowers(EngineType engineType) {
        auto sum = 0;
        auto tmp = head;
        if(head->data == nullptr)
        {
            std::cout<<"List is empty" << std::endl;
            return 0;
        }
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

    bool RoundedDoublyLinkedList::deleteById(std::atomic_uint32_t id) {

        auto tmp = head;
        if(head == end && head->data == nullptr)
        {
            std::cout<< "List is empty";
            return false;
        }
        if (tmp->data->getID() == id) {
            if(head == end)
            {
                delete tmp->data;
                tmp->data = nullptr;
                return true;
            }
            head = tmp->next;
            head->prev = end;
            end->next = head;
            delete tmp;
            return true;
        }
        while (tmp != end) {
            if (tmp->data->getID() == id) {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                return true;
            }
            tmp = tmp->next;
        }
        if (tmp->data->getID() == id) {
            end = tmp->prev;
            end->next = head;
            head->prev = end;
            delete tmp;
            return true;
        }
    }


    void RoundedDoublyLinkedList::WriteToFile() {
        auto tmp = head;
        if(head->data == nullptr)
        {
            std::cout<<"List is empty" << std::endl;
            return;
        }
        std::ofstream out("engine.dat");
        if (!out.is_open())
        {
            std::cout << "Error of open..." << std::endl;
            return;
        }

        while (tmp != end) {
            if (dynamic_cast<DOM::DieselEngine*>(tmp->data) != nullptr)
            {
                out << 1 << '\n';
                out << *((DOM::DieselEngine*)(tmp->data));
            }
            if (dynamic_cast<DOM::JetEngine*>(tmp->data) != nullptr)
            {
                out << 2 << '\n';
                out << *((DOM::JetEngine*)(tmp->data));
            }
            std::cout << std::endl;
            tmp = tmp->next;
        }
        if (dynamic_cast<DOM::DieselEngine*>(tmp->data) != nullptr)
        {
            out << 1 << '\n';
            out << *((DOM::DieselEngine*)(tmp->data));
        }
        if (dynamic_cast<DOM::JetEngine*>(tmp->data) != nullptr)
        {
            out << 2 << '\n';
            out << *((DOM::JetEngine*)(tmp->data));
        }
        std::cout << "Saved in engine.dat"<< std::endl;
        out.close();
    }

    void RoundedDoublyLinkedList::ReadFromFile() {
        std::string fileName;
        std::cout << "File data name(default is engine.dat): ";
        std::cin >> fileName;
        std::ifstream in(fileName);
        if (!in.is_open())
        {
            std::cout << "Error of open..." << std::endl;
            return;
        }
        DOM::DieselEngine* dieselEngine;
        DOM::JetEngine* jetEngine;
        int info;
        in >> info;
        while (!in.eof())
        {
            if (info == 1)
            {
                dieselEngine = new DOM::DieselEngine();
                in >> (*dieselEngine);
                insertNodeEnd(dieselEngine);
            }
            if (info == 2)
            {
                jetEngine = new DOM::JetEngine();
                in >> (*jetEngine);
                insertNodeEnd(jetEngine);
            }
            in >> info;
        }
        in.close();
        std::cout << "Loaded from file '" << fileName << "'\n";
    }

    NodeItem::~NodeItem() {
        if(data!= nullptr)
            delete data;
    }
} // Utilities