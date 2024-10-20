// src: 2011 Rocky Mountain Regional Contest H
struct Date {
    int month, day, year;
    Date(int mm = 1, int dd = 1, int yy = 1900) : month(mm), day(dd), year(yy) {}
    static constexpr int daysInMonth[2][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };
    static constexpr bool isLeap(int y){return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);}
    bool operator<(const Date& date) const {
        if (year != date.year) return year < date.year;
        if (month != date.month) return month < date.month;
        return day < date.day;
    }
    bool operator <=(const Date& date) const{
        return not (date < *this);
    }
    bool operator >(const Date& date) const{
        return date < *this;
    }
    bool operator >=(const Date& date) const{
        return not (*this < date);
    }
    void inc() {
        if (day++ == daysInMonth[isLeap(year)][month]) {
            day = 1;
            if (month++ == 12) {
                month = 1;
                year++;
            }
        }
    }
    void dec() {
        if (day-- == 1) {
            if (month-- == 1) {
                month = 12;
                assert(year > 0);
                year--;
            }
            day = daysInMonth[isLeap(year)][month];
        }
    }
    void change(int step){
        if(step == 0) return;
        if(step > 0){
            for(int i=0;i<step;i++) inc();
        }else{
            step *= -1;
            for(int i=0;i<step;i++) dec();
        }
    }
    friend istream& operator>>(istream& is, Date& date) {
        char c;
        return is >> date.month >> c >> date.day >> c >> date.year;
    }
    friend ostream& operator<<(ostream& os, const Date& date) {
        return os << date.month << '/' << date.day << '/' << date.year;
    }
};
