/*
Author: Mohamed Newir
Date: 4/06/2025
File: lightObserver.hpp
Description:
            -> This file contains the declaration of the ObservableLEDLight class,
                which is a type of LED light that reacts to motion sensor events using the Observer pattern.
*/

#ifndef LIGHT_OBSERVER_HPP
#define LIGHT_OBSERVER_HPP

#include "light.hpp"
#include "observer.hpp"

// LED Light that reacts to motion sensor via Observer pattern
class ObservableLEDLight : public LEDLight, public Observer {
public:
    void update();
};

#endif // LIGHT_OBSERVER_HPP