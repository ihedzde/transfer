//
// Created by Ivan Hedz on 16.04.2022.
//
#include "JetEngine.h"

namespace DOM {
    JetEngine::JetEngine() : Engine(),
                             _trust_to_weight_ratio(0), _effective_exhaust_velocity(0),
                             _impulse(0), _mass_kg(0) {}

    JetEngine::JetEngine(string manufacturer, double emissions, double volume, double speed, double horsepower,
                         int rotationFrequency,
                         double impulse, int effectiveExhaustVelocity, int massKg, double trustToWeightRatio) : Engine(
            manufacturer,
            emissions, volume, speed, horsepower, rotationFrequency), _impulse(impulse), _effective_exhaust_velocity(
            effectiveExhaustVelocity), _mass_kg(massKg), _trust_to_weight_ratio(trustToWeightRatio) {}

    double JetEngine::getImpulse() const {
        return _impulse;
    }

    void JetEngine::setImpulse(double impulse) {
        _impulse = impulse;
    }

    int JetEngine::getEffectiveExhaustVelocity() const {
        return _effective_exhaust_velocity;
    }

    void JetEngine::setEffectiveExhaustVelocity(int effectiveExhaustVelocity) {
        _effective_exhaust_velocity = effectiveExhaustVelocity;
    }

    int JetEngine::getMassKg() const {
        return _mass_kg;
    }

    void JetEngine::setMassKg(int massKg) {
        _mass_kg = massKg;
    }

    double JetEngine::getTrustToWeightRatio() const {
        return _trust_to_weight_ratio;
    }

    void JetEngine::setTrustToWeightRatio(double trustToWeightRatio) {
        _trust_to_weight_ratio = trustToWeightRatio;
    }

    void JetEngine::show() const {
        Engine::show();
        cout << "Trust to weight ratio: " << _trust_to_weight_ratio << ";" << endl;
        cout << "Impulse: " << _impulse << " s;" << endl;
        cout << "Effective exhaust velocity: " << _effective_exhaust_velocity << " m/s;" << endl;
        cout << "Mass: " << _mass_kg << " kg;" << endl;
    }

    ostream &operator<<(ostream &os, const JetEngine &engine) {
        os << static_cast<const DOM::Engine &>(engine) << engine._trust_to_weight_ratio << endl
           << engine._impulse << endl << engine._effective_exhaust_velocity << endl
           << engine._mass_kg << endl;
        return os;
    }

    istream &operator>>(istream &is, JetEngine &engine) {
        is >> static_cast<DOM::Engine &>(engine) >> engine._trust_to_weight_ratio >> engine._impulse
           >> engine._effective_exhaust_velocity >> engine._mass_kg;
        return is;
    }
} // DOM