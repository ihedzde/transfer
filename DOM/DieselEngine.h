//
// Created by Ivan Hedz on 16.04.2022.
//
#include "Engine.h"

#ifndef OOP_DIESELENGINE_H
#define OOP_DIESELENGINE_H

namespace DOM {

    class DieselEngine : public Engine {
    private:
        int _cylinders_count;
        double _cylinder_diameter;
    public:
        friend std::ostream &operator<<(std::ostream &os, const DieselEngine &engine);
        friend std::istream &operator>>(std::istream &is, DieselEngine &engine);
        DieselEngine();

        DieselEngine(double emissions, double volume, double speed, double horsepower, int rotationFrequency,
                     int cylindersCount, double cylinderDiameter);

        [[nodiscard]] int getCylindersCount() const;

        void setCylindersCount(int cylindersCount);

        [[nodiscard]] double getCylinderDiameter() const;

        void setCylinderDiameter(double cylinderDiameter);

        void show() const override;
    };

} // DOM

#endif //OOP_DIESELENGINE_H
