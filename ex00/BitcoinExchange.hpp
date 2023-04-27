/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:43:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/27 19:29:42 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <queue>
# include <string>
# include <fstream>
# include <cmath>
# define X 3.33


class BitcoinExchange
{
	private :
		std::queue<std::string>	date;
		std::queue<std::string>	delemiter;
		std::queue<std::string>	value;
		std::queue<std::string>	line;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		std::queue<std::string>	GetDate(void) const;
		std::queue<std::string>	GetDelemiter(void) const;
		std::queue<std::string>	GetValue(void) const;
		std::queue<std::string>	GetLine(void) const;
		void					FillData(std::ifstream& file);
		void					ValueOfBitcoin(void);
};

#endif
