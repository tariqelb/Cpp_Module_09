/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:37:54 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/24 19:20:09 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	Rpn	expr;
	
	if (ac == 1)
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}
	expr.FillExpr(av);
	if (expr.CheckForErrors())
		return (1);
	expr.DisplayResult();
	return (0);
}
