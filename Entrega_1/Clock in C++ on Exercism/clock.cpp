#include "clock.h"

date_independent::clock::clock(int minutes) {
    total_minutes = (minutes % 1440 + 1440) % 1440;
}

date_independent::clock date_independent::clock::at(int hour, int minute) {
    return clock(hour * 60 + minute);
}

date_independent::clock date_independent::clock::plus(int minutes) const {
    return clock(total_minutes + minutes);
}

date_independent::clock::operator std::string() const {
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;

    std::string result;

    if (hours < 10) {
        result += "0";
    }

    result += std::to_string(hours);
    result += ":";

    if (minutes < 10) {
        result += "0";
    }

    result += std::to_string(minutes);

    return result;
}

bool date_independent::clock::operator==(const clock& other) const {
    return total_minutes == other.total_minutes;
}

bool date_independent::clock::operator!=(const clock& other) const {
    return total_minutes != other.total_minutes;
}
