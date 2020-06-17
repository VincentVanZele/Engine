#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include <SDL.h>

#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "TestScene.h"

#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"

#include "GameTime.h"
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "Animation.h"

void proxy::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(window);

	ResourceManager::GetInstance().Init("../Data/");
}

void proxy::Minigin::LoadGame() const
{
	
}

void proxy::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}

void proxy::Minigin::Run()
{
	LoadGame();				

	{
		//modification added according to powerpoint slides 
		auto t = std::chrono::high_resolution_clock::now();

		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		auto& gameTime = GameTime::GetInstance();

		bool doContinue = true;

		while (doContinue)
		{
			auto currentTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(currentTime - t).count();
			if (deltaTime > 0.06f)
				deltaTime = 0.06f;
			t = currentTime;

			doContinue = input.ProcessInput();

			sceneManager.Update();
			renderer.Render();
			gameTime.Update(deltaTime);
		}
	}

	Cleanup();
}
