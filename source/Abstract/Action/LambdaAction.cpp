#include "LambdaAction.h"

using CustomGlobalHotkeys::Action::LambdaAction;

LambdaAction::LambdaAction(TLambdaFunction function):
	m_function(function)
{
}

void LambdaAction::execute() const
{
	m_function();
}
