#pragma once

#include <functional>

#include "Action.h"

class LambdaAction : public Action
{
public:
	typedef std::function<void()> TLambdaFunction;

public:
	LambdaAction(TLambdaFunction function);

	virtual void execute() const;

private:
	TLambdaFunction m_function;
};