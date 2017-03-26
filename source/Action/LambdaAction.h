#pragma once

#include <functional>

#include <Action/IAction.h>

namespace CustomGlobalHotkeys {
	namespace Action {
		class LambdaAction : public IAction
		{
		public:
			typedef std::function<void()> TLambdaFunction;

		public:
			LambdaAction(TLambdaFunction function);

			virtual void execute() const;

		private:
			TLambdaFunction m_function;
		};
	}
}