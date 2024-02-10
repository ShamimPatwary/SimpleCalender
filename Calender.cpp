#include<iostream>
#include<stdio.h>
#include<time.h>
#include<iomanip>

using namespace std;

int main()
{
    int year,month,daysInmonth,daysOfweek;

    struct tm selectedDate;

    cout<<"\t\t\t###########################################################################";
    cout<<"\n\t\t\t############                                                   ############";
    cout<<"\n\t\t\t############            Simple Calender Application            ############";
    cout<<"\n\t\t\t############                                                   ############";
    cout<<"\n\t\t\t###########################################################################";
    cout<<"\n\t\t\t---------------------------------------------------------------------------\n";
    cout<<"\n\t\t\t----------------------------------------------------------------------------";

    cout<<"\n\t\t\tEnter Year (E.g. 2024) : ";
    cin>>year;
    cout<<"\n\t\t\tEnter Month (1-12): ";
    cin>>month;

    if(month<1 || month>12)
    {
        cout<<"\n\t\t\tInvalid Month. Please Enter Valid Month Between 1 to 12.";
        return 1;
    }

    selectedDate.tm_year = year - 1900;
    selectedDate.tm_mon = month - 1;

    selectedDate.tm_mday = 1;
    selectedDate.tm_hour = 0;
    selectedDate.tm_min = 0;
    selectedDate.tm_sec = 0;

    time_t selectedTime = mktime(&selectedDate);

    if(month==12)
    {
        selectedDate.tm_year++;
        selectedDate.tm_mon = 0;
        daysInmonth = (int) difftime(mktime(&selectedDate),selectedTime) / (86400) ;
    }
    else
    {
        selectedDate.tm_mon++;
        daysInmonth = (int)difftime(mktime(&selectedDate),selectedTime) / (86400);
    }

    daysOfweek = (int)selectedDate.tm_wday;

    cout<<"\n\t\t\tCalender For : "<<month;
    cout<<"/";
    cout<<year;
    cout<<"\n\n";
    cout<<"\n Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    for(int i=0;i<daysOfweek;i++)
    {
        cout<<"    ";
    }
    for(int day=1;day<=daysInmonth;day++)
    {
        cout << setw(5) << day;
        if((daysOfweek+day) % 7 == 6 || day == daysInmonth)
        {
           cout<<"\n\n";
        }
    }
}
