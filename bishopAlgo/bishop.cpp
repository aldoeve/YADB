/**
 * The bishop algorithm that generates the ascii art.
 */

#include <string>
#include <functional>

#include "bishop.hpp"
#include "types/types.hpp"

using namespace app::types;

std::string bishop::generateAscii(const std::string& text, const u32 width, const u32 height) {
    std::hash<std::string> hasher;
    std::size_t hash = hasher(text);
    
    return "";
}
