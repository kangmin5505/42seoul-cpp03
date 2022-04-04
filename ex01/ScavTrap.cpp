/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:21:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/02 23: by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

const std::string ScavTrap::kRobotType = "ScavTrap";

ScavTrap::ScavTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
          << "Default constructor is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
  max_hit_points_ = kHitPoints;
}

ScavTrap::ScavTrap(const std::string &name)
  : ClapTrap(name)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Constructor with name is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
  max_hit_points_ = kHitPoints;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy constructor is called." << std::endl;
  *this = scavtrap;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
            << "Destructor of " << name_ << "'s is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy assignment operator is called." << std::endl;
  ClapTrap::operator=(scavtrap);
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "ScavTrap " << name_ << " attacks " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
    energy_points_--;
  }
}

void ScavTrap::guardGate(void) {
  if (hit_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "isn't gatekeeper mode."
              << "Because he is dead." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " is gatekeeper mode." << std::endl;
  }
}
