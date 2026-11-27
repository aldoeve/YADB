/**
 * This file contains all declarations and constants needed for the bishop
 * algorithm.
 */

#pragma once

#include <array>
#include <string>

#include "types/types.hpp"

namespace bishop::board {

inline constexpr app::types::u32 StdWidth = 17;
inline constexpr app::types::u32 StdHeight = 9;

inline constexpr std::array<char, 15> symbols = {
    ' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};

enum class Moves { UpLeft, UpRight, DownLeft, DownRight };
} // namespace bishop::board

namespace bishop {
std::string generateAscii(const std::string&,
                          const app::types::u32 = bishop::board::StdWidth,
                          const app::types::u32 = bishop::board::StdHeight);
}
