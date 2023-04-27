/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:40:51 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/27 19:29:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	int						i;
	int						size;
	std::queue<std::string>	temp_date;
	std::queue<std::string>	temp_delemiter;
	std::queue<std::string>	temp_value;
	std::queue<std::string>	temp_line;

	if (this != &rhs)
	{
		//free up the object if is not empty
		i = 0;
		size = this->date.size();
		while (i < size)
		{
			this->date.pop();
			i++;
		}
		i = 0;
		size = this->delemiter.size();
		while (i < size)
		{
			this->delemiter.pop();
			i++;
		}
		i = 0;
		size = this->value.size();
		while (i < size)
		{
			this->value.pop();
			i++;
		}
		i = 0;
		size = this->line.size();
		while (i < size)
		{
			this->line.pop();
			i++;
		}
		temp_date = rhs.GetDate();
		// Copy data to the object
		i = 0;
		size = temp_date.size();
		while (i < size)
		{
			this->date.push(temp_date.front());
			temp_date.pop();
			i++;
		}
		temp_delemiter = rhs.GetDelemiter();
		i = 0;
		size = temp_delemiter.size();
		while (i < size)
		{
			this->delemiter.push(temp_delemiter.front());
			temp_delemiter.pop();
			i++;
		}
		temp_value = rhs.GetValue();
		i = 0;
		size = temp_value.size();
		while (i < size)
		{
			this->value.push(temp_value.front());
			temp_value.pop();
			i++;
		}
		temp_line = rhs.GetLine();
		i = 0;
		size = temp_line.size();
		while (i < size)
		{
			this->line.push(temp_line.front());
			temp_line.pop();
			i++;
		}
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::queue<std::string>	BitcoinExchange::GetDate(void) const
{
	return (this->date);
}

std::queue<std::string>	BitcoinExchange::GetDelemiter(void) const
{
	return (this->delemiter);
}

std::queue<std::string>	BitcoinExchange::GetValue(void) const
{
	return (this->value);
}

std::queue<std::string>	BitcoinExchange::GetLine(void) const
{
	return (this->line);
}

void	BitcoinExchange::FillData(std::ifstream& file)
{
	std::string rd_line;
	int			i;
	int			j;
	int			size;
	std::string	del;

	del.assign(",\t;|:");
	getline(file, rd_line);
	i = 0;
	if (rd_line.find("date") >= 0)
	{
		i = rd_line.find("date") + 4;
		size = rd_line.size();
		while (i < size && rd_line[i] == ' ')
			i++;
		if (i == size)
		{
			std::cerr << "Error: invalid CSV format." << std::endl;
			return ;
		}
		if (del.find(rd_line[i]) >= 0)
			del.assign(1, rd_line[i]);
		else
		{
			std::cerr << "Error: invalid CSV format." << std::endl;
			return ;
		}
	}
	else
	{
		std::cerr << "Error: messing CSV format." << std::endl;
		return ;
	}
	while (getline(file, rd_line))
	{
		if (rd_line.size())
		{
			this->line.push(rd_line);
			i = 0;
			size = rd_line.size();
			while (i < size && rd_line[i] == ' ')
				i++;
			j = 0;
			while (i + j < size && rd_line[i + j] != del[0] && rd_line[i + j] != ' ')
				j++;
			if (j)
				this->date.push(rd_line.substr(i, j));
			else
				this->date.push("Invalid");
			i = i + j;
			while (i < size && rd_line[i] == ' ')
				i++;
			if (i < size && rd_line[i] == del[0])
				this->delemiter.push(rd_line.substr(i, 1));
			else
				this->delemiter.push("Invalid");
			i++;
			while (i < size && rd_line[i] == ' ')
				i++;
			j = 0;
			while (i + j < size && rd_line[i + j] != ' ')
				j++;
			if (j)
			{
				int k = j;
				while (i + j < size && rd_line[i + j] == ' ')
					j++;
				if (i + j == size)
					this->value.push(rd_line.substr(i, k));
				else
					this->value.push(rd_line.substr(i, size));
			}
			else
				this->value.push("Invalid");
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
		catch (const std::out_of_range& ex)
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
	int		i;
	int		size;
	float	val;

	i = 0;
	size = this->date.size();
	while (i < size)
	{
		if (ValidDate(this->date.front()))
		{
			if (this->delemiter.front() == "Unvalid")
				std::cerr << "Error: bad input => " << this->line.front() << std::endl;
			else
			{
				if (this->value.front() == "Unvalid")
					std::cerr << "Error: bad input => " << this->line.front() << std::endl;
				else if ((this->value.front())[0] == '-')
					std::cerr << "Error: not a positive number." << std::endl;
				else if (ValidValue(this->value.front(), this->line.front()))
				{
					val = round(std::stof(this->value.front()) / X);
					std::cout << this->date.front() << " => " << this->value.front() << " = " << val << std::endl;
				}
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << this->line.front() << std::endl;
		}
		this->date.push(this->date.front());
		this->date.pop();
		this->delemiter.push(this->delemiter.front());
		this->delemiter.pop();
		this->value.push(this->value.front());
		this->value.pop();
		this->line.push(this->line.front());
		this->line.pop();
		i++;
	}
}




