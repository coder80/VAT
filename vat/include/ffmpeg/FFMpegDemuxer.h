#pragma once

class FFMpegDemuxer {
public:
	FFMpegDemuxer();
	~FFMpegDemuxer() = default;

	FFMpegDemuxer(FFMpegDemuxer&&) = delete;
	FFMpegDemuxer(const FFMpegDemuxer&) = delete;
	FFMpegDemuxer& operator=(FFMpegDemuxer&&) = delete;
	FFMpegDemuxer& operator=(const FFMpegDemuxer&) = delete;
};
