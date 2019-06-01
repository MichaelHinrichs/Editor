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

#include <QDir>
#include <QList>
#include <QSettings>
#include <QString>
#include <memory>

#include "common/filefinder.h"
#include "rpg_database.h"
#include "rpg_map.h"
#include "rpg_treemap.h"

class Project {
public:
	using ProjectList = std::vector<std::shared_ptr<Project>>;

	static ProjectList enumerate(const QDir& path);

	static std::shared_ptr<Project> load(const QString& path);

	bool loadDatabaseAndMapTree();
	std::unique_ptr<RPG::Map> loadMap(int index);
	bool saveMap(RPG::Map& map, int index);

	QString findFile(const QString& filename, FileFinder::FileType type = FileFinder::FileType::Default) const;
	QString findFile(const QString& dir, const QString& filename, FileFinder::FileType type = FileFinder::FileType::Default) const;

	QString encoding() const;
	void setEncoding(const QString& encoding);

	QDir projectDir() const;
	void setProjectDir(const QDir& projectDir);

	QString gameTitle() const;
	void setGameTitle(const QString& gameTitle);

	FileFinder::ProjectType projectType() const;
	void setProjectType(FileFinder::ProjectType projectType);

	RPG::Database& database() const;
	RPG::TreeMap& treeMap() const;

	bool saveDatabase();
	bool saveTreeMap();

private:
	FileFinder::ProjectType m_projectType;
	QString m_encoding;
	QDir m_projectDir;
	std::shared_ptr<QSettings> m_projectSettings;
	QString m_gameTitle;

	RPG::Database* m_db = nullptr;
	RPG::TreeMap* m_treeMap = nullptr;
};
