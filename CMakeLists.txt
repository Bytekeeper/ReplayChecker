find_path(OPENBW_DIR bwgame.h
  PATHS
  ENV OPENBW_DIR
)

include_directories(
  ${OPENBW_DIR}
)

add_executable(ReplayChecker
  ReplayChecker.cpp
)

add_executable(ReplayInfo
  ReplayInfo.cpp
)

install(TARGETS ReplayChecker
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
