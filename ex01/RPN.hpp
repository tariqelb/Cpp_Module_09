/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/27 19:19:39 by tel-bouh         ###   ########.fr       */
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
		Rpn(const Rpn& rhs);
		Rpn&	operator=(const Rpn& rhs);
		~Rpn();

		std::list<std::string>	GetExpr(void) const;
		void					FillExpr(char *arg);
		int						CheckForErrors(void);
		void					DisplayResult(void);
};

#endif
