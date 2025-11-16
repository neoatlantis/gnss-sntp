#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=m9n/i2c_reader.c m9n/ubx_parser.c w5500/new.c w5500/spi.c w5500/udp_socket.c main.c uart.c spi.c syslog.c i2c.c interrupts/interrupts.c rtcc/rtcc.c timer1/timer1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/m9n/i2c_reader.o ${OBJECTDIR}/m9n/ubx_parser.o ${OBJECTDIR}/w5500/new.o ${OBJECTDIR}/w5500/spi.o ${OBJECTDIR}/w5500/udp_socket.o ${OBJECTDIR}/main.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/syslog.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/interrupts/interrupts.o ${OBJECTDIR}/rtcc/rtcc.o ${OBJECTDIR}/timer1/timer1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/m9n/i2c_reader.o.d ${OBJECTDIR}/m9n/ubx_parser.o.d ${OBJECTDIR}/w5500/new.o.d ${OBJECTDIR}/w5500/spi.o.d ${OBJECTDIR}/w5500/udp_socket.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/spi.o.d ${OBJECTDIR}/syslog.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/interrupts/interrupts.o.d ${OBJECTDIR}/rtcc/rtcc.o.d ${OBJECTDIR}/timer1/timer1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/m9n/i2c_reader.o ${OBJECTDIR}/m9n/ubx_parser.o ${OBJECTDIR}/w5500/new.o ${OBJECTDIR}/w5500/spi.o ${OBJECTDIR}/w5500/udp_socket.o ${OBJECTDIR}/main.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/syslog.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/interrupts/interrupts.o ${OBJECTDIR}/rtcc/rtcc.o ${OBJECTDIR}/timer1/timer1.o

# Source Files
SOURCEFILES=m9n/i2c_reader.c m9n/ubx_parser.c w5500/new.c w5500/spi.c w5500/udp_socket.c main.c uart.c spi.c syslog.c i2c.c interrupts/interrupts.c rtcc/rtcc.c timer1/timer1.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/m9n/i2c_reader.o: m9n/i2c_reader.c  .generated_files/flags/default/b17abab991baa615ccf4d5819446f50fec9aa569 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/m9n" 
	@${RM} ${OBJECTDIR}/m9n/i2c_reader.o.d 
	@${RM} ${OBJECTDIR}/m9n/i2c_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/m9n/i2c_reader.o.d" -o ${OBJECTDIR}/m9n/i2c_reader.o m9n/i2c_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/m9n/ubx_parser.o: m9n/ubx_parser.c  .generated_files/flags/default/ac8858e5565c09d8cb9e4ab9abdf623281f5e0dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/m9n" 
	@${RM} ${OBJECTDIR}/m9n/ubx_parser.o.d 
	@${RM} ${OBJECTDIR}/m9n/ubx_parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/m9n/ubx_parser.o.d" -o ${OBJECTDIR}/m9n/ubx_parser.o m9n/ubx_parser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/new.o: w5500/new.c  .generated_files/flags/default/a3fdbdc584d105c4b8646a58fbe83b70d9b869f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/new.o.d 
	@${RM} ${OBJECTDIR}/w5500/new.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/new.o.d" -o ${OBJECTDIR}/w5500/new.o w5500/new.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/spi.o: w5500/spi.c  .generated_files/flags/default/f0f7d21b4c0257c841e503b734c360c814f55d53 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/spi.o.d 
	@${RM} ${OBJECTDIR}/w5500/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/spi.o.d" -o ${OBJECTDIR}/w5500/spi.o w5500/spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/udp_socket.o: w5500/udp_socket.c  .generated_files/flags/default/41198e2c437c3f748b9c14aaa6f660e620988634 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o.d 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/udp_socket.o.d" -o ${OBJECTDIR}/w5500/udp_socket.o w5500/udp_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/4b508fd9074cfc99c40597095a78108bfecb77a9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/3eee6cbf1c521e4354d8b5182d9dfe72f1b7f30f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/spi.o: spi.c  .generated_files/flags/default/30b6669c886f9f8f940643c26bcf019faa7c2ede .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/syslog.o: syslog.c  .generated_files/flags/default/151c047c2a2a1b8d4c7af96687b3657c750ac36b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/syslog.o.d 
	@${RM} ${OBJECTDIR}/syslog.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/syslog.o.d" -o ${OBJECTDIR}/syslog.o syslog.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/34236d659b13e1f118aa408dd98f6e47fb6c2406 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupts/interrupts.o: interrupts/interrupts.c  .generated_files/flags/default/da4af68f8d6b1587114b6eba51ba0e7eeb3d261f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupts" 
	@${RM} ${OBJECTDIR}/interrupts/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupts/interrupts.o.d" -o ${OBJECTDIR}/interrupts/interrupts.o interrupts/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/rtcc/rtcc.o: rtcc/rtcc.c  .generated_files/flags/default/cbccd5604317499f6ad0b1839ccb7ae550d800cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/rtcc" 
	@${RM} ${OBJECTDIR}/rtcc/rtcc.o.d 
	@${RM} ${OBJECTDIR}/rtcc/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rtcc/rtcc.o.d" -o ${OBJECTDIR}/rtcc/rtcc.o rtcc/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timer1/timer1.o: timer1/timer1.c  .generated_files/flags/default/bdb4586688e90eb233f253c048cabdd73a2561d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/timer1" 
	@${RM} ${OBJECTDIR}/timer1/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/timer1/timer1.o.d" -o ${OBJECTDIR}/timer1/timer1.o timer1/timer1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/m9n/i2c_reader.o: m9n/i2c_reader.c  .generated_files/flags/default/f763739581b83a4ffa946cd000b7866d2ca7550 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/m9n" 
	@${RM} ${OBJECTDIR}/m9n/i2c_reader.o.d 
	@${RM} ${OBJECTDIR}/m9n/i2c_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/m9n/i2c_reader.o.d" -o ${OBJECTDIR}/m9n/i2c_reader.o m9n/i2c_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/m9n/ubx_parser.o: m9n/ubx_parser.c  .generated_files/flags/default/bb7960a9cafe9f26af8b82eae6dc588a2733669d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/m9n" 
	@${RM} ${OBJECTDIR}/m9n/ubx_parser.o.d 
	@${RM} ${OBJECTDIR}/m9n/ubx_parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/m9n/ubx_parser.o.d" -o ${OBJECTDIR}/m9n/ubx_parser.o m9n/ubx_parser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/new.o: w5500/new.c  .generated_files/flags/default/94bd9b539e000daae705d7db7d9d19d44d36769d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/new.o.d 
	@${RM} ${OBJECTDIR}/w5500/new.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/new.o.d" -o ${OBJECTDIR}/w5500/new.o w5500/new.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/spi.o: w5500/spi.c  .generated_files/flags/default/42d8e42d7e98d32d9519852b82cdcda2f92dcc5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/spi.o.d 
	@${RM} ${OBJECTDIR}/w5500/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/spi.o.d" -o ${OBJECTDIR}/w5500/spi.o w5500/spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/udp_socket.o: w5500/udp_socket.c  .generated_files/flags/default/f420f0a292fa0350b7f65893657dcdf86896681b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o.d 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/udp_socket.o.d" -o ${OBJECTDIR}/w5500/udp_socket.o w5500/udp_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/49d3ad85dadf3e969907e0bc7e608dddd69d8ec5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/c6ab42a18ea5d3e66e7994835830e279f2c8c98d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/spi.o: spi.c  .generated_files/flags/default/6a695f070458d7bf540c89f4f9e5871a6dc0776f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/syslog.o: syslog.c  .generated_files/flags/default/844447ca4a2d3be49e5717e018c4dafc8499866 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/syslog.o.d 
	@${RM} ${OBJECTDIR}/syslog.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/syslog.o.d" -o ${OBJECTDIR}/syslog.o syslog.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/609a18dc49e936a972ded24e441d5f6867568cac .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupts/interrupts.o: interrupts/interrupts.c  .generated_files/flags/default/5e4aaf55fa8ccb8ade9c6b675382993f1ffe0cf1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupts" 
	@${RM} ${OBJECTDIR}/interrupts/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupts/interrupts.o.d" -o ${OBJECTDIR}/interrupts/interrupts.o interrupts/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/rtcc/rtcc.o: rtcc/rtcc.c  .generated_files/flags/default/3669d874b97be16facfe513ff790ec6780be9ff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/rtcc" 
	@${RM} ${OBJECTDIR}/rtcc/rtcc.o.d 
	@${RM} ${OBJECTDIR}/rtcc/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rtcc/rtcc.o.d" -o ${OBJECTDIR}/rtcc/rtcc.o rtcc/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timer1/timer1.o: timer1/timer1.c  .generated_files/flags/default/10e151a4e41906a000decb0b5e82cc4948053290 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/timer1" 
	@${RM} ${OBJECTDIR}/timer1/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/timer1/timer1.o.d" -o ${OBJECTDIR}/timer1/timer1.o timer1/timer1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/0007-gnss-mk2.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
