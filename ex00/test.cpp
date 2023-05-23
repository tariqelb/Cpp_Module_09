#include <string>
#include <iostream>

int	main()
{
	std::string str = "hi";
	try
	{
	//std::string tmp = str.substr(2, 12);	
	std::string tmp = str.substr(3, 0);	
	//std::string tmp = str.substr(155, 6);
	}
	catch (std::out_of_range &e)
	{
		std::cout << "catch " << std::endl;
	}
	return (0);
}
