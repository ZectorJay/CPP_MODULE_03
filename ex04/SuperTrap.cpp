/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:35:05 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 17:53:41 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap( std::string name ) : NinjaTrap(name), FragTrap(name) {
	_name = name;
	_class_name = "SuperTrap";
	_hp = FragTrap::_hp;
	_max_hp = FragTrap::_max_hp;
	_max_energy = NinjaTrap::_max_energy;
	_energy = NinjaTrap::_energy;
	_level = 1;
	_melee_attack = NinjaTrap::_melee_attack;
	_range_attack = FragTrap::_range_attack;
	_armor_dam_reduct = FragTrap::_armor_dam_reduct;
	std::cout<<BOLDYELLOW<<_class_name<<" HAS BEEN BUILD!!!"<<RESET<<std::endl;
}

SuperTrap::~SuperTrap(){
	std::cout<<YELLOW<<_class_name<<" transforming back into NinjaTrap and FragTrap";
	std::cout<<RESET<<std::endl;
}

int		SuperTrap::meleeAttack( std::string const & target ){
	return (NinjaTrap::meleeAttack(target));
}

int		SuperTrap::rangedAttack( std::string const & target){
	return (FragTrap::rangedAttack(target));
}
