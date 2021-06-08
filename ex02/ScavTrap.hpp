/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 06:57:42 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 15:43:02 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "FragTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( std::string name );
	~ScavTrap();

	void		challengeNewcomer();

};

std::ostream & operator << (std::ostream & o, ScavTrap const & input);

#endif