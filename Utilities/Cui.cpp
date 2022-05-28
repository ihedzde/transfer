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
        std::cout << "7. Load in the file" << std::endl;
        std::cout << "8. Load out of the file" << std::endl;
        std::cout << "9. Load mock data" <<std::endl;
        std::cout << "c. Clean data from list" <<std::endl;
        std::cin >> variant;
        std::cout << "\r" << std::endl;
        return variant;
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

    void CUI::setUpMockData(RoundedDoublyLinkedList * engineList) {
        DOM::Engine *jetEngine = new DOM::JetEngine(2.2, 1.1, 42.2, 241, 22,
                                               24, 53535, 31, 21);
        DOM::Engine *dieselEngine = new DOM::DieselEngine(2.2, 1.1, 42.2, 203132, 123,
                                                     24, 53535);
        DOM::Engine *dieselEngine2 = new DOM::DieselEngine(2.2, 1.1, 42.2, 2042, 123,
                                                      24, 53535);
        engineList->insertNodeHead(jetEngine);
        engineList->insertNodeHead(dieselEngine);
        engineList->insertNodeHead(dieselEngine2);
    }

    void CUI::RunActions(RoundedDoublyLinkedList * engineList) {
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
                case 'c':
                    delete engineList;
                    engineList = new RoundedDoublyLinkedList();
                    break;
            }
        } while (variant != 'e');
    }

}