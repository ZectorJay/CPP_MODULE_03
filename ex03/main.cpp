/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 09:22:46 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 16:29:38 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <time.h>
#include <sys/time.h>

int main(){
	struct timeval timer;

	gettimeofday(&timer, NULL);
	ClapTrap cl4p_tp("CL4P-TP");
	ScavTrap sc4v_tp("SC4V-TP");
	FragTrap fr4g_tp("FT4G-TP");
	NinjaTrap ninja("NINJA-TP");

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

	std::cout<<"\n\n\n------------FIGHT HAS ENDED----------------"<<std::endl;
	return (0);
}