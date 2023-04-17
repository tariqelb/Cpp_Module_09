/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:43:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/17 01:20:26 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include <cctype>
# define X 3.33

class BitcoinExchange
{
	private :
		std::vector<std::string>	date;
		std::vector<std::string>	delemiter;
		std::vector<int>			value;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange& rhs);
		BitcoinExchange&	operator=(BitcoinExchange& rhs);
		~BitcoinExchange();

		std::string	GetDate(unsigned int index);
		std::string	GetDelemiter(unsigned int index);
		int			GetValue(unsigned int index);
		void		FillData(std::ifstream& file);
		void		ValueOfBitcoin(void);
};

#endif
