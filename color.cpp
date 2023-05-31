#include <iostream>
#include <bitset>

int main()
{   
    // bitmasks to isolate the bits for a specific colour
    constexpr std::uint32_t redBits { 0xFF000000 }; 
    constexpr std::uint32_t greenBits { 0x00FF0000 }; 
    constexpr std::uint32_t blueBits { 0x0000FF00 }; 
    constexpr std::uint32_t alphaBits { 0x000000FF }; 

    // ask user for a color value
    std::cout << "Enter a 32-bit RGBA color value in hexadecimal: ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; 

    // view pixel in binary
    std::cout << static_cast<std::bitset<32>>(pixel) << '\n';

    // isolate the 'colored' bits and right shift them for storage as 8 bits
    std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
    std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
    std::uint8_t alpha{ static_cast<std::uint8_t>((pixel & alphaBits)) };

    // output the color values for RGBA in hexadecimal
    std::cout << "Your color contains: \n";
    std::cout << std::hex;
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    return 0;
}
