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

#ifndef KBE_MGR_SPACES_H
#define KBE_MGR_SPACES_H

// common include
#include "helper/debug_helper.hpp"
#include "common/common.hpp"


namespace KBEngine{

class Space;

class Spaces
{
public:
	Spaces();
	~Spaces();

private:
	std::map<SPACE_ID, Space*> spaces_;
};

}
#endif
