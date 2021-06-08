/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 09:22:46 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 17:55:05 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <time.h>
#include <sys/time.h>

int main(){
	struct timeval timer;

	gettimeofday(&timer, NULL);
	ClapTrap cl4p_tp("CL4P-TP");
	ScavTrap sc4v_tp("SC4V-TP");
	FragTrap fr4g_tp("FT4G-TP");
	NinjaTrap ninja("NINJA-TP");
	SuperTrap super("SUPER_TP");

	srand(timer.tv_usec);
	ninja.ninjaShoebox(cl4p_tp);
	std::cout<<"\n\n\n-------------ROUND 1-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	ninja.ninjaShoebox(sc4v_tp);
	ninja.takeDamage(sc4v_tp.meleeAttack(ninja.get_name()));
	sc4v_tp.takeDamage(ninja.meleeAttack(sc4v_tp.get_name()));

	std::cout<<"\n\n\n-------------ROUND 2-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	ninja.ninjaShoebox(fr4g_tp);
	fr4g_tp.takeDamage(ninja.meleeAttack(fr4g_tp.get_name()));
	ninja.takeDamage(fr4g_tp.vaulthunter_dot_exe(ninja.get_name()));

	std::cout<<"\n\n\n-------------ROUND 3-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	ninja.ninjaShoebox(ninja);
	ninja.takeDamage(ninja.rangedAttack(ninja.get_name()));
	ninja.takeDamage(ninja.meleeAttack(ninja.get_name()));

	std::cout<<"\n\n\n-------------ROUND 4-------------"<<std::endl;
	super.ninjaShoebox(fr4g_tp);
	super.ninjaShoebox(sc4v_tp);
	super.ninjaShoebox(cl4p_tp);
	super.ninjaShoebox(ninja);
	fr4g_tp.takeDamage(super.vaulthunter_dot_exe(fr4g_tp.get_name()));
	super.takeDamage(fr4g_tp.vaulthunter_dot_exe(super.get_name()));
	std::cout<<"\n\n\n------------FIGHT HAS ENDED----------------"<<std::endl;
	return (0);
}