/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/04 19:21:00 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class	Rpn
{
	private:
		std::stack<std::string>	expr;

	public:
		Rpn();
		Rpn(const Rpn& rhs);
		Rpn&	operator=(const Rpn& rhs);
		~Rpn();

		std::stack<std::string>	GetExpr(void) const;
		void					FillExpr(char *arg);
		int						CheckForErrors(void);
		void					DisplayResult(void);
};

#endif
