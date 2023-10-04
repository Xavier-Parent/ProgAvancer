#include "Color.h"

Color::Color(uchar red, uchar green, uchar blue, uchar alpha)
{
}
	const Color& Color::Red = Color(255, 0, 0, 0);
	const Color& Color::Blue = Color(0, 0, 255, 0);
	const Color& Color::Green = Color(0, 255, 0, 0);
	const Color& Color::Alpha = Color(0, 0, 0, 255);
