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

install(TARGETS ReplayChecker
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
