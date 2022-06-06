//
// Created by Ivan Hedz on 16.04.2022.
//

#include "DieselEngine.h"

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
        cout << "Cylinders count: " << _cylinders_count << ";" << endl;
        cout << "Cylinder diameter: " << _cylinder_diameter << " mm;" << endl;
    }

    DieselEngine::DieselEngine() : Engine(), _cylinders_count(0),
                                   _cylinder_diameter(0) {}

    DieselEngine::DieselEngine(string manufacturer, double emissions, double volume, double speed, double horsepower,
                               int rotationFrequency,
                               int cylindersCount, double cylinderDiameter) : Engine(manufacturer, emissions, volume,
                                                                                     speed,
                                                                                     horsepower, rotationFrequency),
                                                                              _cylinders_count(cylindersCount),
                                                                              _cylinder_diameter(cylinderDiameter) {}

    ostream &operator<<(ostream &os, const DieselEngine &engine) {
        os << static_cast<const DOM::Engine &>(engine) << engine._cylinders_count << endl
           << engine._cylinder_diameter << endl;
        return os;
    }

    istream &operator>>(istream &is, DieselEngine &engine) {
        is >> static_cast<DOM::Engine &>(engine) >> engine._cylinders_count >> engine._cylinder_diameter;
        return is;
    }
} // DOM