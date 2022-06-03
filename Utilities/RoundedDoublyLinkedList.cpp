//
// Created by Ivan Hedz on 16.04.2022.
//

#include "RoundedDoublyLinkedList.h"
#include "../DOM/JetEngine.h"
#include "../DOM/DieselEngine.h"
#include <iostream>
#include <fstream>

namespace Utilities {
    bool RoundedDoublyLinkedList::isListEmpty() const {
        return head == end || head->data == nullptr;
    }

    void RoundedDoublyLinkedList::printNodes() const {
        if (isListEmpty()) {
            cout << "No data in list" << endl;
            return;
        }
        auto tmp = head;
        while (tmp != end) {
            tmp->data->show();
            cout << endl;
            tmp = tmp->next;
        }
        tmp->data->show();
    }

    NodeItem *RoundedDoublyLinkedList::insertNodeEnd(DOM::Engine *data) {
        if (end == nullptr) {
            end = new NodeItem;
            end->next = end;
            end->prev = end;
            end->data = data;
            head = end;
            return end;
        }
        if (end->data == nullptr) {
            end->data = data;
            return end;
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
        if (head == nullptr) {
            head = new NodeItem;
            head->next = head;
            head->prev = head;
            head->data = data;
            end = head;
            return head;
        }
        if (head->data == nullptr) {
            head->data = data;
            return head;
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

    double RoundedDoublyLinkedList::sumEnginesPowers(EngineType engineType) const {
        if (isListEmpty()) {
            cout << "List is empty" << endl;
            return 0;
        }
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

    bool RoundedDoublyLinkedList::deleteById(int id) {
        if (isListEmpty()) {
            cout << "List is empty";
            return false;
        }
        auto tmp = head;
        if (tmp->data->getID() == id) {
            if (head == end) {
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


    void RoundedDoublyLinkedList::writeToFile() {
        if (isListEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        string filename;
        auto tmp = head;
        cout << "Input please file name:" << endl;
        cin >> filename;
        ofstream out(filename);
        if (!out.is_open()) {
            cout << "Error of open..." << endl;
            return;
        }

        while (tmp != end) {
            if (dynamic_cast<DOM::DieselEngine *>(tmp->data) != nullptr) {
                out << 1 << '\n';
                out << *((DOM::DieselEngine *) (tmp->data));
            }
            if (dynamic_cast<DOM::JetEngine *>(tmp->data) != nullptr) {
                out << 2 << '\n';
                out << *((DOM::JetEngine *) (tmp->data));
            }
            cout << endl;
            tmp = tmp->next;
        }
        if (dynamic_cast<DOM::DieselEngine *>(tmp->data) != nullptr) {
            out << 1 << '\n';
            out << *((DOM::DieselEngine *) (tmp->data));
        }
        if (dynamic_cast<DOM::JetEngine *>(tmp->data) != nullptr) {
            out << 2 << '\n';
            out << *((DOM::JetEngine *) (tmp->data));
        }
        cout << "Saved in " << filename << endl;
        out.close();
    }

    void RoundedDoublyLinkedList::readFromFile() {
        string fileName;
        cout << "Enter file data name: ";
        cin >> fileName;
        ifstream in(fileName);
        try {
            if (!in.is_open()) {
                throw exception();
            }
            DOM::DieselEngine *dieselEngine;
            DOM::JetEngine *jetEngine;
            int info;
            in >> info;
            while (!in.eof()) {
                if (info == 1) {
                    dieselEngine = new DOM::DieselEngine();
                    in >> (*dieselEngine);
                    insertNodeHead(dieselEngine);
                }
                if (info == 2) {
                    jetEngine = new DOM::JetEngine();
                    in >> (*jetEngine);
                    insertNodeHead(jetEngine);
                }
                in >> info;
            }
            cout << "Loaded from file '" << fileName << "'\n";
        }
        catch (exception &e) {
            cout << "Error to open " << fileName << endl;
        }
        in.close();
    }


    NodeItem::~NodeItem() {
        if (data != nullptr)
            delete data;
    }
} // Utilities