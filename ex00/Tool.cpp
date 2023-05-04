/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:44:59 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/04 19:32:33 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	ValidDate(std::string date)
{
	int i;
	int j;
	int size;
	int year;
	int month;
	int	day;
	int	val;

	i = 0;
	size = date.size();
	while (i < size && isdigit(date[i]))
		i++;
	if (i != 4)
		return (0);
	if (date[i] != '-')
		return (0);
	try {
		val = std::stoi((date.substr(0, i)));
	}
	catch (std::invalid_argument& e) {
		return (0);
	}
	year = std::stoi((date.substr(0, i)).c_str());
	if (year < 1)
		return (0);
	i++;
	j = 0;
	while (i + j < size && isdigit(date[i + j]))
		j++;
	if (j != 2)
		return (0);
	if (date[i + j] != '-')
		return (0);
	try {
		val = std::stoi((date.substr(i, 2)));
	}
	catch (std::invalid_argument& e) {
		return (0);
	}
	month = std::stoi(date.substr(i, 2));
	if (month < 1 || month > 12)
		return (0);
	i = i + 3;
	j = 0;
	while (i + j < size && isdigit(date[i + j]))
		j++;
	if (j != 2)
		return (0);
	if (date[i + j] != '\0')
		return (0);
	try {
		val = std::stoi((date.substr(i, 2)));
	}
	catch (std::invalid_argument& e) {
		return (0);
	}
	day = std::stoi(date.substr(i, 2));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
			return (0);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			return (0);
	}
	if (month == 2)
		if (day < 0 || day > 28)
			return (0);
	return (1);
}


int ValidFloatNumber(std::string nbr, std::string line)
{
	int i;
	int size;
	int decimal;
	int notadigit;

	i = 0;
	decimal = 0;
	notadigit = 0;
	size = nbr.size();
	while (i < size && nbr[i] == ' ')
		i++;
	if (nbr[i] == '.')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (0);
	}
	if (nbr[i] == '-')
	{
		std::cerr << "Error: not a positve number." << std::endl;
		return (0);
	}
	while (i < size)
	{
		if (nbr[i] == '.')
			decimal++;
		else if (isdigit(nbr[i]) == 0)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			return (0);
		}
		i++;
	}
	if (decimal > 1)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (0);
	}
	i = 0;
	while (i < size && nbr[i] != '.')
		i++;
	if (i > 3)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

int	ValidValue(std::string value, std::string line)
{
	int		i;
	float	val;

	i = 0;
	if (ValidFloatNumber(value, line))
	{
		try
		{
			val = std::stof(value);
		}
		catch (const std::invalid_argument& ex)
		{
			std::cerr << "Error: bad input 1=> " << line << std::endl;
			return (0);
		}
		catch (const std::out_of_range& ex)
		{
			std::cerr << "Error: bad input 2=> " << line << std::endl;
			return (0);
		}
		return (1);
	}
	return (0);

}

std::pair<std::string, float>		CheckForErrors(std::string line)
{
	std::string						date;
	std::string						rate;
	int								i;
	int								j;
	int								size;
	std::pair<std::string, float>	pr;

	pr.first.assign("");
	size = line.size();
	j = 0;
	i = 0;
	while (i < size && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (i + j < size && line[i + j] != ' ' && line[i + j] != '|' && line[i] != '\t')
		j++;
	if (j)
		date = line.substr(i, j);
	else
		date.assign("");
	if (j == 0 || ValidDate(date) == 0)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (pr);
	}
	i += j;
	while (i < size && (line[i] == ' ' || line[i] == '|' || line[i] == '\t'))
		i++;
	j = 0;
	while (i + j < size)
		j++;
	while (j && (line[i + j - 1] == ' ' || line[i + j - 1] == '\t'))
		j--;
	if (j > 0)
		rate = line.substr(i , j);
	else
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (pr);
	}
	if (ValidValue(rate, line))
	{
		pr.first = date;
		pr.second = std::stof(rate);
		return (pr);
	}
	return (pr);
}



