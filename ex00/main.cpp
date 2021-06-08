/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 09:22:46 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/05 09:14:57 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <time.h>
#include <sys/time.h>

int main(){
	FragTrap trap("OBIWAN");
	struct timeval timer;
	gettimeofday(&timer, NULL);
	srand(timer.tv_usec);

	std::cout<<trap<<std::endl;
	trap.meleeAttack("ENEMY");
	trap.rangedAttack("ENEMY");
	trap.takeDamage(30);
	trap.takeDamage(19);
	trap.takeDamage(22);
	trap.takeDamage(33);
	trap.takeDamage(16);
	trap.takeDamage(10);
	trap.beRepaired(25);
	trap.beRepaired(25);
	trap.beRepaired(25);
	trap.beRepaired(25);
	trap.beRepaired(25);
	trap.vaulthunter_dot_exe("EMINEM");
	trap.vaulthunter_dot_exe("EMINEM");
	trap.vaulthunter_dot_exe("EMINEM");
	trap.vaulthunter_dot_exe("EMINEM");
	trap.vaulthunter_dot_exe("EMINEM");
	trap.vaulthunter_dot_exe("EMINEM");
	return (0);
}