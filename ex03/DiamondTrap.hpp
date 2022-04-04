/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:06:50 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:24:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_H_
# define DIAMONTRAP_H_

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(void);
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &diamondtrap);
  ~DiamondTrap(void);
  DiamondTrap &operator=(const DiamondTrap &diamondtrap);

  void attack(const std::string &target);

  void whoAmI(void);

private:
  std::string name_;
  static const std::string kRobotType;
};

#endif
