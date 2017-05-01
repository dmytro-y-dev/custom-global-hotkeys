#pragma once

#include <memory>

namespace CustomGlobalHotkeys {
	namespace Action {
		class ActionInterface
		{
		public:
			virtual ~ActionInterface() {}

			virtual void execute() const = 0;
		};

		typedef std::shared_ptr<ActionInterface> TActionSharedPtr;
	}
}