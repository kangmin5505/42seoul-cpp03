/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:21:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:20:19 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

const std::string DiamondTrap::kRobotType = "DiamondTrap";

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), name_("") {
  std::cout << "[ " << kRobotType << " ] "
          << "Default constructor is called." << std::endl;
  hit_points_ = FragTrap::kHitPoints;
  energy_points_ = ScavTrap::kEnergyPoints;
  attack_damage_ = FragTrap::kAttackDamage;
  max_hit_points_ = FragTrap::kHitPoints;
}

DiamondTrap::DiamondTrap(const std::string &name)
  : ClapTrap(name + "_clap_name"), name_(name)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Constructor with name is called." << std::endl;
  hit_points_ = FragTrap::kHitPoints;
  energy_points_ = ScavTrap::kEnergyPoints;
  attack_damage_ = FragTrap::kAttackDamage;
  max_hit_points_ = FragTrap::kHitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy constructor is called." << std::endl;
  *this = diamondtrap;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
            << "Destructor of " << name_ << "'s is called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy assignment operator is called." << std::endl;
  ClapTrap::operator=(diamondtrap);
  name_ = diamondtrap.name_;
  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "[ " << kRobotType << " ] "
            << "DiamondTrap name : " << name_ << ", "
            << "ClapTrap name : " << ClapTrap::name_ << std::endl;
}
