#include <stdio.h>


typedef enum {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} Day;


const char* check_day_type(Day d) {
    if (d == FRIDAY || d == SATURDAY) {
        return "Weekend";
    } else {
        return "Weekday";
    }
}

int main() {

    for (Day d = SATURDAY; d <= FRIDAY; d++) {
        printf("Day %d is a %s\n", d, check_day_type(d));
    }

    return 0;
}
