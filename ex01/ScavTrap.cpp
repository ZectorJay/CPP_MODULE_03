/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 07:51:55 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 12:50:54 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : _name(name), _hp(100), _max_hp(100),
_energy(50), _max_energy(100), _level(1), _melee_attack(20), _range_attack(15),
_armor_dam_reduct(3){}

ScavTrap::~ScavTrap(){};

ScavTrap::ScavTrap( ScavTrap const & src ){	*this = src; }

int			ScavTrap::get_hp() const { return(_hp); }

int			ScavTrap::get_max_hp() const { return(_max_hp); }

int			ScavTrap::get_energy() const { return(_energy); }

int			ScavTrap::get_max_energy() const { return(_max_energy); }

int			ScavTrap::get_level() const { return(_level); }

int			ScavTrap::get_melee_attack() const { return(_melee_attack); }

int			ScavTrap::get_range_attack() const { return(_range_attack); }

int			ScavTrap::get_armor_reduct() const { return(_armor_dam_reduct); }

std::string	ScavTrap::get_name() const { return(_name); }

ScavTrap &	ScavTrap::operator = ( ScavTrap const & value){
	if (this != &value)
	{
		_hp = value.get_hp();
		_max_hp = value.get_max_hp();
		_energy = value.get_energy();
		_max_energy = value.get_max_energy();
		_level = value.get_level();
		_name = value.get_name();
		_melee_attack = value.get_melee_attack();
		_range_attack = value.get_range_attack();
		_armor_dam_reduct = value.get_armor_reduct();
	}
	return (*this);
}

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

int			ScavTrap::rangedAttack( std::string const & target ){
	std::cout<<"ScavTrap ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at range, causing ";
	std::cout<<RED<<_range_attack<<RESET<<" points of damage"<<std::endl;
	return (_range_attack);
}

int			ScavTrap::meleeAttack( std::string const & target ){
	std::cout<<"ScavTrap ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at melee, causing ";
	std::cout<<RED<<_melee_attack<<RESET<<" points of damage"<<std::endl;
	return (_melee_attack);
}

void		ScavTrap::beRepaired( unsigned int amount ){
	if (_hp + amount > _max_hp)
		amount = _max_hp - _hp;
	std::cout<<"ScavTrap ("<<GREEN<<_name<<RESET<<") repaired for ";
	std::cout<<GREEN<<amount<<RESET<<" hit points (";
	_hp += amount;
	std::cout<<*this<<")"<<std::endl;
}

void		ScavTrap::takeDamage( unsigned int amount ){
	int		damage_taken;
	if (_armor_dam_reduct > amount)
		damage_taken = 0;
	else if (_armor_dam_reduct < amount)
		damage_taken = amount - _armor_dam_reduct;
	if (damage_taken > _hp)
		damage_taken = _hp;
	if (damage_taken != _hp){
		std::cout<<"ScavTrap ("<<GREEN<<_name<<RESET<<") take ";
		std::cout<<RED<<damage_taken<<RESET<<" amount of damage (";
	}
	else
		std::cout<<"ScavTrap ("<<GREEN<<_name<<BOLDWHITE<<") destroyed ("<<RESET;
	_hp -= damage_taken;
	std::cout<<*this<<")"<<std::endl;
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
