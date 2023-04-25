/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/24 02:39:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>
#include <cctype>
//#include <>

class	Rpn
{
	private:
		std::list<std::string>	expr;

	public:
		Rpn();
		Rpn(Rpn& rhs);
		Rpn&	operator=(Rpn& rhs);
		~Rpn();

		std::list<std::string>	GetExpr(void);
		void					FillExpr(char *arg);
		int						CheckForErrors(void);
		void					DisplayResult(void);
};

#endif
