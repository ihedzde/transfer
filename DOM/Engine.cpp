//
// Created by Ivan Hedz on 16.04.2022.
//

#include "Engine.h"
#include "iostream"

namespace DOM {
    int Engine::current_id;

    Engine::Engine() :
            _id(current_id++), _manufacturer(""), _speed(0),
            _rotation_frequency(0), _horsepower(0),
            _volume(0), _emissions(0) {}

    Engine::Engine(string manufacturer, double emissions, double volume, double speed, double horsepower,
                   int rotationFrequency)
            : _id(current_id++), _manufacturer(manufacturer), _emissions(emissions), _volume(volume), _speed(speed),
              _horsepower(horsepower),
              _rotation_frequency(rotationFrequency){}

    Engine::~Engine() = default;

    void Engine::show() const {
        cout << "ID: " << _id << endl;
        cout << "Fuel tank volumes: " << _volume << " liters;" << endl;
        cout << "Speed: " << _speed << " km/h;" << endl;
        cout << "CO₂ emissions: " << _emissions << " kg;" << endl;
        cout << "Horsepower: " << _horsepower << " 🐴;" << endl;
        cout << "Rotation frequency: " << _rotation_frequency << " RPM;" << endl;
        cout << "Manufacturer: " << _manufacturer << endl;
    }

    int Engine::getID() const {
        return _id;
    }

    double Engine::getEmissions() const {
        return _emissions;
    }

    void Engine::setEmissions(double kg) {
        Engine::_emissions = kg;
    }

    double Engine::getVolume() const {
        return _volume;
    }

    void Engine::setVolume(double volume) {
        _volume = volume;
    }

    double Engine::getSpeed() const {
        return _speed;
    }

    void Engine::setSpeed(double speed) {
        _speed = speed;
    }

    double Engine::getHorsepower() const {
        return _horsepower;
    }

    void Engine::setHorsepower(double horsepower) {
        _horsepower = horsepower;
    }

    int Engine::getRotationFrequency() const {
        return _rotation_frequency;
    }

    void Engine::setRotationFrequency(int rotationFrequency) {
        _rotation_frequency = rotationFrequency;
    }

    ostream &operator<<(ostream &os, const Engine &engine) {
        os << engine._id << endl << engine._manufacturer << endl << engine._emissions << endl << engine._volume
           << endl << engine._speed << endl << engine._horsepower << endl
           << engine._rotation_frequency << endl;
        return os;
    }

    istream &operator>>(istream &is, Engine &engine) {
        is >> engine._id >> engine._manufacturer >> engine._emissions >> engine._volume
           >> engine._speed >> engine._horsepower >> engine._rotation_frequency;
        return is;
    }

    const string &Engine::getManufacturer() const {
        return _manufacturer;
    }

    void Engine::setManufacturer(const string &manufacturer) {
        _manufacturer = manufacturer;
    }
} // DOM