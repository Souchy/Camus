
#include "../../models/Tower.h"

class BasicTower : public Tower {

	BasicTower() {
		Ref<EntityData> data;
		this->setData(data);
	}

};