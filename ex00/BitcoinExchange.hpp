/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:43:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/27 15:49:49 by tel-bouh         ###   ########.fr       */
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
		BitcoinExchange(BitcoinExchange& rhs);
		BitcoinExchange&	operator=(BitcoinExchange& rhs);
		~BitcoinExchange();

		std::queue<std::string>	GetDate(void);
		std::queue<std::string>	GetDelemiter(void);
		std::queue<std::string>	GetValue(void);
		std::queue<std::string>	GetLine(void);
		void					FillData(std::ifstream& file);
		void					ValueOfBitcoin(void);
};

#endif
