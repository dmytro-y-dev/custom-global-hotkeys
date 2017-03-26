#pragma once

class Action
{
public:
	virtual ~Action();

	virtual void execute() const = 0;
};