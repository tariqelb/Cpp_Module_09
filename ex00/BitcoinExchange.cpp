/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:01:55 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/20 01:08:25 by tel-bouh         ###   ########.fr       */
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
		i = 0;
		size = this->line.size();
		while (i < size)
		{
			this->line[i] = rhs.line[i];
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

std::string	BitcoinExchange::GetValue(unsigned int index)
{
	std::string empty;

	if (index < this->value.size())
	{
		return (this->value[index]);
	}
	return (empty);
}

void	SkipWhiteSpace(std::string line, int& i)
{
	int	size;

	size = line.size();
	while (i < size && line[i] == ' ')
		i++;
}


void	BitcoinExchange::FillData(std::ifstream& file)
{
	std::string line;
	int			i;
	int			j;
	int			size;
	std::string	del;

	del.assign(",\t;|:");
	std::cout << "FillData member function called" << std::endl;
	getline(file, line);
	i = 0;
	if (line.find("date") >= 0)
	{
		std::string	del;
		i = line.find("date") + 4;
		size = line.size();
		while (i < size && line[i] == ' ')
			i++;
		if (i == size)
		{
			std::cerr << "Error: invalide CSV format." << std::endl;
			return ;
		}
		if (del.find(line[i]) >= 0)
			del.assign(1, line[i]);
		else
		{
			std::cerr << "Error: invalide CSV format." << std::endl;
			return ;
		}
	}
	else
	{
		std::cerr << "Error: invalide CSV format." << std::endl;
		return ;
	}
	while (getline(file, line))
	{
		if (line.size())
		{
			this->line.push_back(line);
			i = 0;
			size = line.size();
			SkipWhiteSpace(line, i);
			j = 0;
			while (i + j < size && line[i + j] != del[0] && line[i + j] != ' ')
				j++;
			if (j)
				this->date.push_back(line.substr(i, j));
			else
				this->date.push_back("Unvalid");
			i = i + j;
			SkipWhiteSpace(line, i);
			if (i < size && line[i] == del[0])
				this->delemiter.push_back(line.substr(i, 1));
			else
				this->delemiter.push_back("Unvalid");
			i++;
			SkipWhiteSpace(line, i);
			j = 0;
			while (i + j < size && line[i + j] != ' ')
				j++;
			if (j)
				this->value.push_back(line.substr(i, j));
			else
				this->value.push_back("Unvalid");
		}	
	}
}


int	ValidDate(std::string date)
{
	int i;
	int j;
	int size;
	int year;
	int month;
	int	day;

	i = 0;
	size = date.size();
	while (i < size && isdigit(date[i]))
		i++;
	if (i != 4)
		return (0);
	if (date[i] != '-')
		return (0);
	year = atoi((date.substr(0, i)).c_str());
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
	month = atoi(date.substr(i, 2).c_str());
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
	day = atoi(date.substr(i, 2).c_str());
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
	if (nbr[0] == '.')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
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
			std::cerr << "Error: bad input => " << line << std::endl;
			return (0);
		}
		return (1);
	}
	return (0);

}

void	BitcoinExchange::ValueOfBitcoin(void)
{
	std::cout << "ValueOfBitcoin member function called" << std::endl;
	int		i;
	int		size;
	float	val;

	i = 0;
	size = this->date.size();
	while (i < size)
	{
		if (ValidDate(this->date[i]))
		{
			if (this->delemiter[i] == "Unvalid")
				std::cerr << "Error: bad input => " << this->line[i] << std::endl; 
			else
			{
				if (this->value[i] == "Unvalid")
					std::cerr << "Error: bad input => " << line[i] << std::endl; 
				else if (this->value[i][0] == '-')
					std::cerr << "Error: not a positive number." << std::endl; 
				else if (ValidValue(this->value[i], this->line[i]))
				{
					val = std::stof(this->value[i]) / X;
					std::cout << this->date[i] << " => " << this->value[i] << " = " << val << std::endl;
				}
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << this->line[i] << std::endl;
		}
		i++;
	}
}
		//std::cout << "Data : [" << this->date[i] << "][" << this->delemiter[i] << "][" << this->value[i] << "]" << std::endl;
