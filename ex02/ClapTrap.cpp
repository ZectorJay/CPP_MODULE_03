/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:48:00 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 14:41:54 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name) {
	std::cout<<BOLDGREEN<<"ClapTrap has been built"<<RESET<<std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout<<BOLDRED<<"ClapTrap has been destroyed"<<RESET<<std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src){
	std::cout<<BOLDRED<<"ClapTrap has been cloned from another one";
	std::cout<<RESET<<std::endl;
	*this = src;
}

ClapTrap &	ClapTrap::operator= (ClapTrap const & src){
	if (this != &src){
		_hp = src._hp;
		_max_hp = src._max_hp;
		_energy = src._energy;
		_max_energy = src._max_energy;
		_level = src._level;
		_name = src._name;
		_melee_attack = src._melee_attack;
		_range_attack = src._range_attack;
		_armor_dam_reduct = src._armor_dam_reduct;
	}
	return (*this);
};

int		ClapTrap::get_hp() const { return (_hp); }

std::ostream & operator << (std::ostream & o, ClapTrap const & input){
	std::cout<<"current hp: ";
	if (input.get_hp() > 60)
		std::cout<<GREEN;
	else if (input.get_hp() > 30)
		std::cout<<YELLOW;
	else
		std::cout<<RED;
	return (o << input.get_hp()<<RESET);
}

int			ClapTrap::rangedAttack( std::string const & target ){
	std::cout<<"ClapTrap ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at range, causing ";
	std::cout<<RED<<_range_attack<<RESET<<" points of damage"<<std::endl;
	return (_range_attack);
}

int			ClapTrap::meleeAttack( std::string const & target ){
	std::cout<<"ClapTrap ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at melee, causing ";
	std::cout<<RED<<_melee_attack<<RESET<<" points of damage"<<std::endl;
	return (_melee_attack);
}

void		ClapTrap::beRepaired( unsigned int amount ){
	if (_hp + amount > _max_hp)
		amount = _max_hp - _hp;
	std::cout<<"ClapTrap ("<<GREEN<<_name<<RESET<<") repaired for ";
	std::cout<<GREEN<<amount<<RESET<<" hit points (";
	_hp += amount;
	std::cout<<*this<<")"<<std::endl;
}

void		ClapTrap::takeDamage( unsigned int amount ){
	int		damage_taken;
	if (_armor_dam_reduct > amount)
		damage_taken = 0;
	else if (_armor_dam_reduct < amount)
		damage_taken = amount - _armor_dam_reduct;
	if (damage_taken > _hp)
		damage_taken = _hp;
	if (damage_taken != _hp){
		std::cout<<"ClapTrap ("<<GREEN<<_name<<RESET<<") take ";
		std::cout<<RED<<damage_taken<<RESET<<" amount of damage (";
	}
	else
		std::cout<<"ClapTrap ("<<GREEN<<_name<<BOLDWHITE<<") destroyed ("<<RESET;
	_hp -= damage_taken;
	std::cout<<*this<<")"<<std::endl;
}