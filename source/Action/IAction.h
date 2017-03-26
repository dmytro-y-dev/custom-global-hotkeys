#pragma once

#include <memory>

namespace CustomGlobalHotkeys {
	namespace Action {
		class IAction
		{
		public:
			virtual ~IAction();

			virtual void execute() const = 0;
		};

		typedef std::shared_ptr<IAction> TActionSharedPtr;
	}
}