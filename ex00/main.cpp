#include "easyfind.hpp"

int main()
{
	try
	{
		// vectorでテスト
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);


		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;

		// listでテスト
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		std::list<int>::iterator it2 = easyfind(lst, 30);
		std::cout << "Found: " << *it2 << std::endl;

		// const vectorでテスト
		const std::vector<int> constVec(vec.begin(), vec.end());

		std::vector<int>::const_iterator it3 = easyfind(constVec, 3);
		std::cout << "Found: " << *it3 << std::endl;

		// 存在しない値でテスト
		it = easyfind(vec, 6);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}