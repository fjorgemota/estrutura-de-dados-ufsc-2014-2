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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Fila.o \
	${OBJECTDIR}/FilaEnc.o \
	${OBJECTDIR}/Lista.o \
	${OBJECTDIR}/ListaDupEnc.o \
	${OBJECTDIR}/ListaEnc.o \
	${OBJECTDIR}/Pilha.o \
	${OBJECTDIR}/PilhaEnc.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f2

${TESTDIR}/TestFiles/f2: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Fila.o: Fila.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fila.o Fila.cpp

${OBJECTDIR}/FilaEnc.o: FilaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FilaEnc.o FilaEnc.cpp

${OBJECTDIR}/Lista.o: Lista.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista.o Lista.cpp

${OBJECTDIR}/ListaDupEnc.o: ListaDupEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaDupEnc.o ListaDupEnc.cpp

${OBJECTDIR}/ListaEnc.o: ListaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaEnc.o ListaEnc.cpp

${OBJECTDIR}/Pilha.o: Pilha.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pilha.o Pilha.cpp

${OBJECTDIR}/PilhaEnc.o: PilhaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PilhaEnc.o PilhaEnc.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/FilaEncTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/FilaTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/ListaDupEncTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/ListaEncTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/ListaTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/PilhaEncTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/PilhaTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest -lpthread 


${TESTDIR}/tests/FilaEncTest.o: tests/FilaEncTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FilaEncTest.o tests/FilaEncTest.cpp


${TESTDIR}/tests/FilaTest.o: tests/FilaTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FilaTest.o tests/FilaTest.cpp


${TESTDIR}/tests/ListaDupEncTest.o: tests/ListaDupEncTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ListaDupEncTest.o tests/ListaDupEncTest.cpp


${TESTDIR}/tests/ListaEncTest.o: tests/ListaEncTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ListaEncTest.o tests/ListaEncTest.cpp


${TESTDIR}/tests/ListaTest.o: tests/ListaTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ListaTest.o tests/ListaTest.cpp


${TESTDIR}/tests/PilhaEncTest.o: tests/PilhaEncTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PilhaEncTest.o tests/PilhaEncTest.cpp


${TESTDIR}/tests/PilhaTest.o: tests/PilhaTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PilhaTest.o tests/PilhaTest.cpp


${OBJECTDIR}/Fila_nomain.o: ${OBJECTDIR}/Fila.o Fila.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Fila.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fila_nomain.o Fila.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Fila.o ${OBJECTDIR}/Fila_nomain.o;\
	fi

${OBJECTDIR}/FilaEnc_nomain.o: ${OBJECTDIR}/FilaEnc.o FilaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FilaEnc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FilaEnc_nomain.o FilaEnc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FilaEnc.o ${OBJECTDIR}/FilaEnc_nomain.o;\
	fi

${OBJECTDIR}/Lista_nomain.o: ${OBJECTDIR}/Lista.o Lista.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Lista.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista_nomain.o Lista.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Lista.o ${OBJECTDIR}/Lista_nomain.o;\
	fi

${OBJECTDIR}/ListaDupEnc_nomain.o: ${OBJECTDIR}/ListaDupEnc.o ListaDupEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ListaDupEnc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaDupEnc_nomain.o ListaDupEnc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ListaDupEnc.o ${OBJECTDIR}/ListaDupEnc_nomain.o;\
	fi

${OBJECTDIR}/ListaEnc_nomain.o: ${OBJECTDIR}/ListaEnc.o ListaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ListaEnc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaEnc_nomain.o ListaEnc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ListaEnc.o ${OBJECTDIR}/ListaEnc_nomain.o;\
	fi

${OBJECTDIR}/Pilha_nomain.o: ${OBJECTDIR}/Pilha.o Pilha.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Pilha.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pilha_nomain.o Pilha.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Pilha.o ${OBJECTDIR}/Pilha_nomain.o;\
	fi

${OBJECTDIR}/PilhaEnc_nomain.o: ${OBJECTDIR}/PilhaEnc.o PilhaEnc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PilhaEnc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PilhaEnc_nomain.o PilhaEnc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PilhaEnc.o ${OBJECTDIR}/PilhaEnc_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
