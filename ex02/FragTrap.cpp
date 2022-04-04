/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:21:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:11:51 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

const std::string FragTrap::kRobotType = "FragTrap";

FragTrap::FragTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
          << "Default constructor is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
  max_hit_points_ = kHitPoints;
}

FragTrap::FragTrap(const std::string &name)
  : ClapTrap(name)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Constructor with name is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
  max_hit_points_ = kHitPoints;
}

FragTrap::FragTrap(const FragTrap &fragtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy constructor is called." << std::endl;
  *this = fragtrap;
}

FragTrap::~FragTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
            << "Destructor of " << name_ << "'s is called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy assignment operator is called." << std::endl;
  ClapTrap::operator=(fragtrap);
  return *this;
}

void FragTrap::attack(const std::string &target) {
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "FragTrap " << name_ << " attacks " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
    energy_points_--;
  }
}

void FragTrap::highFivesGuys(void) {
  if (hit_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "dosn't do the high five."
              << "Because he is dead." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "I'm " << name_ << ". Let's high five!" << std::endl;
  }
}
