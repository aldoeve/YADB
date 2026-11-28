/**
 * This file contains all declarations and constants needed for the bishop
 * algorithm.
 */

#pragma once

#include <array>
#include <expected>
#include <memory>
#include <string>
#include <utility>

#include "types/types.hpp"

namespace bishop::board {

inline constexpr app::types::u32 StdWidth = 17;
inline constexpr app::types::u32 StdHeight = 9;

inline constexpr std::array<char, 15> symbols{
    ' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};

enum class Moves { UpLeft, UpRight, DownLeft, DownRight };
} // namespace bishop::board

namespace bishop::errors {
enum class Type { Overflow, InvalidDimensions };
} // namespace bishop::errors

namespace bishop::detail {
inline app::types::u32
twoDimensionsToOneIndex(const std::pair<app::types::u32, app::types::u32>,
                        const app::types::u32) noexcept;
void moveBishop(
    const app::types::u32 move, const std::unique_ptr<app::types::u32[]> &board,
    std::pair<app::types::u32, app::types::u32> &bishopLoc) noexcept;
std::string
interpolateSymbols(const std::unique_ptr<app::types::u32[]> &board) noexcept;
} // namespace bishop::detail

namespace bishop {
std::expected<std::string, bishop::errors::Type>
generateAscii(const std::size_t &,
              const app::types::u32 = bishop::board::StdWidth,
              const app::types::u32 = bishop::board::StdHeight) noexcept;
} // namespace bishop
