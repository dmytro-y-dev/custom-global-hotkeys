#pragma once

#include <functional>

#include <Abstract/Action/ActionInterface.h>

namespace CustomGlobalHotkeys {
	namespace Action {
		class LambdaAction : public ActionInterface
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