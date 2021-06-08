/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:32:37 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 17:49:09 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "NinjaTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap {
	
public:

	SuperTrap( std::string name );
	~SuperTrap();

	int	meleeAttack( std::string const & target);
	int	rangedAttack( std::string const & target);

};


#endif