#include "LambdaAction.h"

LambdaAction::LambdaAction(TLambdaFunction function):
	m_function(function)
{
}

void LambdaAction::execute() const
{
	m_function();
}
