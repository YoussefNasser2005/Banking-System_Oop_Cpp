#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <cstdio>

using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;
    short _Hour = 0;
    short _Minute = 0;
    short _Second = 0;

public:


    clsDate(short Day, short Month, short Year,
        short Hour = 0, short Minute = 0, short Second = 0)
    {
        _Day = Day; _Month = Month; _Year = Year;
        _Hour = Hour; _Minute = Minute; _Second = Second;
    }

    clsDate() 
    {
        *this = GetSystemDate();
    }

    void SetDate(short day, short month, short year)
    {
        _Day = day; _Month = month; _Year = year;
    }

    void SetDate(short day, short month, short year,
        short hour, short minute, short second)
    {
        _Day = day; _Month = month; _Year = year;
        _Hour = hour; _Minute = minute; _Second = second;
    }

    short Day() const { return _Day; }
    short Month() const { return _Month; }
    short Year() const { return _Year; }
    short Hour() const { return _Hour; }
    short Minute() const { return _Minute; }
    short Second() const { return _Second; }

    static bool IsLeapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
    }

    void Print()
    {
        cout << DateToString();
    }

    void Print(string Date)
    {
        cout << Date;
    }

    void Print(short day, short month, short year)
    {
        cout << day << '/' << month << '/' << year;
    }

    void Print(short Days, short Year)
    {
        YearAddDays(Days, Year);
    }


    short CountDaysFromYearStart(short Year, short Month, short day)
    {
        short CountDays = 0;
        for (short i = 1; i <= Month - 1; i++)
            CountDays += NumberOfDaysInAMonth(i, Year);

        return CountDays + day;
    }

    void YearAddDays(short Days, short Year)
    {
        _Year = Year; _Month = 1; _Day = 1;

        short RemainingDays = Days;

        while (RemainingDays > 0)
        {
            short DaysInCurrentMonth = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > DaysInCurrentMonth)
            {
                RemainingDays -= DaysInCurrentMonth;
                _Month++;
                if (_Month > 12) { _Month = 1; _Year++; }
            }
            else
            {
                _Day = RemainingDays;
                RemainingDays = 0;
            }
        }

        cout << _Day << '/' << _Month << '/' << _Year;
    }

    static short DayOfWeekOrder(const clsDate& Date)
    {
        short a, y, m;
        a = (14 - Date._Month) / 12;
        y = Date._Year - a;
        m = Date._Month + (12 * a) - 2;
        return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        return (Month > 12 || Month < 1) ? 0 :
            (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 :
            (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : 31;
    }

    static string MonthShortName(short Month)
    {
        string Months[] =
        {
            "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        return Months[Month];
    }


    static bool IsValid(const clsDate& Date)
    {
        if (Date._Day < 1 || Date._Day > 31) return false;
        if (Date._Month < 1 || Date._Month > 12) return false;

        if (Date._Month == 2)
        {
            if (IsLeapYear(Date._Year) && Date._Day > 29) return false;
            if (!IsLeapYear(Date._Year) && Date._Day > 28) return false;
        }
        else
        {
            short dim = NumberOfDaysInAMonth(Date._Month, Date._Year);
            if (Date._Day > dim) return false;
        }

        return true;
    }

    bool IsValid()
    {
        return IsValid(*this);
    }


    static void PrintMonthCalendar(short Year, short Month)
    {
        clsDate FirstDay{ 1, Month, Year };
        short DayOrder = DayOfWeekOrder(FirstDay);
        short Days = NumberOfDaysInAMonth(Month, Year);
        short counter = 0;

        printf("\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ %s _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n",
            MonthShortName(Month).c_str());

        cout << left << setw(10) << "Sun" << setw(10) << "Mon" << setw(10) << "Tue" << setw(10) << "Wed"
            << setw(10) << "Thu" << setw(10) << "Fri" << setw(10) << "Sat" << endl << endl;

        for (short i = 0; i < DayOrder; i++)
            cout << setw(10) << " ";

        for (short day = 1; day <= Days; day++)
        {
            cout << setw(10) << day;
            counter++;
            if ((DayOrder + counter) % 7 == 0)
                cout << endl;
        }

        cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Year, _Month);
    }

    static void PrintYearCalendar(short Year)
    {
        printf("\t\t  _______________________________\n\n");
        printf("\t\t           Calendar - %d      \n\n", Year);
        printf("\t\t  _______________________________\n\n");

        for (short i = 1; i <= 12; i++)
            PrintMonthCalendar(Year, i);
    }

    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static bool IsLastDayInMonth(const clsDate& Date)
    {
        return Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return Month == 12;
    }

    static clsDate IncreaseDateByOneDay(const clsDate& Date)
    {
        clsDate newDate = Date;

        if (IsLastDayInMonth(newDate) && IsLastMonthInYear(newDate._Month))
        {
            newDate._Year++;
            newDate._Month = 1;
            newDate._Day = 1;
        }
        else if (IsLastDayInMonth(newDate))
        {
            newDate._Month++;
            newDate._Day = 1;
        }
        else
        {
            newDate._Day++;
        }
        // لا نلمس الوقت هنا (نبقيه كما هو)
        return newDate;
    }

    static bool IsDateEqual(const clsDate& Date1, const clsDate& Date2)
    {
        return Date1._Year == Date2._Year &&
            Date1._Month == Date2._Month &&
            Date1._Day == Date2._Day;
    }

    bool IsDateEqual(const clsDate& Date2)
    {
        return IsDateEqual(*this, Date2);
    }

    static bool IsDateBefore(const clsDate& Date1, const clsDate& Date2)
    {
        return (Date1._Year < Date2._Year) ? true :
            (Date1._Year == Date2._Year && Date1._Month < Date2._Month) ? true :
            (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day < Date2._Day);
    }

    bool IsDateBefore(const clsDate& Date2)
    {
        return IsDateBefore(*this, Date2);
    }

    static bool IsDateAfter(const clsDate& Date1, const clsDate& Date2)
    {
        return (!IsDateBefore(Date1, Date2)) && (!IsDateEqual(Date1, Date2));
    }

    bool IsDateAfter(const clsDate& Date2)
    {
        return IsDateAfter(*this, Date2);
    }


    static int CalculateAgeInDays(clsDate BirthDate, const clsDate& CurrentDate)
    {
        if (IsDateAfter(BirthDate, CurrentDate))
            return -1;

        int days = 0;
        clsDate tempDate = BirthDate;

        while (!IsDateEqual(tempDate, CurrentDate))
        {
            tempDate = IncreaseDateByOneDay(tempDate);
            days++;
        }
        return days;
    }

    int CalculateAgeInDays(clsDate Date)
    {
        clsDate CurrentDate = clsDate::GetSystemDate();
        return CalculateAgeInDays(Date, CurrentDate);
    }

    bool IsWeekEnd()
    {
        short dow = DayOfWeekOrder(*this);
        return dow == 5 || dow == 6;
    }

    bool IsBusinessDay()
    {
        return !IsWeekEnd();
    }

    short CalculateVacationsDaysAndWeekend(short AddDays)
    {
        short CountVacation = 0;
        clsDate tempDate = *this;

        while (tempDate.IsWeekEnd())
            tempDate = IncreaseDateByOneDay(tempDate);

        for (short i = 0; i < AddDays + CountVacation; i++)
        {
            if (tempDate.IsWeekEnd())
                CountVacation++;
            tempDate = IncreaseDateByOneDay(tempDate);
        }

        while (tempDate.IsWeekEnd())
            tempDate = IncreaseDateByOneDay(tempDate);

        return CountVacation;
    }

    static vector<string> SplitString(string s1, string delim = " ")
    {
        size_t pos = 0; string sword;
        vector<string> vString;
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            sword = s1.substr(0, pos);
            if (!sword.empty()) vString.push_back(sword);
            s1.erase(0, pos + delim.length());
        }
        if (!s1.empty()) vString.push_back(s1);
        return vString;
    }

    static clsDate StringToDate(string DateString)
    {

        vector<string> v = SplitString(DateString, "/");
        clsDate Date;
        if (v.size() >= 3)
        {
            Date._Day = static_cast<short>(stoi(v[0]));
            Date._Month = static_cast<short>(stoi(v[1]));
            Date._Year = static_cast<short>(stoi(v[2]));
        }
        return Date;
    }
 
    static string DateToString(const clsDate& Date)
    {
        ostringstream oss;
        oss << Date._Day << '/' << Date._Month << '/' << Date._Year;
        return oss.str();
    }

    string DateToString() const
    {
        return DateToString(*this);
    }

    string TimeToString() const
    {
        ostringstream oss;
        oss << setfill('0')
            << setw(2) << _Hour << ':'
            << setw(2) << _Minute << ':'
            << setw(2) << _Second;
        return oss.str();
    }

    string DateTimeToString() const
    {
        ostringstream oss;
        oss << _Day << '/' << _Month << '/' << _Year << ' '
            << setfill('0') << setw(2) << _Hour << ':'
            << setw(2) << _Minute << ':'
            << setw(2) << _Second;
        return oss.str();
    }

    static void IncreaseDateByXDays(clsDate& Date, short Days)
    {
        for (short i = 0; i < Days; i++)
            Date = IncreaseDateByOneDay(Date);
    }

    void IncreaseDateByXDays(short Days)
    {
        IncreaseDateByXDays(*this, Days);
    }

    static void IncreaseDateByXWeeks(clsDate& Date, short Weeks)
    {
        IncreaseDateByXDays(Date, static_cast<short>(Weeks * 7));
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(*this, Weeks);
    }

    static void IncreaseDateByXMonths(clsDate& Date, short Months)
    {
        Date._Month += Months;
        while (Date._Month > 12)
        {
            Date._Month -= 12;
            Date._Year++;
        }

        short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > DaysInMonth)
            Date._Day = DaysInMonth;
    }

    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(*this, Months);
    }

    enum enCheckDates { Before = -1, Equal = 0, After = 1 };

    static enCheckDates CompareDates(const clsDate& Date1, const clsDate& Date2)
    {
        if (IsDateBefore(Date1, Date2)) return enCheckDates::Before;
        if (IsDateEqual(Date1, Date2))  return enCheckDates::Equal;
        return enCheckDates::After;
    }

    enCheckDates CompareDates(const clsDate& Date2)
    {
        return CompareDates(*this, Date2);
    }

    friend class clsInputValidate;

    static clsDate GetSystemDate()
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime;
#ifdef _WIN32
        localtime_s(&localTime, &currentTime); 
#else
        localtime_r(&currentTime, &currentTime); 
        localtime_r(&currentTime, &localTime);   
#endif

        return clsDate(
            static_cast<short>(localTime.tm_mday),
            static_cast<short>(localTime.tm_mon + 1),
            static_cast<short>(localTime.tm_year + 1900),
            static_cast<short>(localTime.tm_hour),
            static_cast<short>(localTime.tm_min),
            static_cast<short>(localTime.tm_sec)
        );
    }

    static string GetCurrentDateTimeString()
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime;
#ifdef _WIN32
        localtime_s(&localTime, &currentTime);
#else
        localtime_r(&currentTime, &currentTime); 
#endif

        ostringstream oss;
        oss << put_time(&localTime, "%d-%m-%Y %H:%M:%S");
        return oss.str();
    }

};
