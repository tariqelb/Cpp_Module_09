/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:39:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/24 19:21:51 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange bitcoin;
	std::ifstream data_file;
	std::ifstream input_file;
	char	database[11] = "./data.csv";

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
	input_file.open(av[1]);
	if (input_file.is_open() == 0)
	{
		std::cerr << "Error : Fail to open file : " << av[1] << "." <<std::endl;
		return (-1);
	}
	data_file.open("./data.csv");
	if (data_file.is_open() == 0)
	{
		std::cerr << "Error : Fail to open file : data.csv" <<std::endl;
		input_file.close();
		return (-1);
	}
	if (bitcoin.IsEmptyFiles(database, av[1]) == 0)
	{
		bitcoin.GetDatabase(data_file);
		bitcoin.Display(input_file);
	}
	input_file.close();
	data_file.close();
	return (0);
}
