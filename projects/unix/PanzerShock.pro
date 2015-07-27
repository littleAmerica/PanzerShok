TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

VPATH = ../../src

HEADERS +=  \
            Camera.h                    \
            Entity.h                    \
            EntityList.h                \
            EventListener.h             \
            Game.h                      \
            GameObjectLibrary.h         \
            Player.h                    \
            RenderEngine.h              \
            Screen.h                    \
            Singleton.h                 \
            States.h                    \
            Texture.h                   \
            Timer.h                     \
            ./Physics/Physics.h         \
            ./Physics/PhysEngine.h      \
            ./Physics/Physics_Rigid.h   \
            ./Utils/SDL_platform.h      \
            ./Utils/Box2D_platform.h    \
            ./Utils/Resources.h         \
            ./Utils/Types.h

SOURCES +=  main.cpp                \
            Camera.cpp              \
            Entity.cpp              \
            EntityList.cpp          \
            EventListener.cpp       \
            Game.cpp                \
            GameObjectLibrary.cpp   \
            Player.cpp              \
            RenderEngine.cpp        \
            Screen.cpp              \
            Texture.cpp             \
            Timer.cpp               \
            ./Physics/Physics_Rigid.cpp            \
            ./Physics/PhysEngine.cpp          \

LIBS += -lSDL2 -lSDL2_image -lBox2D

release:DESTDIR = ../../output/release
debug:DESTDIR = ../../output/debug
OBJECTS_DIR = $${DESTDIR}/.obj

QMAKE_CXXFLAGS += -std=c++0x

include(deployment.pri)
qtcAddDeployment()
