/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:06:50 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:37:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
# define SCAVTRAP_H_

# include "ClapTrap.hpp"

# include <string>

class ScavTrap : public ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &scavtrap);
  ~ScavTrap(void);
  ScavTrap &operator=(const ScavTrap &scavtrap);

  void attack(const std::string &target);

  void guardGate(void);

private:
  static const std::string kRobotType;
  static const unsigned int kHitPoints = 100;
  static const unsigned int kEnergyPoints = 50;
  static const unsigned int kAttackDamage = 20;

};

#endif
