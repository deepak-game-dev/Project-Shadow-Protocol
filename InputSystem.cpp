#include "InputSystem.h"
#include <Windows.h>

int GetWindowsKey(Key key)
{
	switch (key)
	{
	case Key::W:
		return 'W';

	case Key::A:
		return 'A';

	case Key::S:
		return 'S';

	case Key::D:
		return 'D';

	case Key::Space:
		return VK_SPACE;

	case Key::E:
		return 'E';

	case Key::F:
		return 'F';
	}
	return 0;
}

Key InputSystem::GetKeyForAction(Action action)
{
	switch (action)
	{
	case Action::MoveForward:
		return Key::W;

	case Action::MoveBackward:
		return Key::S;

	case Action::MoveLeft:
		return Key::A;

	case Action::MoveRight:
		return Key::D;

	case Action::Jump:
		return Key::Space;

	case Action::Attack:
		return Key::F;

	case Action::Interact:
		return Key::E;

	return Key::W;
	}
}

bool InputSystem::IsPressed(Action action)
{
	return IsPressed(GetKeyForAction(action));
}

bool InputSystem::IsHeld(Action action)
{
	return IsHeld(GetKeyForAction(action));
}

bool InputSystem::IsReleased(Action action)
{
	return IsReleased(GetKeyForAction(action));
}

void InputSystem::Update()
{
	previousKeys = currentKeys;

	currentKeys[Key::W] = (GetAsyncKeyState(GetWindowsKey(Key::W)) & 0x8000) != 0;
	currentKeys[Key::A] = (GetAsyncKeyState(GetWindowsKey(Key::A)) & 0x8000) != 0;
	currentKeys[Key::S] = (GetAsyncKeyState(GetWindowsKey(Key::S)) & 0x8000) != 0;
	currentKeys[Key::D] = (GetAsyncKeyState(GetWindowsKey(Key::D)) & 0x8000) != 0;
	currentKeys[Key::Space] = (GetAsyncKeyState(GetWindowsKey(Key::Space)) & 0x8000) != 0;
	currentKeys[Key::F] = (GetAsyncKeyState(GetWindowsKey(Key::F)) & 0x8000) != 0;
}

bool InputSystem::IsPressed(Key key)
{
	return currentKeys[key] && !previousKeys[key];
}

bool InputSystem::IsHeld(Key key)
{
	return currentKeys[key];
}

bool InputSystem::IsReleased(Key key)
{
	return !currentKeys[key] && previousKeys[key];
}