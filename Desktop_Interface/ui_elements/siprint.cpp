#include "siprint.h"
#include <cmath>

siprint::siprint(const char *unitsInit, double valInit)
: value(valInit)
{
    units[0] = '\0';
    strncat(units, unitsInit, sizeof units - 1);
}

char* siprint::printVal(){
    const char *sign = (value < 0.0) ? "-" : "";
    double abs_value = std::fabs(value);

    if (abs_value >= 1000000000000000000.0) {
        snprintf(printString, sizeof printString, "%sInf %s", sign, units);
    } else if (abs_value >= 1000000.0) {
        snprintf(printString, sizeof printString, "%s%.2fM%s", sign, abs_value/1000000, units);
    } else if (abs_value >= 1000.0) {
        snprintf(printString, sizeof printString, "%s%.2fk%s", sign, abs_value/1000, units);
    } else if (abs_value >= 1.0) {
        snprintf(printString, sizeof printString, "%s%.2f%s", sign, abs_value, units);
    } else if (abs_value >= 0.001) {
        snprintf(printString, sizeof printString, "%s%.2fm%s", sign, abs_value*1000, units);
    } else if (abs_value >= 0.000001) {
        snprintf(printString, sizeof printString, "%s%.2fu%s", sign, abs_value*1000000, units);
    } else if (abs_value >= 0.000000001) {
        snprintf(printString, sizeof printString, "%s%.2fn%s", sign, abs_value*1000000000, units);
    } else if (abs_value >= 0.000000000001) {
        snprintf(printString, sizeof printString, "%s%.2fp%s", sign, abs_value*1000000000000, units);
    } else {
        snprintf(printString, sizeof printString, "%s%.2f%s", sign, abs_value, units);
    }

    return printString;
}
