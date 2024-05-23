# Install script for directory: /home/lokesh/psc-ns3-psc-6.0/src/psc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lokesh/psc-ns3-psc-6.0/build/lib/libns3-dev-psc-debug.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so"
         OLD_RPATH "/home/lokesh/psc-ns3-psc-6.0/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-psc-debug.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ns3" TYPE FILE FILES
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/ims-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/intel-http-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-call-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-msg-stats.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-server-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-state-machine-stats.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/mcptt-trace-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/psc-application-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/psc-scenario-trace-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/uav-mobility-energy-model-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/helper/udp-group-echo-helper.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/intel-http-client.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/intel-http-header.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/intel-http-server.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-grp-basic.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-grp-basic-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-grp-broadcast.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-grp-broadcast-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-private.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-machine-private-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-msg.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-msg-field.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-type-machine.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-type-machine-grp-basic.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-type-machine-private.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-call-type-machine-private-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-channel.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-counter.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-emerg-alert-machine.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-emerg-alert-machine-basic.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-entity-id.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-floor-msg.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-floor-msg-field.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-floor-msg-sink.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-floor-participant.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-floor-queue.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-media-msg.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-media-sink.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-media-src.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-msg.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-off-network-floor-participant.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-off-network-floor-participant-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-call-machine-client.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-call-machine-client-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-arbitrator.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-arbitrator-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-dual-control.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-dual-control-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-participant.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-participant-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-towards-participant.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-on-network-floor-towards-participant-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-ptt-app.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher-orchestrator.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher-orchestrator-contention.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher-orchestrator-interface.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher-orchestrator-session-cdf.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-pusher-orchestrator-spurt-cdf.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-queued-user-info.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-rtp-header.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-sdp-fmtp-header.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-server-app.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-server-call.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-server-call-machine.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-server-call-machine-group-prearranged.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-server-call-machine-group-prearranged-state.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/mcptt-timer.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-application.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-application-client.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-application-configuration.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-application-server.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-scenario-definition.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-video-streaming.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/psc-video-streaming-distributions.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/uav-mobility-energy-model.h"
    "/home/lokesh/psc-ns3-psc-6.0/src/psc/model/udp-group-echo-server.h"
    "/home/lokesh/psc-ns3-psc-6.0/build/include/ns3/psc-module.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lokesh/psc-ns3-psc-6.0/build/src/psc/examples/cmake_install.cmake")

endif()

