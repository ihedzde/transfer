//
// Created by Ivan Hedz on 17.04.2022.
//

#include "Cui.h"

namespace Utilities {
    char CUI::printMenu() {
        char variant;
        std::cout << std::endl;
        std::cout << "Choose please:" << std::endl;
        std::cout << "e. Exit program" << std::endl;
        std::cout << "1. Add new jet engine to the list" << std::endl;
        std::cout << "2. Add new diesel engine to the list" << std::endl;
        std::cout << "3. List all engines" << std::endl;
        std::cout << "4. Print sum of diesel engines" << std::endl;
        std::cout << "5. Print sum of jet engines" << std::endl;
        std::cout << "6. Delete by id" << std::endl;
        std::cin >> variant;
        std::cout << "\r" << std::endl;
        return variant;
    }

    RoundedDoublyLinkedList *setUpMockData() {
        DOM::Engine *jetEngine = new DOM::JetEngine(2.2, 1.1, 42.2, 241, 22,
                                                    24, 53535, 31, 21);
        DOM::Engine *dieselEngine = new DOM::DieselEngine(2.2, 1.1, 42.2, 203132, 123,
                                                          24, 53535);
        DOM::Engine *dieselEngine2 = new DOM::DieselEngine(2.2, 1.1, 42.2, 2042, 123,
                                                           24, 53535);
        auto engineList = new RoundedDoublyLinkedList(jetEngine);
        engineList->insertNodeHead(dieselEngine);
        engineList->insertNodeHead(dieselEngine2);
        return engineList;
    }

    DOM::JetEngine *CUI::initNewJet() {
        double volume;
        std::cout << "Fuel tank volumes in liters: " << std::endl;
        std::cin >> volume;
        double speed;
        std::cout << "Speed in km/h: " << std::endl;
        std::cin >> speed;
        double emissions;
        std::cout << "CO₂ emissions in kg: " << std::endl;
        std::cin >> emissions;
        double horsepower;
        std::cout << "Horsepower: " << std::endl;
        std::cin >> horsepower;
        int rotation_frequency;
        std::cout << "Rotation frequency in RPM: " << std::endl;
        std::cin >> rotation_frequency;
        double impulse;
        int effectiveExhaustVelocity;
        int massKg;
        double trustToWeightRatio;

        std::cout << "Trust to weight ratio: " << std::endl;
        std::cin >> trustToWeightRatio;
        std::cout << "Impulse: " << std::endl;
        std::cin >> impulse;
        std::cout << "Effective exhaust velocity: " << std::endl;
        std::cin >> effectiveExhaustVelocity;
        std::cout << "Mass in kg: " << std::endl;
        std::cin >> massKg;

        return new DOM::JetEngine(emissions, volume, speed, horsepower, rotation_frequency,
                                  impulse, effectiveExhaustVelocity, massKg, trustToWeightRatio);

    }

    DOM::DieselEngine *CUI::initNewDiesel() {
        double volume;
        std::cout << "Fuel tank volumes in liters: " << std::endl;
        std::cin >> volume;
        double speed;
        std::cout << "Speed in km/h: " << std::endl;
        std::cin >> speed;
        double emissions;
        std::cout << "CO₂ emissions in kg: " << std::endl;
        std::cin >> emissions;
        double horsepower;
        std::cout << "Horsepower: " << std::endl;
        std::cin >> horsepower;
        int rotation_frequency;
        std::cout << "Rotation frequency in RPM: " << std::endl;
        std::cin >> rotation_frequency;
        int cylinders_count;
        double cylinder_diameter;
        std::cout << "Cylinders count: " << std::endl;
        std::cin >> cylinders_count;
        std::cout << "Cylinder diameter: " << std::endl;
        std::cin >> cylinder_diameter;
        return new DOM::DieselEngine(emissions, volume, speed, horsepower, rotation_frequency,
                                     cylinders_count, cylinder_diameter);
    }

    RoundedDoublyLinkedList * CUI::setUpMockData() {
        DOM::Engine *jetEngine = new DOM::JetEngine(2.2, 1.1, 42.2, 241, 22,
                                               24, 53535, 31, 21);
        DOM::Engine *dieselEngine = new DOM::DieselEngine(2.2, 1.1, 42.2, 203132, 123,
                                                     24, 53535);
        DOM::Engine *dieselEngine2 = new DOM::DieselEngine(2.2, 1.1, 42.2, 2042, 123,
                                                      24, 53535);
        auto engineList = new RoundedDoublyLinkedList(jetEngine);
        engineList->insertNodeHead(dieselEngine);
        engineList->insertNodeHead(dieselEngine2);
        return engineList;
    }

}