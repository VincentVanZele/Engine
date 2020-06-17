#pragma once
#include <cmath>
#include <Xinput.h>
#pragma comment(lib,"Xinput.lib")


namespace proxy
{
	struct SDLWindowInfo
	{
		float _x{ 0.f }, _y{ 0.f };
	};

	struct SDLCommand
	{ 
		SDLCommand()
			:_sdlKey{ '\0' } //https://wiki.libsdl.org/SDLKeycodeLookup SDL_UNKNOWN
		{}
		// int32_t correspond to a certain key code by SDL
		SDLCommand(int32_t key) 
			:_sdlKey{ key }
		{}

		int32_t _sdlKey;

		bool _keyPressed{ false };
		bool _keyUp{ false };
		bool _keyDown{ false };
	};

	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY,
		DPLeft,
		DPRight,
		DPUp,
		DPDown
	};

	struct Float2
	{
		// Variables
		float _x{}, _y{};

		// Constructors
		Float2()
			: _x(0), _y(0)
		{
		}

		Float2(float x, float y)
			:_x(x), _y(y)
		{
		}

		// Functions 
		float Length()
		{
			return (sqrt(_x * _x + _y * _y));
		}

		void Normalize()
		{
			_x /= Length();
			_y /= Length();
		}
	};

	struct Float3
	{
		float _x{}, _y{}, _z{};

		Float3(float x, float y, float z)
			:_x(x), _y(y), _z(z)
		{
		}

		Float3()
			:_x(0), _y(0), _z(0)
		{
		}
	};

	struct Float4
	{
		float _x{}, _y{}, _z{}, _w{};

		Float4(float x, float y, float z, float w)
			: _x(x), _y(y), _z(z), _w(w)
		{
		}
		Float4()
			:_x(0), _y(0), _z(0), _w(0)
		{
		}
	};

}