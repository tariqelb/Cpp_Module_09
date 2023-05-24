/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:44:59 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/24 14:22:12 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	toInt(std::string nbr)
{
	int i;
	int rst;
	int size;
	int	sign;

	i = 0;
	rst = 0;
	sign = 1;
	size = nbr.size();
	while (i < size)
	{
		rst = rst * 10;
		rst = rst + (nbr[i] - 48);
		i++;
	}
	return (rst * sign);
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
	year = toInt((date.substr(0, i)).c_str());
	if (year < 2009)
		return (0);
	i++;
	j = 0;
	while (i + j < size && isdigit(date[i + j]))
		j++;
	if (j != 2)
		return (0);
	if (date[i + j] != '-')
		return (0);
	month = toInt(date.substr(i, 2));
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
	day = toInt(date.substr(i, 2));
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
	int 	i;
	int 	size;
	int 	decimal;
	int 	notadigit;

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
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
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
	return (1);
}

int	ValidValue(std::string value, std::string line)
{
	int		i;
	float	val;

	i = 0;
	val = 0;
	if (ValidFloatNumber(value, line))
	{
		val = toPositiveFloat(value);
		if (value.size() > 1 &&  value[0] == '-')
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return (0);
		}
		if (val < 0 || val > 1000)
		{
			if (val > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else if (val == -1)
				std::cerr << "Error: bad input => " << line << std::endl;
			return (0);
		}
		return (1);
	}
	return (0);

}

double	toPositiveFloat(std::string	value)
{
	int i;
	int size;
	int dot;
	double frac;
	double rst;
	int	frac_time;

	size = value.size();
	if (size == 0)
	{
		return (-1);
	}
	dot = 0;
	i = 0;
	if (value[0] == '.')
	{
		return (-1);
	}
	if (value[0] == '+')
		value = value.substr(1, value.size() - 1);
	size = value.size();
	if (size == 0)
		return (-1);
	while (i < size)
	{
		if (value[i] >= '0' && value[i] <= '9')
			i++;
		else if (value[i] == '.')
		{
			dot++;
			i++;
		}
		else
		{
			return (-1);
		}
	}
	if (dot > 1)
		return (-1);
	dot = 0;
	rst = 0;
	frac = 0;
	frac_time = 0;
	i = 0;
	while (i < size)
	{
		if (dot == 0 && value[i] != '.')
		{
			rst = rst * 10;
			rst = rst + (value[i] - 48);
		}
		else if (dot == 1 && value[i] != '.')
		{
			frac = frac * 10;
			frac = frac + (value[i] - 48);
			frac_time++;
		}
		else if (value[i] == '.')
			dot = 1;
		i++;
	}
	while (frac_time)
	{
		frac = frac / 10;
		frac_time--;
	}
	rst = rst + frac;
	return  (rst);
}

std::pair<std::string, float>		CheckForErrors(std::string line)
{
	std::string						date;
	std::string						rate;
	int								i;
	int								j;
	int								size;
	float							flag;
	std::pair<std::string, float>	pr;

	flag = 0;
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
	while (i < size && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (i < size && line[i] != '|')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (pr);
	}
	i++;
	while (i < size && (line[i] == ' ' || line[i] == '\t'))
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
		if (rate[0] == '+' || rate[0] == '-')
		{
			i = 1;
			size = rate.size();
			while (i < size)
			{
				if (rate[i] != '0' && rate[i] != '.')
					flag = 1;
				i++;
			}
			if (flag == 0)
				rate.assign("0");
		}
		pr.first = date;
		pr.second = toPositiveFloat(rate);
		return (pr);
	}
	return (pr);
}
