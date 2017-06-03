/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2016 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "cellapp.h"
#include "space.h"	
#include "navigation/navigation.hpp"




namespace KBEngine{	

//-------------------------------------------------------------------------------------
Space::Space(SPACE_ID spaceID):
id_(spaceID),
hasGeometry_(false),
pCell_(NULL),
pNavHandle_(),
state_(STATE_NORMAL),
destroyTime_(0)
{
}

//-------------------------------------------------------------------------------------
Space::~Space()
{
	pNavHandle_.clear();

	SAFE_RELEASE(pCell_);	
}

//-------------------------------------------------------------------------------------
void Space::_clearGhosts()
{
	// ��Ϊspace��destroyʱ����һ�������������������ʣ�µ���ghostsʵ��
	/*if(entities_.size() == 0)
		return;
	
	std::vector<ENTITY_ID> entitieslog;
	
	SPACE_ENTITIES::const_iterator log_iter = this->entities().begin();
	for(; log_iter != this->entities().end(); ++log_iter)
		entitieslog.push_back((*log_iter).get()->id());

	std::vector<ENTITY_ID>::iterator iter = entitieslog.begin();
	for(; iter != entitieslog.end(); ++iter)
	{
		Entity* entity = Cellapp::getSingleton().findEntity((*iter));
		if(entity != NULL && !entity->isDestroyed() && entity->spaceID() == this->id())
		{
			entity->destroyEntity();
		}
		else
		{
			entity = findEntity((*iter));
			if(entity != NULL && !entity->isDestroyed() && entity->spaceID() == this->id())
			{
				removeEntity(entity);
			}
		}
	}
	
	entities_.clear();	*/
}


//-------------------------------------------------------------------------------------
bool Space::addSpaceGeometryMapping(std::string respath, bool shouldLoadOnServer, const std::map< int, std::string >& params)
{
	INFO_MSG(fmt::format("KBEngine::addSpaceGeometryMapping: spaceID={}, respath={}, shouldLoadOnServer={}!\n",
		id(), respath, shouldLoadOnServer));

	hasGeometry_ = true;
	if(getGeometryPath() == respath)
	{
		WARNING_MSG(fmt::format("KBEngine::addSpaceGeometryMapping: spaceID={}, respath={} exist!\n",
			id(), respath));

		return true;
	}

	setGeometryPath(respath);

	if(shouldLoadOnServer)
		loadSpaceGeometry(params);

	return true;
}

//-------------------------------------------------------------------------------------
void Space::loadSpaceGeometry(const std::map< int, std::string >& params)
{
	KBE_ASSERT(pNavHandle_ == NULL);
	//Cellapp::getSingleton().threadPool().addTask(new LoadNavmeshTask(getGeometryPath(), this->id(), params));
}

//-------------------------------------------------------------------------------------
void Space::unLoadSpaceGeometry()
{
}

//-------------------------------------------------------------------------------------
void Space::onLoadedSpaceGeometryMapping(NavigationHandlePtr pNavHandle)
{
	pNavHandle_ = pNavHandle;
	INFO_MSG(fmt::format("KBEngine::onLoadedSpaceGeometryMapping: spaceID={}, respath={}!\n",
			id(), getGeometryPath()));

	
	onAllSpaceGeometryLoaded();
}

//-------------------------------------------------------------------------------------
void Space::onAllSpaceGeometryLoaded()
{
	//SCOPED_PROFILE(SCRIPTCALL_PROFILE);

	
}

//-------------------------------------------------------------------------------------
bool Space::update()
{
	/*if(destroyTime_ > 0 && timestamp() - destroyTime_ >= uint64( 5.f * stampsPerSecond() ))
		return false;

		if(destroyTime_ > 0 && timestamp() - destroyTime_ >= uint64( 4.f * stampsPerSecond() ))
		_clearGhosts();*/
		
	return true;
}

////-------------------------------------------------------------------------------------
//void Space::addEntityAndEnterWorld(Entity* pEntity, bool isRestore)
//{
//	addEntity(pEntity);
//	addEntityToNode(pEntity);
//	onEnterWorld(pEntity);
//}
//
////-------------------------------------------------------------------------------------
//void Space::addEntity(Entity* pEntity)
//{
//	//pEntity->spaceID(this->id_);
//	//pEntity->spaceEntityIdx(entities_.size());
//	//entities_.push_back(pEntity);
//	//pEntity->onEnterSpace(this);
//}
//
////-------------------------------------------------------------------------------------
//void Space::addEntityToNode(Entity* pEntity)
//{
//	//pEntity->installCoordinateNodes(&coordinateSystem_);
//}
//
////-------------------------------------------------------------------------------------
//void Space::removeEntity(Entity* pEntity)
//{
//	//KBE_ASSERT(pEntity->spaceID() == id());
//
//	//pEntity->spaceID(0);
//	//
//	//// �Ȼ�ȡ������λ��
//	//SPACE_ENTITIES::size_type idx = pEntity->spaceEntityIdx();
//
//	//KBE_ASSERT(idx < entities_.size());
//	//KBE_ASSERT(entities_[ idx ] == pEntity);
//
//	//// �����2�������ϵ�entity�����һ��entity����ɾ�������entity����λ��
//	//Entity* pBack = entities_.back().get();
//	//pBack->spaceEntityIdx(idx);
//	//entities_[idx] = pBack;
//	//pEntity->spaceEntityIdx(SPACE_ENTITIES::size_type(-1));
//	//entities_.pop_back();
//
//	//onLeaveWorld(pEntity);
//
//	//// ��������onLeaveWorld֮�� ��Ϊ����rangeTrigger��Ҫ�ο�pEntityCoordinateNode
//	//pEntity->uninstallCoordinateNodes(&coordinateSystem_);
//	//pEntity->onLeaveSpace(this);
//
//	//// ���û��entity������Ҫ����space, ��Ϊspace���ٴ���һ��entity
//	//if(entities_.empty() && state_ == STATE_NORMAL)
//	//{
//	//	Spaces::destroySpace(this->id(), 0);
//	//}
//}
//
////-------------------------------------------------------------------------------------
//void Space::_onEnterWorld(Entity* pEntity)
//{
//	/*
//	if (pEntity->hasWitness())
//	{
//		_addSpaceDatasToEntityClient(pEntity);
//		pEntity->pWitness()->onEnterSpace(this);
//	}
//	*/
//}
//
////-------------------------------------------------------------------------------------
//void Space::onEnterWorld(Entity* pEntity)
//{
//	KBE_ASSERT(pEntity != NULL);
//	
//	// �����һ����Witness(ͨ�������)����Ҫ����ǰ�����Ѿ���������client���ֵ�entity�㲥����
//	// ������һ����ͨ��entity�������磬 ��ô��Ҫ�����entity�㲥�����п���������Witness��entity��
//	/*if(pEntity->hasWitness())
//	{
//	_onEnterWorld(pEntity);
//	}*/
//}
//
////-------------------------------------------------------------------------------------
//void Space::onEntityAttachWitness(Entity* pEntity)
//{
//	/*KBE_ASSERT(pEntity != NULL && pEntity->hasWitness());
//	_onEnterWorld(pEntity);*/
//}
//
////-------------------------------------------------------------------------------------
//void Space::onLeaveWorld(Entity* pEntity)
//{
//	
//	// �������˿ͻ��˹㲥�Լ����뿪
//	// ��ͻ��˷���onLeaveWorld��Ϣ
//	
//}

////-------------------------------------------------------------------------------------
//Entity* Space::findEntity(ENTITY_ID entityID)
//{
//	/*
//	SPACE_ENTITIES::const_iterator iter = this->entities().begin();
//	for(; iter != this->entities().end(); ++iter)
//	{
//		const Entity* entity = (*iter).get();
//			
//		if(entity->id() == entityID)
//			return const_cast<Entity*>(entity);
//	}
//	*/
//	return NULL;
//}

//-------------------------------------------------------------------------------------
bool Space::destroy(ENTITY_ID entityID)
{
	
	return true;
}

//-------------------------------------------------------------------------------------
void Space::setGeometryPath(const std::string& path)
{ 
	return setSpaceData("_mapping", path); 
}

//-------------------------------------------------------------------------------------
const std::string& Space::getGeometryPath()
{ 
	return getSpaceData("_mapping"); 
}

//-------------------------------------------------------------------------------------
void Space::setSpaceData(const std::string& key, const std::string& value)
{
	SPACE_DATA::iterator iter = datas_.find(key);
	if(iter == datas_.end())
		datas_.insert(SPACE_DATA::value_type(key, value)); 
	else
		if(iter->second == value)
			return;
		else
			datas_[key] = value;

	//onSpaceDataChanged(key, value, false);
}

//-------------------------------------------------------------------------------------
bool Space::hasSpaceData(const std::string& key)
{
	SPACE_DATA::iterator iter = datas_.find(key);
	if(iter == datas_.end())
		return false;

	return true;
}

//-------------------------------------------------------------------------------------
const std::string& Space::getSpaceData(const std::string& key)
{
	SPACE_DATA::iterator iter = datas_.find(key);
	if(iter == datas_.end())
	{
		static const std::string null = "";
		return null;
	}

	return iter->second;
}

//-------------------------------------------------------------------------------------
void Space::delSpaceData(const std::string& key)
{
	SPACE_DATA::iterator iter = datas_.find(key);
	if(iter == datas_.end())
		return;

	datas_.erase(iter);

	//onSpaceDataChanged(key, "", true);
}


//-------------------------------------------------------------------------------------
}
