#pragma once
#include <string>
#include <array>

const std::string nomsDirections[4] = { "au nord","au sud","à l'est","à l'ouest" };
const char symbolesDirections[4] = { 'N','S','E','O'};

const enum class Direction {nord,sud,est,ouest};
const std::array<Direction,4> directionsInverses = { Direction::sud,Direction::nord,Direction::ouest,Direction::est };

