#include"class.h"

int main()
{
	Date date1(2000, 2, 24);
	Date date(2023, 2, 7);
	//日期-日期
	std::cout << date1 - date << std::endl;
	//日期+天数
	std::cout << (date1 += 8384);
	//++日期(前置++)
	std::cout << ++date1 ;
	//日期++
	std::cout << date1++;
	//日期-天数
	std::cout << (date - 8384);
	return 0;
}