cmake_minimum_required (VERSION 3.8)
set(ProjectName vst)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h)
find_library(AVCODEC_LIBRARY avcodec)

find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
find_library(AVFORMAT_LIBRARY avformat)

find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h)
find_library(AVUTIL_LIBRARY avutil)

find_path(AVDEVICE_INCLUDE_DIR libavdevice/avdevice.h)
find_library(AVDEVICE_LIBRARY avdevice)

message(AVCODEC_INCLUDE_DIR ${AVCODEC_INCLUDE_DIR})
message("CMAKE_PROJECT_DIR" ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/include/common/FfmpegCommon.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/common/common.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/common/types.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/ffmpeg/FFMpegDemuxer.h
	${CMAKE_CURRENT_SOURCE_DIR}/VideoAnalyse.h
)

set(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/VideoAnalyse.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ffmpeg/FFMpegDemuxer.cpp
)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library (${ProjectName}_lib ${HEADER_FILES} ${SRC_FILES})
target_include_directories(${ProjectName}_lib 
PUBLIC ${INCLUDE_DIR} 
PRIVATE ${AVCODEC_INCLUDE_DIR} ${AVFORMAT_INCLUDE_DIR}  
${AVUTIL_INCLUDE_DIR} ${AVDEVICE_INCLUDE_DIR} include
)

target_link_libraries(${ProjectName}_lib 
PRIVATE ${AVCODEC_LIBRARY} ${AVFORMAT_LIBRARY} ${AVUTIL_LIBRARY} ${AVDEVICE_LIBRARY}
)

add_executable(${ProjectName} VideoAnalyse.h VideoAnalyse.cpp)
target_link_libraries(${ProjectName} ${ProjectName}_lib)