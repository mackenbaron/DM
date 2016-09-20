#-------------------------------------------------------
# Copyright (c) DuiMagic
# All rights reserved.
# History:
# 		<Author>	<Time>		<Version>	  <Des>
#      guoyou		2015-2-28	1.0		
#-------------------------------------------------------
PROJECT(DMSpy) 

# �ļ����飨���ˣ���ͬʱ������뵽ADD_LIBRARY�в�����ʾ
FILE(GLOB ROOT_HEADER 		./inc/*.h)
FILE(GLOB ROOT_SOURCE 		./src/*.cpp;./src/*.c;./src/*.cur)
FILE(GLOB ROOT		 		./*.h;./*.rc;)

SOURCE_GROUP("inc" 		FILES 	${ROOT_HEADER})
SOURCE_GROUP("src"		FILES 	${ROOT_SOURCE})
SOURCE_GROUP("other"	FILES 	${ROOT})

# ����Ԥ����ͷ
use_precompiled_header(DMSpy
   "${CMAKE_CURRENT_SOURCE_DIR}/inc/DMSpyAfx.h"
   "${CMAKE_CURRENT_SOURCE_DIR}/src/DMSpyAfx.cpp"
  )
  
 # ����ͷ�ļ�����·��
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc;${CMAKE_CURRENT_SOURCE_DIR}/)

# ����DmMain��ͷ�ļ�
INCLUDE_DIRECTORIES(${DM_SOURCE_DIR}/DmMain/inc
					${DM_SOURCE_DIR}/DmMain/inc/Common;
					${DM_SOURCE_DIR}/DmMain/inc/Common/Template;
					${DM_SOURCE_DIR}/DmMain/inc/Core;
					${DM_SOURCE_DIR}/DmMain/inc/Core/Msg;
					${DM_SOURCE_DIR}/DmMain/inc/Core/Dui;
					${DM_SOURCE_DIR}/DmMain/inc/Core/Event;
					${DM_SOURCE_DIR}/DmMain/inc/IDmMain;
					${DM_SOURCE_DIR}/DmMain/inc/Modules;
					${DM_SOURCE_DIR}/DmMain/inc/Widgets;)
  
# �������
SET(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")# ֱ�ӳ�gui��Ĭ�ϣ�Ȼ�� �ĳ�mtd
SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /D NDEBUG")
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)  # unicode�汾
ADD_EXECUTABLE(DMSpy  WIN32 ${ROOT_HEADER};${ROOT_SOURCE};${ROOT})
#if(USE_DMDLL_)
#else
#	set(EXTRA_LIBS rich32.lib)# ����һ����ʽlib
#   target_link_libraries(DMSpy ${EXTRA_LIBS})
#endif()
SET_TARGET_PROPERTIES(DMSpy PROPERTIES OUTPUT_NAME "DMSpy")

# ������Ŀ������
add_dependencies(DMSpy  DmMain)

#�����¼�������
add_custom_command(TARGET DMSpy 
					PRE_BUILD 
					COMMAND call ${DM_SOURCE_DIR}/Tools/CMake/PreBuild.cmd $(TargetDir)
					COMMENT "This command will be executed before build target DMSpy"
					)
add_custom_command(TARGET DMSpy 
					POST_BUILD 
					COMMAND call ${DM_SOURCE_DIR}/Tools/CMake/PostBuild.cmd $(TargetDir)
					COMMENT "This command will be executed after build target DMSpy"
					)
SET_TARGET_PROPERTIES(DMSpy PROPERTIES FOLDER Samples)
 