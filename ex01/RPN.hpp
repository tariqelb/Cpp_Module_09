/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/22 01:11:47 by tel-bouh         ###   ########.fr       */
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
		Rpn(Rpn&	rhs);
		Rpn&	operator=(Rpn& rhs);
		~Rpn();

		void			FillExpr(char *arg);
		void			DisplayResult(void);
		int				Size(void);
		void			PushFront(std::string& val);
		void			PushBack(std::string& val);
		void			PopFront(void);
		void			PopBack(void);
		std::string&	Front(void);
};

#endif
