#include"class.h"

int main()
{
	Date date1(2000, 2, 24);
	Date date(2023, 2, 7);
	//����-����
	std::cout << date1 - date << std::endl;
	//����+����
	std::cout << (date1 += 8384);
	//++����(ǰ��++)
	std::cout << ++date1 ;
	//����++
	std::cout << date1++;
	//����-����
	std::cout << (date - 8384);
	return 0;
}