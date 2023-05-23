/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:40:59 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/23 19:14:46 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float >	data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		const std::map<std::string, float>	GetData(void) const ;
		int									IsEmptyFiles(char *database, char *input);
		int									GetDatabase(std::ifstream& file);
		void								Display(std::ifstream& file);
};

double								toPositiveFloat(std::string);
std::pair<std::string, float>       CheckForErrors(std::string line);
int 								ValidDate(std::string date);

#endif
