#include "Component.h"
#include "engin.h"

class TextRenderer : public Component, public IDrawable
{
public:
	/// <summary>
	/// Constructor by default
	/// </summary>
	TextRenderer() = default;
	/// <summary>
	/// Constructor with Entity
	/// </summary>
	/// <param name="entity"></param>
	TextRenderer(Entity* entity);
	/// <summary>
	/// Destructor
	/// </summary>
	~TextRenderer();
	/// <summary>
	/// Function draw
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// Function Start
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// Function Destroy
	/// </summary>
	virtual void Destroy() override;
	/// <summary>
	/// Initialisation of the Sprite
	/// </summary>
	/// <param name="filename">The file string where the sprite is</param>
	/// <param name="w">The width of the sprite</param>
	/// <param name="h">Height of the sprite</param>

	void InitText(const std::string& fontfilename, float fontSize);
private:
	std::string file;
	size_t id;
	RectF square;
	float h;
	float w;
	float X;
	float Y;
	Color* color;
};