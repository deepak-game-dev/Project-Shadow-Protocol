#pragma once
#include <unordered_map>

enum class Key
{
	W,
	A,
	S,
	D,
	F,
	E,
	Space
};

enum class Action
{
	MoveForward,
	MoveBackward,
	MoveLeft,
	MoveRight,
	Jump,
	Attack,
	Interact,
};

class InputSystem
{
private:
	std::unordered_map<Key, bool> currentKeys;
	std::unordered_map<Key, bool> previousKeys;

public:
	void Update();
	bool IsPressed(Key key);
	bool IsHeld(Key key);
	bool IsReleased(Key key);
	Key GetKeyForAction(Action action);
	bool IsPressed(Action action);
	bool IsHeld(Action action);
	bool IsReleased(Action action);
};