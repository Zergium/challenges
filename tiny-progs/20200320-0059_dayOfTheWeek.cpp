class Solution {
public:
    static bool isLeapYear(int year) {
        return (0 == year % 4 && 0 != year % 100) || 0 == year % 400;
    }
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> day_names({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});

        vector<int> day_per_month({31,28,31, 30,31,30, 31,31,30, 31,30,31}); //non-leap feb
        
        int abs_day = day;
        month--;
        for (int i=0; i<month; i++) {
            abs_day += day_per_month[i];
            if (i==1 && isLeapYear(year)) {
                abs_day++;
            }
        };
        year--;
        while (year > 1971) {
            abs_day += isLeapYear(year) ? 366 : 365;
            year--;
        }
        
        //cout << "abs_day: " << abs_day << endl;
        int week_day_num = (abs_day + 5) % 7;
        //cout << "weel_day_num: " << week_day_num << endl;
        return day_names[week_day_num];
    }
};