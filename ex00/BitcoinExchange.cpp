/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:01:55 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/17 01:20:39 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructer called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& rhs)
{
	std::cout << "Copy constructer called" << std::endl;
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange& rhs)
{
	std::cout << "Copy assignment called" << std::endl;
	int	i;
	int	size;

	if (this != &rhs)
	{
		//copy data inside data member variable
		i = 0;
		size = this->date.size();
		while (i < size)
		{
			this->date[i] = rhs.date[i];
			i++;
		}
		//copy data inside delemiter member variable
		i = 0;
		size = this->delemiter.size();
		while (i < size)
		{
			this->delemiter[i] = rhs.delemiter[i];
			i++;
		}
		//copy data inside value member variable
		i = 0;
		size = this->value.size();
		while (i < size)
		{
			this->value[i] = rhs.value[i];
			i++;
		}
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default destructer called" << std::endl;
}

std::string	BitcoinExchange::GetDate(unsigned int index)
{
	std::string empty;

	if (index < this->date.size())
	{
		return (this->date[index]);
	}
	return (empty);
}

std::string	BitcoinExchange::GetDelemiter(unsigned int index)
{
	std::string empty;

	if (index < this->delemiter.size())
	{
		return (this->delemiter[index]);
	}
	return (empty);
}

int	BitcoinExchange::GetValue(unsigned int index)
{
	if (index < this->value.size())
	{
		return (this->value[index]);
	}
	return (-1);
}

void	BitcoinExchange::FillData(std::ifstream& file)
{
	std::string line;
	int			i;
	int			size;
	std::string	delemiter;

	delemiter.assign("|");
	std::cout << "FillData member function called" << std::endl;
	(void) file;
	i = 0;
	while (getline(file, line))
	{
		if (i == 0 && line.find("date") >= 0)
		{
			std::string	del = ",;:";
			int j = 0;

			size = line.size();
			while (j < size && (line[j] == ' ' || line[j] == '\t'))
				j++;
			while (j < size && isalpha(line[j]))
				j++;
			while (j < size && (line[j] == ' ' || line[j] == '\t'))
				j++;
			if (del.find(line[j]) >= 0)
				delemiter.assign(1, line[j]);
			i++;
		}
		else
		{
			;
		}

	}
}

void	BitcoinExchange::ValueOfBitcoin(void)
{
	std::cout << "ValueOfBitcoin member function called" << std::endl;
}
