//
// Created by Ivan Hedz on 16.04.2022.
//
#include "Engine.h"

#ifndef OOP_JETENGINE_H
#define OOP_JETENGINE_H

namespace DOM {
    using namespace std;

    class JetEngine : public Engine {
    private:
        double _impulse;
        int _effective_exhaust_velocity;
        int _mass_kg;
        double _trust_to_weight_ratio;
    public:
        JetEngine();


        JetEngine(string manufacturer, double emissions, double volume, double speed, double horsepower,
                  int rotationFrequency,
                  double impulse, int effectiveExhaustVelocity, int massKg, double trustToWeightRatio);

        friend ostream &operator<<(ostream &os, const JetEngine &engine);

        friend istream &operator>>(istream &is, JetEngine &engine);

        double getImpulse() const;

        void setImpulse(double impulse);

        int getEffectiveExhaustVelocity() const;

        void setEffectiveExhaustVelocity(int effectiveExhaustVelocity);

        int getMassKg() const;

        void setMassKg(int massKg);

        double getTrustToWeightRatio() const;

        void setTrustToWeightRatio(double trustToWeightRatio);

        void show() const override;
    };
} // DOM

#endif //OOP_JETENGINE_H