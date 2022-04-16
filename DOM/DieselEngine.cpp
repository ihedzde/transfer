//
// Created by Ivan Hedz on 16.04.2022.
//

#include "DieselEngine.h"
#include "iostream"

namespace DOM {
    int DieselEngine::getCylindersCount() const {
        return _cylinders_count;
    }

    void DieselEngine::setCylindersCount(int cylindersCount) {
        _cylinders_count = cylindersCount;
    }

    double DieselEngine::getCylinderDiameter() const {
        return _cylinder_diameter;
    }

    void DieselEngine::setCylinderDiameter(double cylinderDiameter) {
        _cylinder_diameter = cylinderDiameter;
    }


    void DieselEngine::show() const {
        Engine::show();
        std::cout << "Cylinders count: " << _cylinders_count << ";" << std::endl;
        std::cout << "Cylinder diameter: " << _cylinder_diameter << " mm;" << std::endl;
    }

    DieselEngine::DieselEngine() : Engine(), _cylinders_count(0),
                                   _cylinder_diameter(0) {
    }

    DieselEngine::DieselEngine(double emissions, double volume, double speed, double horsepower, int rotationFrequency,
                               int cylindersCount, double cylinderDiameter) : Engine(emissions, volume, speed,
                                                                                     horsepower, rotationFrequency),
                                                                              _cylinders_count(cylindersCount),
                                                                              _cylinder_diameter(cylinderDiameter) {}
} // DOM