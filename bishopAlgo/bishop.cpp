/**
 * The bishop algorithm that generates the ascii art.
 */

#include <string>
#include <memory>
#include <limits>
#include <functional>

#include "bishop.hpp"
#include "types/types.hpp"

using namespace app::types;

std::string bishop::generateAscii(const std::string& text, const u32 width, const u32 height) {
    std::hash<std::string> hasher;
    std::size_t hash = hasher(text);

    if ( width > ( std::numeric_limits<u32>::max() / height ) ) {
    // call error func
    }
    
    const u32 totalCells = width * height;
    

    // create board with smart pointers of u32 vals

    // call the move() to shift through pairs; ie loop 

    // call boardPrint() it has the work out of what each value means
    
    return "";
}
