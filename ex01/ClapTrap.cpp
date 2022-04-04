/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:19:56 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:02:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

const std::string ClapTrap::kRobotType = "ClapTrap"; 

ClapTrap::ClapTrap(void)
  : name_(""), hit_points_(kHitPoints), 
  energy_points_(kEnergyPoints), attack_damage_(kAttackDamage),
  max_hit_points_(kHitPoints)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Default constructor is called." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
  : name_(name), hit_points_(kHitPoints), 
  energy_points_(kEnergyPoints), attack_damage_(kAttackDamage),
  max_hit_points_(kHitPoints)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Constructor with name is called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Copy constructor is called." << std::endl;
  *this = claptrap;
}

ClapTrap::~ClapTrap(void)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Destructor of " << name_ << "'s is called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Copy assignment operator is called." << std::endl;
  name_ = claptrap.get_name();
  hit_points_ = claptrap.get_hit_points();
  energy_points_ = claptrap.get_energy_points();
  attack_damage_ = claptrap.get_attack_damage();
  return *this;
}

void ClapTrap::attack(const std::string &target)
{
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "ClapTrap " << name_ << " attacks " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
    energy_points_--;
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (hit_points_ <= amount || hit_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "'s hit point is 0." << std::endl;
    hit_points_ = 0;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " take damage " << amount << std::endl;
    hit_points_ -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
    return;
  }
  else if (hit_points_ == max_hit_points_) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "'s hit point is full." << std::endl;
    return;
  }
  else if (hit_points_ + amount > max_hit_points_) {
    hit_points_ = max_hit_points_;
    std::cout << "[ " << kRobotType << " ] "
              << "Max hit points is " << max_hit_points_
              << ". You are already full." << std::endl;
  }
  else {
    hit_points_ += amount;
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " gets " << amount
              << " hit points back. Total : " << hit_points_ << std::endl;
  }
  energy_points_--;
}

const std::string &ClapTrap::get_name(void) const { return name_; }

unsigned int ClapTrap::get_hit_points(void) const { return hit_points_; }

unsigned int ClapTrap::get_energy_points(void) const { return energy_points_; }

unsigned int ClapTrap::get_attack_damage(void) const { return attack_damage_; }

void ClapTrap::set_name(std::string &name) { name_ = name; }

void ClapTrap::set_hit_points(const unsigned int hit_point)
{
  hit_points_ = hit_point;
}

void ClapTrap::set_energy_points(const unsigned int energy_point)
{
  energy_points_ = energy_point;
}

void ClapTrap::set_attack_damage(const unsigned int attack_damage)
{
  attack_damage_ = attack_damage;
}
