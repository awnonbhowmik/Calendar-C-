#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int firstDayofYear(int year) {
	return ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
}

int main() {
	int year;
	cout << "Which year's calendar to print: ";
	cin >> year;

	string month[] = { "January","February","March","April","May","June",
		"July","August","September","October","November","Decemeber" };

	int numDaysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//Case for leap year
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		month[1] = 29;

	int start_day = firstDayofYear(year);

	for (int i = 0; i < sizeof(month) / sizeof(month[0]); i++) {
		cout << "\n\n\t-----------------------" << month[i] << "-----------------------\n";
		cout << "\n\tSun\tMon\tTue\tWed\tThurs\tFri\tSat" << endl;
		
		int days_in_month = numDaysInMonth[i];
		int weekDay = 0;

		for (weekDay = 0; weekDay < start_day; weekDay++)
			cout << "\t";

		for (int day = 1; day <= days_in_month; day++) {

			//cout << setw(4);
			cout << "\t" << day;


			weekDay++;
			if (weekDay == 7) {
				cout << endl;
				weekDay = 0;
			}
			start_day = weekDay;
		}
	}
}