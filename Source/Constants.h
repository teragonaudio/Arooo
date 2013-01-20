/*
  ==============================================================================

    Constants
    Created: 19 Jan 2013 1:55:33pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __CONSTANTS_H_448F6882__
#define __CONSTANTS_H_448F6882__

// Use fixed FFT buffer sizes at compile time. Offers a large performance
// improvement, but slower compile times and so is disabled for now.
#define USE_FFT_FIXED_SIZE 1

// Instead of triggering MIDI notes, this will generate a file to /tmp
// with information about the incoming signal.
#define ANALYSIS_MODE 0

// Use the built-in Apple IAC Driver for MIDI output. Currently doesn't
// work for some weird reason.
#define USE_IAC_DRIVER 0

// How large of a buffer size we should request from the audio device. Note
// that this also determines the FFT buffer sizes algorithm, and hence must
// be given at compile time.
static const int kBufferSize = 1024;
// Required if using a fixed FFT size
static const int kBufferSizeBase2 = 10; // 2^10

static const float kSampleRate = 44100.0f;

// The minimum strength of the bucket value in order to trigger a hit
static const float kBucketMinimumStrength = 30.0f;

// TODO: Would be nice to use real frequencies instead of bucket indexes
// These must be recalibrated for different FFT buffer sizes
static const int kHowlBucketIndexes[] = { 13, 14, 15, 526, 527, 528 };
static const int kHowlBucketNumIndexes = 6;

// If all buckets contain at least this many hits, a howl has been found
static const int kHowlDetectionNumPointsNeeded = 15;

// Output note settings
static const int kOutputMidiChannel = 1;
static const int kOutputMidiNoteNumber = 64;
static const int kOutputMidiNoteVelocity = 127;
static const int kOutputMidiNoteDurationMs = 1000;

#endif  // __CONSTANTS_448F6882__
