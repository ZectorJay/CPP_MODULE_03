/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 07:51:55 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 16:03:01 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) { 
	_name = name;
	_hp = 100;
	_max_hp = 100;
	_energy = 50;
	_max_energy = 100;
	_level = 1;
	_melee_attack = 20;
	_range_attack = 15;
	_armor_dam_reduct = 3;
	_class_name = typeid(*this).name();
	_class_name = _class_name.substr(1, _class_name.length());
	std::cout<<BOLDCYAN<<"Transforming ClapTrap into ScavTrap!"<<RESET;
	std::cout<<GREEN<<" ("<<name<<") ";
	std::cout<<RESET<<std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout<<BOLDCYAN<<"ScavTrap "<<RESET<<GREEN<<"("<<_name;
	std::cout<<")"<<BOLDCYAN<<"transforming back into ClapTrap";
	std::cout<<RESET<<std::endl;
};

std::ostream & operator << (std::ostream & o, ScavTrap const & input){
	std::cout<<"current hp: ";
	if (input.get_hp() > 60)
		std::cout<<GREEN;
	else if (input.get_hp() > 30)
		std::cout<<YELLOW;
	else
		std::cout<<RED;
	return (o << input.get_hp()<<RESET);
}

void		ScavTrap::challengeNewcomer(){
	int	i = rand() % 5;
	std::cout<<GREEN<<_name<<": "<<RED;
	if (i == 0)
		std::cout<<"Come at me, bro!";
	else if (i == 1)
		std::cout<<"Prove yourself worthy of joining RedBelly's band of scavs!";
	if (i == 2)
		std::cout<<"You really think you can beat me?!?!";
	if (i == 3)
		std::cout<<"Chickened out? Pussy! Cluck-cluck-cluck!";
	if (i == 4)
		std::cout<<"You are not worty to challenge me!";
	std::cout<<RESET<<std::endl;
}
