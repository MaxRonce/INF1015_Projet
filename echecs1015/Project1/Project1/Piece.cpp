#pragma once
#include "Piece.h"

Piece::Piece(std::string color) {
	color_ = color;
}

std::pair<int, int> Piece::getPosition() const {
	return position_;
}

void Piece::move(char x, int y) {
	previousPosition_ = position_;
	auto coordonnees = map.find(x);
	position_.first = coordonnees->second;
	position_.second = y;
}

std::pair<int, int>Piece::getPreviousPosition() const {
	return previousPosition_;
};

char Piece::getSymbol() const {
	return symbol_;
};
void Piece::setColor(std::string newColor) {
	color_ = newColor;
}

std::string Piece::getColor() const {
	return color_;
}

void Piece::setPreviousPosition() {
	previousPosition_ = getPosition();
}