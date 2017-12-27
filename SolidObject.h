//
// Created by damir on 12-Dec-17.
//

#ifndef EX2_CPP_SOLIDOBJECT_H
#define EX2_CPP_SOLIDOBJECT_H

#include "Point.h"
#include "MapObject.h"

class SolidObject : public MapObject, public std::enable_shared_from_this<SolidObject> {

    double _length, _width;
public:

    SolidObject(const Point& position, double len, double width);
    virtual ~SolidObject();
    void acceptAction(Soldier* soldier);
    std::ostream& toString(std::ostream& out);


};


#endif //EX2_CPP_SOLIDOBJECT_H
