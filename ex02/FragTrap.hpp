/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:03:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/06/08 14:50:43 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	
public:

	FragTrap( std::string name );
	~FragTrap();
	
	int	vaulthunter_dot_exe( std::string const & target );

private:

	int	_funny_attack ( int const amount, std::string const text,
		std::string const & target );

};

std::ostream & operator << (std::ostream & o, FragTrap const & input);

#endif