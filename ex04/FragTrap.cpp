/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:06:33 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 17:28:51 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) {
	_name = name;
	_hp = 100;
	_max_hp = 100;
	_energy = 100;
	_max_energy = 100;
	_level = 1;
	_melee_attack = 30;
	_range_attack = 20;
	_armor_dam_reduct = 5;
	_class_name = typeid(*this).name();
	_class_name = _class_name.substr(1, _class_name.length());
	std::cout<<BOLDCYAN<<"Transforming ClapTrap into FragTrap!"<<RESET;
	std::cout<<GREEN<<" ("<<name<<") ";
	std::cout<<RESET<<std::endl;
}

FragTrap::~FragTrap(){ 
	std::cout<<BOLDCYAN<<"FragTrap "<<RESET<<GREEN<<"("<<_name;
	std::cout<<")"<<BOLDCYAN<<"transforming back into ClapTrap";
	std::cout<<RESET<<std::endl;
}

int	FragTrap::_funny_attack( int const amount, std::string const text,
		std::string const & target ){
	std::cout<<_class_name<<" ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<BLUE<<text;
	std::cout<<RED<<amount<<RESET<<" points of damage (current energy: ";
	if (_energy > 60)
		std::cout<<GREEN;
	else if (_energy > 30)
		std::cout<<YELLOW;
	else
		std::cout<<RED;
	std::cout<<_energy<<")"<<RESET<<std::endl;
	return (amount);
}

int	FragTrap::vaulthunter_dot_exe( std::string const & target ){
	_target = target;
	int	i = rand() % 15;
	if (_energy - 25 < 0)
		std::cout<<"Not enough energy. Current energy: "<<_energy<<std::endl;
	else{
		if (i >= 0 && i <= 5)
			i = _funny_attack(19, " wingardium leviosa ", target);
		else if (i > 5 && i <= 9)
			i = _funny_attack(25, " BONK ", target);
		else if (i > 9 && i < 11)
			i = _funny_attack(31, " fart ", target);
		else if (i >= 11 && i < 14)
			i = _funny_attack(6, " kick ", target);
		else if (i >= 14)
			i = _funny_attack(200, " ХДЫЩЬ! ", target);
		_energy -= 25;
		return (i);
	}
	return (0);
}

std::ostream & operator << (std::ostream & o, FragTrap const & input){
	std::cout<<"current hp: ";
	if (input.get_hp() > 60)
		std::cout<<GREEN;
	else if (input.get_hp() > 30)
		std::cout<<YELLOW;
	else
		std::cout<<RED;
	return (o << input.get_hp()<<RESET);
}