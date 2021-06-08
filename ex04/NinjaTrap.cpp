/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:48 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 16:05:23 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap ( std::string name ){
	_name = name;
	_hp = 60;
	_max_hp = 60;
	_energy = 120;
	_max_energy = 120;
	_level = 1;
	_melee_attack = 60;
	_range_attack = 5;
	_armor_dam_reduct = 0;
	_class_name = typeid(*this).name();
	_class_name = _class_name.substr(1, _class_name.length());
	std::cout<<BOLDCYAN<<"Transforming ClapTrap into NinjaTrap!"<<RESET;
	std::cout<<GREEN<<" ("<<name<<") ";
	std::cout<<RESET<<std::endl;
}

NinjaTrap::~NinjaTrap(){
	std::cout<<BOLDCYAN<<"NinjaTrap "<<RESET<<GREEN<<"("<<_name;
	std::cout<<")"<<BOLDCYAN<<"transforming back into ClapTrap";
	std::cout<<RESET<<std::endl;
}

void	NinjaTrap::ninjaShoebox (ClapTrap & clap) const {
	std::cout<<ITALIC<<_name<<": ClapTrap "<<ITALICGREEN<<"("<<clap.get_name()<<") "<<RESET;
	std::cout<<ITALIC<<": has been detected"<<RESET<<std::endl;
}

void	NinjaTrap::ninjaShoebox (FragTrap & frag) const {
	std::cout<<ITALIC<<_name<<": FragTrap "<<ITALICGREEN<<"("<<frag.get_name()<<") "<<RESET;
	std::cout<<ITALIC<<": has been detected"<<RESET<<std::endl;
}

void	NinjaTrap::ninjaShoebox (ScavTrap & scav) const {
	std::cout<<ITALIC<<_name<<": ScavTrap "<<ITALICGREEN<<"("<<scav.get_name()<<") "<<RESET;
	std::cout<<ITALIC<<": has been detected"<<RESET<<std::endl;
}

void	NinjaTrap::ninjaShoebox (NinjaTrap & ninja) const {
	std::cout<<ITALIC<<_name<<": NinjaTrap "<<ITALICGREEN<<"("<<ninja.get_name()<<") "<<RESET;
	std::cout<<ITALIC<<": has been detected"<<RESET<<std::endl;
}