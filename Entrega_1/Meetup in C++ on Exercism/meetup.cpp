#include "meetup.h"

scheduler::scheduler(boost::gregorian::greg_month month, int year)
    : month(month), year(year) {
}

boost::gregorian::date meetup::scheduler::calculate(int weekday, int week) const {

    boost::gregorian::date first(year, month, 1);

    int current = first.day_of_week().as_number();
    int result;

    if (week == 0) {
        result = 13 + (weekday -
            boost::gregorian::date(year, month, 13).day_of_week().as_number() + 7) % 7;
    }
    else if (week == 5) {
        boost::gregorian::date last = first.end_of_month();

        result = last.day() -
            (last.day_of_week().as_number() - weekday + 7) % 7;
    }
    else {
        result = 1 + (weekday - current + 7) % 7;
        result += (week - 1) * 7;
    }

    return boost::gregorian::date(year, month, result);
}

// Teenth
boost::gregorian::date meetup::scheduler::monteenth() const { return calculate(1, 0); }
boost::gregorian::date meetup::scheduler::tuesteenth() const { return calculate(2, 0); }
boost::gregorian::date meetup::scheduler::wednesteenth() const { return calculate(3, 0); }
boost::gregorian::date meetup::scheduler::thursteenth() const { return calculate(4, 0); }
boost::gregorian::date meetup::scheduler::friteenth() const { return calculate(5, 0); }
boost::gregorian::date meetup::scheduler::saturteenth() const { return calculate(6, 0); }
boost::gregorian::date meetup::scheduler::sunteenth() const { return calculate(0, 0); }

// First
boost::gregorian::date meetup::scheduler::first_monday() const { return calculate(1, 1); }
boost::gregorian::date meetup::scheduler::first_tuesday() const { return calculate(2, 1); }
boost::gregorian::date meetup::scheduler::first_wednesday() const { return calculate(3, 1); }
boost::gregorian::date meetup::scheduler::first_thursday() const { return calculate(4, 1); }
boost::gregorian::date meetup::scheduler::first_friday() const { return calculate(5, 1); }
boost::gregorian::date meetup::scheduler::first_saturday() const { return calculate(6, 1); }
boost::gregorian::date meetup::scheduler::first_sunday() const { return calculate(0, 1); }

// Second
boost::gregorian::date meetup::scheduler::second_monday() const { return calculate(1, 2); }
boost::gregorian::date meetup::scheduler::second_tuesday() const { return calculate(2, 2); }
boost::gregorian::date meetup::scheduler::second_wednesday() const { return calculate(3, 2); }
boost::gregorian::date meetup::scheduler::second_thursday() const { return calculate(4, 2); }
boost::gregorian::date meetup::scheduler::second_friday() const { return calculate(5, 2); }
boost::gregorian::date meetup::scheduler::second_saturday() const { return calculate(6, 2); }
boost::gregorian::date meetup::scheduler::second_sunday() const { return calculate(0, 2); }

// Third
boost::gregorian::date meetup::scheduler::third_monday() const { return calculate(1, 3); }
boost::gregorian::date meetup::scheduler::third_tuesday() const { return calculate(2, 3); }
boost::gregorian::date meetup::scheduler::third_wednesday() const { return calculate(3, 3); }
boost::gregorian::date meetup::scheduler::third_thursday() const { return calculate(4, 3); }
boost::gregorian::date meetup::scheduler::third_friday() const { return calculate(5, 3); }
boost::gregorian::date meetup::scheduler::third_saturday() const { return calculate(6, 3); }
boost::gregorian::date meetup::scheduler::third_sunday() const { return calculate(0, 3); }

// Fourth
boost::gregorian::date meetup::scheduler::fourth_monday() const { return calculate(1, 4); }
boost::gregorian::date meetup::scheduler::fourth_tuesday() const { return calculate(2, 4); }
boost::gregorian::date meetup::scheduler::fourth_wednesday() const { return calculate(3, 4); }
boost::gregorian::date meetup::scheduler::fourth_thursday() const { return calculate(4, 4); }
boost::gregorian::date meetup::scheduler::fourth_friday() const { return calculate(5, 4); }
boost::gregorian::date meetup::scheduler::fourth_saturday() const { return calculate(6, 4); }
boost::gregorian::date meetup::scheduler::fourth_sunday() const { return calculate(0, 4); }

// Last
boost::gregorian::date meetup::scheduler::last_monday() const { return calculate(1, 5); }
boost::gregorian::date meetup::scheduler::last_tuesday() const { return calculate(2, 5); }
boost::gregorian::date meetup::scheduler::last_wednesday() const { return calculate(3, 5); }
boost::gregorian::date meetup::scheduler::last_thursday() const { return calculate(4, 5); }
boost::gregorian::date meetup::scheduler::last_friday() const { return calculate(5, 5); }
boost::gregorian::date meetup::scheduler::last_saturday() const { return calculate(6, 5); }
boost::gregorian::date meetup::scheduler::last_sunday() const { return calculate(0, 5); }
