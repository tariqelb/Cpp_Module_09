/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:43:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/21 22:23:30 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include <cctype>
# include <cstdlib>
# include <cmath>
# define X 3.33

class BitcoinExchange
{
	private :
		std::vector<std::string>	date;
		std::vector<std::string>	delemiter;
		std::vector<std::string>	value;
		std::vector<std::string>	line;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange& rhs);
		BitcoinExchange&	operator=(BitcoinExchange& rhs);
		~BitcoinExchange();

		std::string	GetDate(unsigned int index);
		std::string	GetDelemiter(unsigned int index);
		std::string	GetValue(unsigned int index);
		void		FillData(std::ifstream& file);
		void		ValueOfBitcoin(void);
};

#endif
