/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 06:57:42 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 13:25:14 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "FragTrap.hpp"
# include <iostream>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


class ScavTrap {

public:

	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src);
	~ScavTrap();

	ScavTrap &	operator = ( ScavTrap const & value );
	int			rangedAttack( std::string const & target );
	int			meleeAttack( std::string const & target );
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );
	void		challengeNewcomer();

	int			get_hp() const;
	int			get_max_hp() const ;
	int			get_energy() const ;
	int			get_max_energy() const ;
	int			get_level() const ;
	std::string	get_name() const ;
	int			get_melee_attack() const ;
	int			get_range_attack() const ;
	int			get_armor_reduct() const ;

private:

	int			_hp;
	int			_max_hp;
	int			_energy;
	int 		_max_energy;
	int			_level;
	std::string	_name;
	int			_melee_attack;
	int			_range_attack;
	int			_armor_dam_reduct;

};

std::ostream & operator << (std::ostream & o, ScavTrap const & input);

#endif