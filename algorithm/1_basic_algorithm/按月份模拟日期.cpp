#include <iostream>

using namespace std;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekday[7];

int main()
{
    int n, year = 1900, day = 0;
    cin >> n;
    while (n --)
    {
        for (int i = 1; i <= 12; i ++)
        {
            weekday[(day + 12) % 7] ++;

            day += month[i];
            
            if (i == 2 && (year % 4 == 0 && year % 100 || year % 400 == 0)) day++;
        }
    year ++;
    }
    
    for (int i = 0, j = 5; i < 7; i ++, j ++) cout << weekday[j % 7] << ' ';
    cout << endl;

    return 0;
}