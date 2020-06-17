#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Structs.h"
#include <unordered_map>

namespace proxy
{

	class InputManager final : public Singleton<InputManager>
	{
	public:

		bool ProcessInput(); // keyboard + controller input 
		bool ProcessKeyboardInput();
		bool ProcessControllerInput();
		
		void AddInput(const std::string& name, int32_t sdlKey);

		// Mouse
		Float2 GetMousePos();
		void UpdateMousePos();

		// Keyboard
		// neww && because of std::move 
		// https://www.artima.com/cppsource/rvalue.html

		bool IsPressed(std::string&& name);	  // get input by name
		bool IsDown(std::string&& name);
		bool IsUp(std::string&& name);

		
		// Gamepad
		XINPUT_STATE GetControllerInputState();
		bool GetControllerIsValid();

		bool IsButton(int index, ControllerButton cButton);
	
	private:
		// Keyboard
		Float2 m_mousePos;
		std::unordered_map<std::string, SDLCommand> m_KeyCommands;	// access each input easily via name 
		
		// Gamepad
		XINPUT_STATE m_controllerState{};
		bool m_IsControllerValid{ false };
	};
}

