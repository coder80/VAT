#pragma once

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
}

namespace ffmpeg {

	class FFInit {
	public:
		static void init() {
			static auto& ffinit = FFInit();
		}

	private:
		FFInit() {
			av_register_all();
		}
	};

}