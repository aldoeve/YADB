/**
 * The bishop algorithm that generates the ascii art.
 */

#include <cstddef>
#include <expected>
#include <limits>
#include <memory>
#include <string>
#include <utility>

#include "bishop.hpp"
#include "types/types.hpp"

inline app::types::u32 bishop::detail::twoDimensionsToOneIndex(const std::pair<app::types::u32, app::types::u32> loc, const app::types::u32 width) noexcept {
    return loc.second * width + loc.first;
}

std::string bishop::detail::interpolateSymbols(
    const std::unique_ptr<app::types::u32[]> &board) noexcept {
    return "";
}

std::expected<std::string, bishop::errors::Type>
bishop::generateAscii(const std::size_t &hash, const app::types::u32 width,
                      const app::types::u32 height) noexcept {
  if (width == 0 || height == 0) {
    return std::unexpected(bishop::errors::Type::InvalidDimensions);
  }
  if (width > (std::numeric_limits<app::types::u32>::max() / height)) {
    return std::unexpected(bishop::errors::Type::Overflow);
  }

  const app::types::u32 totalCells{width * height};
  const auto board{std::make_unique<app::types::u32[]>(totalCells)};
  std::pair<app::types::u32, app::types::u32> bishopLoc{width / 2, height / 2};

  constexpr const std::size_t totalBits{
      std::numeric_limits<std::size_t>::digits};

  const auto next = [](std::size_t a) { return a + 1; };
  const std::size_t shiftPair{2};
  const app::types::u32 keep2LeastSigBits{0b11u};

  for (std::size_t i{0}; next(i) <= totalBits; i += shiftPair) {
    const app::types::u32 pair{
        static_cast<app::types::u32>((hash >> i) & keep2LeastSigBits)};
    bishop::detail::moveBishop(pair, board, bishopLoc);
  }

  return bishop::detail::interpolateSymbols(board);
}
