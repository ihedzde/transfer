//
// Created by Ivan Hedz on 16.04.2022.
//
#include "Engine.h"

#ifndef OOP_DIESELENGINE_H
#define OOP_DIESELENGINE_H

namespace DOM {
    using namespace std;
    class DieselEngine : public Engine {
    private:
        int _cylinders_count;
        double _cylinder_diameter;
    public:
        friend ostream &operator<<(ostream &os, const DieselEngine &engine);
        friend istream &operator>>(istream &is, DieselEngine &engine);
        DieselEngine();

        DieselEngine(string manufacturer, double emissions, double volume, double speed, double horsepower, int rotationFrequency,
                     int cylindersCount, double cylinderDiameter);

        int getCylindersCount() const;

        void setCylindersCount(int cylindersCount);

        double getCylinderDiameter() const;

        void setCylinderDiameter(double cylinderDiameter);

        void show() const override;
    };

} // DOM

#endif //OOP_DIESELENGINE_H
