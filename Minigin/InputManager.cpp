#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>

bool proxy::InputManager::ProcessInput()
{
	if (!ProcessControllerInput())
	{
		return false;
	}
	if (!ProcessKeyboardInput())
	{
		return false;
	}

	return true;
}

void proxy::InputManager::AddInput(const std::string& name, int32_t sdlKey)
{
	m_KeyCommands[name] = SDLCommand(sdlKey);
}

bool proxy::InputManager::IsPressed(std::string&& name)
{
	return m_KeyCommands[std::move(name)]._keyPressed;
}

bool proxy::InputManager::IsDown(std::string&& name)
{
	return m_KeyCommands[std::move(name)]._keyDown;
}

bool proxy::InputManager::IsUp(std::string&& name)
{
	return m_KeyCommands[std::move(name)]._keyUp;
}

bool proxy::InputManager::ProcessKeyboardInput()
{
	for (auto& cmd : m_KeyCommands)
	{
		cmd.second._keyDown = false;
		cmd.second._keyUp = false;
	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		auto key = event.key.keysym.sym;

		switch (event.type)
		{
		case SDL_QUIT:
			return false;
		case SDL_KEYDOWN:
			// command buttons
			for (std::pair<const std::string, SDLCommand>& cmd : m_KeyCommands)
			{
				if (cmd.second._sdlKey == key)
				{
					if (cmd.second._keyPressed)
						break;

					cmd.second._keyPressed = true;
					cmd.second._keyDown = true;
					break;
				}
			}
			break;
		case SDL_KEYUP:
			if (key == SDLK_ESCAPE)
				return false;

			for (std::pair<const std::string, SDLCommand>& cmd : m_KeyCommands)
			{
				if (cmd.second._sdlKey == key)
				{
					cmd.second._keyPressed = false;
					cmd.second._keyUp = true;
					break;
				}
			}
			break;
		}
	}
	return true;
}

proxy::Float2 proxy::InputManager::GetMousePos()
{
	return m_mousePos;
}

void proxy::InputManager::UpdateMousePos()
{
	int x{}, y{};
	SDL_GetMouseState(&x, &y);

	m_mousePos._x = (float)x;
	m_mousePos._y = (float)y;
}

XINPUT_STATE proxy::InputManager::GetControllerInputState()
{
	return m_controllerState;
}

bool proxy::InputManager::IsButton(int index, ControllerButton cButton)
{
	if (!m_IsControllerValid)
	{
		return false;
	}

	switch (cButton)
	{
	case ControllerButton::ButtonA:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
		break;

	case ControllerButton::ButtonB:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
		break;

	case ControllerButton::ButtonX:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
		break;

	case ControllerButton::ButtonY:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
		break;

	case ControllerButton::DPDown:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
		break;

	case ControllerButton::DPUp:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
		break;

	case ControllerButton::DPLeft:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
		break;

	case ControllerButton::DPRight:
		return m_controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
		break;

	}

	return false;
}

bool proxy::InputManager::GetControllerIsValid()
{
	return m_IsControllerValid;
}

bool proxy::InputManager::ProcessControllerInput()
{
	m_IsControllerValid = XInputGetState(0, &m_controllerState) == ERROR_SUCCESS;
	return true;
}


