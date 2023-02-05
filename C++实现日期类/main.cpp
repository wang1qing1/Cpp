#include"class.h"

int main()
{
	Date date1(2023, 2, 4);
	Date date(3056, 1, 14);
	//date1.ShowDate();
	//Date date2(date1);
	//date2.ShowDate();
	//date1.After_X_Day_fmy(500);
	//date1.ShowDate();
	//printf("%d\n", date1 > date);
	//cout << date - date1 << endl;
	Date date3 = date - 377274;
	date3.ShowDate();
	return 0;
}