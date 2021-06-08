/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 09:22:46 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 15:01:26 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <time.h>
#include <sys/time.h>

int main(){
	struct timeval timer;

	gettimeofday(&timer, NULL);
	ScavTrap sc4v_tp("SC4V-TP");
	FragTrap fr4g_tp("FT4G-TP");

	srand(timer.tv_usec);
	std::cout<<"-------------ROUND 1-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	fr4g_tp.takeDamage(sc4v_tp.meleeAttack("FR4G-TP"));
	std::cout<<std::endl;
	sc4v_tp.takeDamage(fr4g_tp.meleeAttack("SC4V-TP"));
	std::cout<<"\n-------------ROUND 2-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	fr4g_tp.takeDamage(sc4v_tp.rangedAttack("FR4G-TP"));
	std::cout<<std::endl;
	sc4v_tp.takeDamage(fr4g_tp.vaulthunter_dot_exe("SC4V-TP"));
	sc4v_tp.beRepaired(120);
	std::cout<<"\n-------------ROUND 3-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	fr4g_tp.takeDamage(sc4v_tp.rangedAttack("FR4G-TP"));
	std::cout<<std::endl;
	sc4v_tp.takeDamage(fr4g_tp.vaulthunter_dot_exe("SC4V-TP"));
	std::cout<<"\n-------------ROUND 4-------------"<<std::endl;
	sc4v_tp.challengeNewcomer();
	fr4g_tp.takeDamage(sc4v_tp.rangedAttack("FR4G-TP"));
	std::cout<<std::endl;
	sc4v_tp.takeDamage(fr4g_tp.vaulthunter_dot_exe("SC4V-TP"));
	return (0);
}