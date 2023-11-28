#pragma once
#include <iostream>
#include "Color.h"
/// <summary>
/// Struct to make a Rectangle with value of integer
/// </summary>
struct RectI
{
	int x;
	int y;
	int w;
	int h;
};
/// <summary>
/// Struct to make a rectangle with value of decimal number
/// </summary>
struct RectF
{
	float x;
	float y;
	float w;
	float h;
};
/// <summary>
/// Function to flip an image
/// </summary>
struct Flip
{
	bool h;
	bool v;
};
class IGraphics
{
public:
	virtual ~IGraphics() = default;
	/// <summary>
	/// Function to Draw a line
	/// </summary>
	/// <param name="x0">Position to start the line in the horizontal position</param>
	/// <param name="y0">Position to start the line in the vertical position</param>
	/// <param name="x1">Position to end the line in the horizontal position</param>
	/// <param name="y1">Position to end the line in the vertical position</param>
	virtual void DrawLine(int x0, int y0,int x1,int y1) = 0;
	/// <summary>
	/// Function to initialise a graphic
	/// </summary>
	/// <param name="title">Name of the sprite</param>
	/// <param name="w">Width of the sprite</param>
	/// <param name="h">Heigh of the sprite</param>
	/// <returns></returns>
	virtual bool Initialize(const std::string& title, int w, int h) = 0;
	/// <summary>
	/// Shutdown the graphics
	/// </summary>
	virtual void Shutdown() = 0;
	/// <summary>
	/// Function to set the color of the graphics
	/// </summary>
	/// <param name="color">Choose the color</param>
	virtual void SetColor(const Color& color) = 0;
	/// <summary>
	/// Clear the sprite 
	/// </summary>
	virtual void Clear() = 0;
	/// <summary>
	/// ??
	/// </summary>
	virtual void Present() = 0;
	/// <summary>
	/// Function to draw a empty Rectangle with only the side will appears
	/// </summary>
	/// <param name="x">Horizontal position of the rect</param>
	/// <param name="y">Vertical position of the rect</param>
	/// <param name="w">Width of the rect</param>
	/// <param name="h">Height of the rect</param>
	/// <param name="color">color of the new rect</param>
	virtual void DrawRect(int x, int y, int w, int h, const Color& color) = 0;
	/// <summary>
	/// Other variable to draw an empty rect Rect
	/// </summary>
	/// <param name="rect">A prefab of a rect</param>
	/// <param name="color">the color</param>
	virtual void DrawRect(const RectF& rect, const Color& color) = 0;
	/// <summary>
	/// A full Rectangle with color in the inside
	/// </summary>
	/// <param name="x">Horizontal position of the rect</param>
	/// <param name="y">Vertical position of the rect</param>
	/// <param name="w">Width of the rect</param>
	/// <param name="h">Height of the rect</param>
	/// <param name="color">color of the draw</param>
	virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
	/// <summary>
	/// Function to draw a full rect with a prefab of a rect
	/// </summary>
	/// <param name="rect">the prefabs</param>
	/// <param name="color">color of the rect</param>
	virtual void FillRect(const RectF& rect, const Color& color) = 0;
	/// <summary>
	/// Draw a line from a point to another with a color
	/// </summary>
	/// <param name="x1">horizontal position of the start of the line</param>
	/// <param name="y1">Vertical position of the start of the line</param>
	/// <param name="x2">Horizontal position of the end of the line</param>
	/// <param name="y2">vertical position of the end of the line</param>
	/// <param name="color">Color of this magnificient line</param>
	virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
	/// <summary>
	/// Function to load a texture using the path for the image
	/// </summary>
	/// <param name="filename">the path for the file</param>
	/// <returns></returns>
	virtual size_t LoadTexture(const std::string& filename) = 0;
	/// <summary>
	/// Function to draw a texture Using the ID 2 rect, an angle the flip and a color
	/// </summary>
	/// <param name="id">The ID of the texture that is gonna be load</param>
	/// <param name="src">the source of the rect</param>
	/// <param name="dst">the destination of that rect</param>
	/// <param name="angle">the angle of the texture</param>
	/// <param name="flip">the side of the texture if it is flip or not</param>
	/// <param name="color">the color of the texture</param>
	virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
	/// <summary>
	/// function to draw a texture using a prefab of a rect an Id and a color
	/// </summary>
	/// <param name="id">The ID of the new texture</param>
	/// <param name="dst">The destination of the Rect</param>
	/// <param name="color">The color of the rect</param>
	virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
	/// <summary>
	/// Function to draw of Texture using ID and a color
	/// </summary>
	/// <param name="id">The Id of the new texture</param>
	/// <param name="color">the color of the texture</param>
	virtual void DrawTexture(size_t id, const Color& color) = 0;
	/// <summary>
	/// Get the texture size 
	/// </summary>
	/// <param name="id">The ID< of the texture/param>
	/// <param name="w">Return the Width of the Image</param>
	/// <param name="h">Return the Height of the Image</param>
	virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
	/// <summary>
	/// Function to load a Font for the text in your game
	/// </summary>
	/// <param name="filename">The path to find the correct Font</param>
	/// <param name="fontSize">The size of the font</param>
	/// <returns></returns>
	virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
	/// <summary>
	/// Function to draw text in the game
	/// </summary>
	/// <param name="text">The text o nthe screen</param>
	/// <param name="fontId">The correct font ID</param>
	/// <param name="x">The horizontal position of the text</param>
	/// <param name="y">the vertical position of the text</param>
	/// <param name="color">color of the text</param>
	virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;
	/// <summary>
	/// The text size
	/// </summary>
	/// <param name="text">The name of the text</param>
	/// <param name="fontId">The ID of the font</param>
	/// <param name="w">The Width of the text</param>
	/// <param name="h">The height of the text</param>
	virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;

private:

};

