/*
* TP6 INF1015
* \file   InstancesKingException.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include <stdexcept>


class InstancesKingException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};
