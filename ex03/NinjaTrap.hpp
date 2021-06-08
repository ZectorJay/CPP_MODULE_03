/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:12 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 15:44:42 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ScavTrap.hpp"
# define ITALICGREEN "\033[1;3;38;2;0;200;0m"
# define ITALIC "\033[1;3m"

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap ( std::string name );
	~NinjaTrap();

	void	ninjaShoebox( ClapTrap & clap) const ;
	void	ninjaShoebox( ScavTrap & scav) const ;
	void	ninjaShoebox( FragTrap & frag) const ;
	void	ninjaShoebox( NinjaTrap & ninja) const ;

};

#endif