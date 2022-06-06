//
// Created by Ivan Hedz on 16.04.2022.
//
#ifndef OOP_ENGINE_H
#define OOP_ENGINE_H
#include <ostream>
#include "iostream"
#include "string"
namespace DOM {
    using namespace std;

    class Engine {
        static int current_id;//Static ID for generating unique one
    protected:
        int _id;
        double _emissions;
        double _volume;
        double _speed;
        double _horsepower;
        int _rotation_frequency;
        string _manufacturer;

        Engine();

        Engine(string manufacturer, double emissions, double volume, double speed, double horsepower,
               int rotationFrequency);

    public:
        virtual ~Engine();

        friend ostream &operator<<(ostream &os, const Engine &engine);

        friend istream &operator>>(istream &is, Engine &engine);

        const string &getManufacturer() const;

        void setManufacturer(const string &manufacturer);

        double getHorsepower() const;

        void setHorsepower(double horsepower);

        int getRotationFrequency() const;

        void setRotationFrequency(int rotationFrequency);

        double getSpeed() const;

        void setSpeed(double speed);

        double getVolume() const;

        void setVolume(double volume);

        double getEmissions() const;

        void setEmissions(double kg);

        int getID() const;

        virtual void show() const;
    };
} // DOM

#endif //OOP_ENGINE_H
