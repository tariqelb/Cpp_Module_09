/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:39:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/17 00:42:17 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int	main(int ac, char **av)
{
	BitcoinExchange bitcoin;

	std::ifstream file;
	if (ac == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	if (ac > 2)
	{
		std::cerr << "Error: too many arguments." << std::endl;
		return (-1);
	}
	file.open(av[1]);
	if (file.is_open() == 0)
	{
		std::cerr << "Error : Fail to open file : " << av[1] << "." <<std::endl;
		return (-1);
	}
	bitcoin.FillData(file);
	bitcoin.ValueOfBitcoin();
	file.close();
	return (0);
}
