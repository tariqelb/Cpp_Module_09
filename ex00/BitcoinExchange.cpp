/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:03:56 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/05 11:24:24 by tel-bouh         ###   ########.fr       */
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
	if (this != &rhs)
	{
		if (this->data.size())
			this->data.erase(this->data.begin(), this->data.end());
		if (rhs.GetData().size())
			this->data.insert(rhs.GetData().begin(), rhs.GetData().end());
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

const std::map<std::string, float>	BitcoinExchange::GetData(void) const
{
	return (this->data);
}

int		BitcoinExchange::IsEmptyFiles(char *database, char *input)
{
	std::ifstream	data_file;
	std::ifstream	input_file;
	std::string		line;
	unsigned int	rd;

	rd = 0;
	data_file.open(database);
	if (data_file.is_open())
	{
		while (getline(data_file, line))
		{
			rd = rd + line.size();
		}
		if (rd == 0)
		{
			std::cerr << "Error: empty Databse file." << std::endl;
			data_file.close();
			return (1);
		}
		data_file.close();
	}
	line.assign("");
	rd = 0;
	input_file.open(input);
	if (input_file.is_open())
	{
		while (getline(input_file, line))
		{
			rd = rd + line.size();
		}
		if (rd == 0)
		{
			std::cerr << "Error: empty input file." << std::endl;
			input_file.close();
			return (1);
		}
		input_file.close();
	}
	return (0);
}

int		BitcoinExchange::GetDatabase(std::ifstream& file)
{
	std::string		line;
	int				i;
	int				j;
	int				k;
	int				size;

	std::getline(file, line);
	i = line.find("date");
	j = line.find(",");
	k = line.find("exchange_rate");
	if (i < 0 || j < 0 || k < 0)
	{
		std::cerr << "Invalid datebase format." << std::endl;
		return (1);
	}
	else if (i < j && j < k)
		;
	else
	{
		std::cerr << "Invalid datebase format." << std::endl;
		return (1);
	}
	i = 0;
	j = 0;
	k = 0;
	while (std::getline(file, line))
	{
		std::string		date;
		std::string		rate;
		float			nbr;

		i = 0;
		size = line.size();
		while (i < size && (line[i] == ' ' || line[i] == '\t'))
			i++;
		j = 0;
		while (i + j < size && line[i + j] != ',' && line[i + j] != ' ' && line[i] != '\t')
			j++;
		if (j)
			date = line.substr(i, j);
		i += j;
		while (i < size && (line[i] == ' ' || line[i] == ',' || line[i] == '\t'))
			i++;
		j = 0;
		while (i + j < size && (line[i + j] != ' ' || line[i] != '\t'))
			j++;
		if (j)
			rate = line.substr(i, j);
		nbr = 0;
		try
		{
			nbr = std::stof(rate);
		}
        catch (const std::invalid_argument& ex)
        {
			nbr = -1;
		}
        catch (const std::out_of_range& ex)
        {
			nbr = -1;
		}
		if (nbr != -1) 
			this->data.insert(std::make_pair(date, nbr));	
		k++;
	}
	return (0);
}

void	CheckFormat(std::string line)
{
	int	date;
	int pipe;
	int value;

	date = line.find("date");
	pipe = line.find("|");
	value = line.find("value"); 
	if (date < 0 || pipe < 0 || value < 0 )
		std::cerr << "Error: Invalid input format." << std::endl;
	else if (date < pipe && pipe < value)
		return;
	else
		std::cerr << "Error: Invalid input format." << std::endl;
}

void	BitcoinExchange::Display(std::ifstream& file)
{
	std::string								line;
	std::pair<std::string, float>			pr;
	std::map<std::string, float>::iterator	it;

	getline(file, line);
	CheckFormat(line);
	while (std::getline(file, line))
	{
		pr = CheckForErrors(line);
		if (pr.first.size() != 0)
		{
			it  = data.find(pr.first);
			if (it == data.end())
			{
				it = this->data.lower_bound(pr.first);
				if (it == this->data.begin())
				{
					std::cout << pr.first << " => " << pr.second << " = ";
			    	std::cout << pr.second * 0 << std::endl;
				}
				else
				{
					it--;
					std::cout << pr.first << " => " << pr.second << " = ";
					std::cout << it->second * pr.second << std::endl;
				}
			}
			else
			{
				std::cout << pr.first << " => " << pr.second << " = ";
			    std::cout << it->second * pr.second << std::endl;
			}
		}
	}	
}
