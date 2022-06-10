//
// Created by Ivan Hedz on 17.04.2022.
//

#include "Cui.h"

namespace Utilities {
    char CUI::printMenu() {
        char variant;
        cout << endl;
        cout << "Choose please:" << endl;
        cout << "e. Exit program" << endl;
        cout << "1. Add new jet engine to the list" << endl;
        cout << "2. Add new diesel engine to the list" << endl;
        cout << "3. List all engines" << endl;
        cout << "4. Print sum of diesel engines" << endl;
        cout << "5. Print sum of jet engines" << endl;
        cout << "6. Delete by id" << endl;
        cout << "7. Load in the file" << endl;
        cout << "8. Load out of the file" << endl;
        cout << "9. Load mock data" << endl;
        cout << "c. Clean data from list" << endl;
        cin >> variant;
        cout << "\r" << endl;
        return variant;
    }

    DOM::JetEngine *CUI::initNewJet() {
        double volume;
        cout << "Fuel tank volumes in liters: " << endl;
        cin >> volume;
        double speed;
        cout << "Speed in km/h: " << endl;
        cin >> speed;
        double emissions;
        cout << "CO₂ emissions in kg: " << endl;
        cin >> emissions;
        double horsepower;
        cout << "Horsepower: " << endl;
        cin >> horsepower;
        int rotation_frequency;
        cout << "Rotation frequency in RPM: " << endl;
        cin >> rotation_frequency;
        double impulse;
        int effectiveExhaustVelocity;
        int massKg;
        double trustToWeightRatio;

        cout << "Trust to weight ratio: " << endl;
        cin >> trustToWeightRatio;
        cout << "Impulse: " << endl;
        cin >> impulse;
        cout << "Effective exhaust velocity: " << endl;
        cin >> effectiveExhaustVelocity;
        cout << "Mass in kg: " << endl;
        cin >> massKg;
        string manufacturer;
        cout << "Manufacturer: " << endl;
        cin >> manufacturer;
        return new DOM::JetEngine(manufacturer, emissions, volume, speed, horsepower, rotation_frequency,
                                  impulse, effectiveExhaustVelocity, massKg, trustToWeightRatio);

    }

    DOM::DieselEngine *CUI::initNewDiesel() {
        double volume;
        cout << "Fuel tank volumes in liters: " << endl;
        cin >> volume;
        double speed;
        cout << "Speed in km/h: " << endl;
        cin >> speed;
        double emissions;
        cout << "CO₂ emissions in kg: " << endl;
        cin >> emissions;
        double horsepower;
        cout << "Horsepower: " << endl;
        cin >> horsepower;
        int rotation_frequency;
        cout << "Rotation frequency in RPM: " << endl;
        cin >> rotation_frequency;
        int cylinders_count;
        cout << "Cylinders count: " << endl;
        cin >> cylinders_count;
        double cylinder_diameter;
        cout << "Cylinder diameter: " << endl;
        cin >> cylinder_diameter;
        string manufacturer;
        cout << "Manufacturer: " << endl;
        cin >> manufacturer;
        return new DOM::DieselEngine(manufacturer, emissions, volume, speed, horsepower, rotation_frequency,
                                     cylinders_count, cylinder_diameter);
    }

    void CUI::setUpMockData(RoundedDoublyLinkedList *engineList) {
        DOM::Engine *jetEngine = new DOM::JetEngine("Tesla", 1993.24, 42.2, 422.2, 123, 1532,
                                                    24, 304, 31, 21);
        DOM::Engine *dieselEngine = new DOM::DieselEngine("Jeep", 53.3, 2.4, 42.2, 23, 132,
                                                          24, 2492);
        DOM::Engine *dieselEngine2 = new DOM::DieselEngine("Honda", 23.2, 3.3, 36, 12, 231,
                                                           24, 53535);
        DOM::Engine *dieselEngine3 = new DOM::DieselEngine("Leower", 494.2, 4.2, 29.3, 42, 424,
                                                           24, 53535);
        engineList->insertNodeHead(jetEngine);
        engineList->insertNodeHead(dieselEngine);
        engineList->insertNodeHead(dieselEngine2);
        engineList->insertNodeHead(dieselEngine3);
    }

    void CUI::RunActions(RoundedDoublyLinkedList *&engineList) {
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
                    cout << "Diesel engine ∑ " ;
                    cout << engineList->sumEnginesPowers(EngineType::DieselEngine)<<" 🐴"<< endl;
                    break;
                case '5':
                    cout << "Jet engine ∑ " ;
                    cout << engineList->sumEnginesPowers(EngineType::JetEngine) <<" 🐴"<< endl;
                    break;
                case '6':
                    cout << "Input id:";
                    int id;
                    cin >> id;
                    if (engineList->deleteById(id))
                        cout << "Deleted" << endl;
                    else
                        cout << "Not found by id" << endl;
                    break;
                case '7':
                    engineList->writeToFile();
                    break;
                case '8':
                    engineList->readFromFile();
                    break;
                case '9':
                    CUI::setUpMockData(engineList);
                    break;
                case 'c':
                    delete engineList;
                    engineList = new RoundedDoublyLinkedList();
                    cout << "List cleaned" << endl;
                    break;
            }
        } while (variant != 'e');
    }

}