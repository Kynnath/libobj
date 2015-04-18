#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/OBJ/Face.o \
	${OBJECTDIR}/src/OBJ/Object.o \
	${OBJECTDIR}/src/OBJ/Vertex.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -std=c++14 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code
CXXFLAGS=-m64 -std=c++14 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a

${OBJECTDIR}/src/OBJ/Face.o: src/OBJ/Face.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/OBJ
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../../../lib/glew-1.12.0/include -I../libgltools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/OBJ/Face.o src/OBJ/Face.cpp

${OBJECTDIR}/src/OBJ/Object.o: src/OBJ/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/OBJ
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../../../lib/glew-1.12.0/include -I../libgltools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/OBJ/Object.o src/OBJ/Object.cpp

${OBJECTDIR}/src/OBJ/Vertex.o: src/OBJ/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/OBJ
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../../../lib/glew-1.12.0/include -I../libgltools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/OBJ/Vertex.o src/OBJ/Vertex.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibobj.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
