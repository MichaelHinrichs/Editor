/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "project.h"
#include "rpg_actor.h"

class QSortFilterProxyModel;

/**
 * A thin wrapper around RPG::Actor
 */
class Actor
{
public:
	Actor(RPG::Actor& actor, Project& project);

	bool IsItemUsable(const RPG::Item& item) const;

	/**
	 * Create a SortFilterProxy which only contains items of a specific type
	 * and who the actor can equip.
	 * @param type Equipment type
	 * @return QSortFilterProxyModel
	 */
	QSortFilterProxyModel* CreateEquipmentFilter(RPG::Item::Type type);

	RPG::Actor& data();

private:
	RPG::Actor& actor;
	Project& project;
};

