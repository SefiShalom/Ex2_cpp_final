//
// Created by damir on 27-Dec-17.
//

#ifndef EX2_CPP_SEFI_BATTLEFIELD_H
#define EX2_CPP_SEFI_BATTLEFIELD_H


class Battlefield {
// defines a Game's battlefield. Considered as a two dimension field of non negative coordinates.
    const double _height, _width; //the field height and width

public:

    Battlefield(double height, double width);//ctor

    const double getHeight() const;//returns the Battlefield's height

    const double getWidth() const;//returns the Battlefield's width

};


#endif //EX2_CPP_SEFI_BATTLEFIELD_H
