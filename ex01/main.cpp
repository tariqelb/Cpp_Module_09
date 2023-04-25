/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:23:40 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/24 00:59:29 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	Rpn	expr;
	
	if (ac != 2)
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}
	expr.FillExpr(av[1]);
	if (expr.CheckForErrors())
		return (1);
	expr.DisplayResult();
	return (0);
}
