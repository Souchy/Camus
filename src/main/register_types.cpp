/*************************************************************************/
/*  register_types.cpp                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
using namespace godot;


#include "Game.h"
#include "../models/example.h"
#include "../models/Wompa.h"
#include "../models/EntityData.h"
#include "../models/Tower.h"
#include "../models/Unit.h"
#include "../models/Projectile.h"
#include "../ux/HealthBar.h"

#include "../new/api/AI.hpp"
#include "../new/api/BattleNode.hpp"
#include "../new/api/Entity.h"
#include "../new/api/Target.h"
#include "../new/api/TerrainEntity.h"
#include "../new/api/Weapon.h"
#include "../new/data/Base.hpp"
#include "../new/data/towers/BasicTower.hpp"
#include "../new/data/towers/CircleTower.hpp"

/// <summary>
/// Register my library's types
/// </summary>
void register_types() {
	ClassDB::register_class<Example>();
	ClassDB::register_class<Game>();
	ClassDB::register_class<EntityData>();
	ClassDB::register_class<Tower>();
	ClassDB::register_class<Projectile>();
	ClassDB::register_class<Unit>();
	ClassDB::register_class<Wompa>();
	//ClassDB::register_class<Weapon>();
	ClassDB::register_class<HealthBar>();

	ClassDB::register_class<Entity>();
	ClassDB::register_class<TerrainEntity>();
	ClassDB::register_class<Weapon>();
	ClassDB::register_class<BattleNode>();
	//ClassDB::register_class<Base>();
	ClassDB::register_class<BasicTower>();
	ClassDB::register_class<CircleTower>();
}

/// <summary>
/// Unregister my library's types
/// </summary>
void unregister_types() {

}

extern "C" {
	/// <summary>
	/// Library enter point
	/// </summary>
	/// <param name="p_interface"></param>
	/// <param name="p_library"></param>
	/// <param name="r_initialization"></param>
	/// <returns></returns>
	GDNativeBool GDN_EXPORT library_init(const GDNativeInterface* p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_scene_initializer(register_types);
		init_obj.register_scene_terminator(unregister_types);

		return init_obj.init();
	}
}


/*
void register_example_types() {
	ClassDB::register_class<ExampleRef>();
	ClassDB::register_class<Example>();
}


extern "C" {

	// Initialization.

	GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface* p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_scene_initializer(register_example_types);
		init_obj.register_scene_terminator(unregister_example_types);

		return init_obj.init();
	}
}
*/
