#include "TitleSceme.h"
#include <Entity.h>

void TitleScene::Load()
{
	Entity* e1 = new TestEntity();
	homer::Entity* e2 = new DogEntity();

	homer::Engine::Get().World().Add(e1);
	homer::Engine::Get().World().Add(e2);

}
