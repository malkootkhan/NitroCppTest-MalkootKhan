#include "rectangle.hpp"
/*This overloaded operator < check the rectangle intersection logic here*/
bool operator<(const Rectangle& rec1, const Rectangle& rec2) {
    if (rec1.lLeft_point.getXcord() >= rec2.uRight_point.getXcord() || rec2.lLeft_point.getXcord() >= rec1.uRight_point.getXcord())
        return false;
    if (rec1.lLeft_point.getYcord() >= rec2.uRight_point.getYcord() || rec2.lLeft_point.getYcord() >= rec1.uRight_point.getYcord())
        return false;
    return true;
}

/*Operator overloaded to give customized definition to & for rectangle objects intersection*/
bool operator&(const Rectangle& rec1, const Rectangle& rec2) {
    return rec1 < rec2;
}

/*this function return the new shaded rectangle object formed by rec1 and rec2*/
Rectangle getShadedRec(const Rectangle& rec1, const Rectangle& rec2) {
    Rectangle newRec;
    newRec.uLeft_point.setPoint((std::max(rec1.uLeft_point.getXcord(), rec2.uLeft_point.getXcord())), (std::min(rec1.uLeft_point.getYcord(), rec2.uLeft_point.getYcord())) );
    newRec.uRight_point.setPoint((std::min(rec1.uRight_point.getXcord(), rec2.uRight_point.getXcord())), (std::min(rec1.uRight_point.getYcord(), rec2.uRight_point.getYcord())) );
    newRec.lLeft_point.setPoint((std::max(rec1.lLeft_point.getXcord(), rec2.lLeft_point.getXcord())), (std::max(rec1.lLeft_point.getYcord(), rec2.lLeft_point.getYcord())) );
    newRec.lRight_point.setPoint((std::min(rec1.lRight_point.getXcord(), rec2.lRight_point.getXcord())), (std::max(rec1.lRight_point.getYcord(), rec2.lRight_point.getYcord())) );

    newRec.setWidth(newRec.uRight_point.getXcord() - newRec.uLeft_point.getXcord());
    newRec.setHeight(newRec.uLeft_point.getYcord() - newRec.lLeft_point.getYcord());

    return newRec;
}

