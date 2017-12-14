#include <iostream>
#include "Point.h"
#include "Rifle.h"
#include "SolidObject.h"

using namespace std;

int main() {

    Point p(1,1);
    cout << p.get_x() << endl;

    Point p_test = p.nextPoint(17, Point(17,31));
    cout << p_test.get_x() << ", " << p_test.get_y() << endl;

    Rifle rifle(&p,50,1);

    SolidObject so(&p,100,100);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}