/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 07:51:55 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/05 09:19:21 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : _name(name), _hp(100), _max_hp(100),
_energy(100), _max_energy(100), _level(1), _melee_attack(30), _range_attack(20),
_armor_dam_reduct(5){}

FragTrap::~FragTrap(){};

FragTrap::FragTrap( FragTrap const & src ){	*this = src; }

int			FragTrap::get_hp() const { return(_hp); }

int			FragTrap::get_max_hp() const { return(_max_hp); }

int			FragTrap::get_energy() const { return(_energy); }

int			FragTrap::get_max_energy() const { return(_max_energy); }

int			FragTrap::get_level() const { return(_level); }

int			FragTrap::get_melee_attack() const { return(_melee_attack); }

int			FragTrap::get_range_attack() const { return(_range_attack); }

int			FragTrap::get_armor_reduct() const { return(_armor_dam_reduct); }

std::string	FragTrap::get_name() const { return(_name); }

FragTrap &	FragTrap::operator = ( FragTrap const & value){
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

void		FragTrap::rangedAttack( std::string const & target ){
	std::cout<<"FR4G-TP ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at range, causing ";
	std::cout<<RED<<_range_attack<<RESET<<" points of damage"<<std::endl;
}

void		FragTrap::meleeAttack( std::string const & target ){
	std::cout<<"FR4G-TP ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<RESET<<" at melee, causing ";
	std::cout<<RED<<_melee_attack<<RESET<<" points of damage"<<std::endl;
}

void		FragTrap::beRepaired( unsigned int amount ){
	if (_hp + amount > _max_hp)
		amount = _max_hp - _hp;
	std::cout<<"FR4G-TP ("<<GREEN<<_name<<RESET<<") repaired for ";
	std::cout<<GREEN<<amount<<RESET<<" hit points (";
	_hp += amount;
	std::cout<<*this<<")"<<std::endl;
}

void		FragTrap::takeDamage( unsigned int amount ){
	int		damage_taken;
	if (_armor_dam_reduct > amount)
		damage_taken = 0;
	else if (_armor_dam_reduct < amount)
		damage_taken = amount - _armor_dam_reduct;
	if (damage_taken > _hp)
		damage_taken = _hp;
	if (damage_taken != _hp){
		std::cout<<"FR4G-TP ("<<GREEN<<_name<<RESET<<") take ";
		std::cout<<RED<<damage_taken<<RESET<<" amount of damage (";
	}
	else
		std::cout<<"FR4G-TP ("<<GREEN<<_name<<BOLDWHITE<<") destroyed ("<<RESET;
	_hp -= damage_taken;
	std::cout<<*this<<")"<<std::endl;
}

void		FragTrap::_funny_attack( int const amount, std::string const text,
			std::string const & target){
	std::cout<<"FR4G-TP ("<<GREEN<<_name<<RESET<<") attacks ";
	std::cout<<MAGENTA<<target<<BLUE<<text;
	std::cout<<RED<<amount<<RESET<<" points of damage (current energy: ";
	if (_energy > 60)
		std::cout<<GREEN;
	else if (_energy > 30)
		std::cout<<YELLOW;
	else
		std::cout<<RED;
	std::cout<<_energy<<")"<<RESET<<std::endl;
}

void		FragTrap::vaulthunter_dot_exe( std::string const & target ){
	_target = target;
	int	i = rand() % 15;
	if (_energy - 25 < 0)
		std::cout<<"Not enough energy. Current energy: "<<_energy<<std::endl;
	else{
		if (i >= 0 && i <= 5)
			_funny_attack(19, " wingardium leviosa ", target);
		if (i > 5 && i <= 9)
			_funny_attack(25, " BONK ", target);
		if (i > 9 && i < 11)
			_funny_attack(31, " fart ", target);
		if (i >= 11 && i < 14)
			_funny_attack(6, " kick ", target);
		if (i >= 14)
			_funny_attack(200, " ХДЫЩЬ! ", target);
		_energy -= 25;
	}
}
